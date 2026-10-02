"""Characterize the unfixed gameplay boundaries without rebuilding the runtime.

These checks intentionally demonstrate current defects. Passing is NOT gameplay
or security acceptance. See HARMONY_RECOMP_CONTEXT.md for the proposed design.
"""
from __future__ import annotations
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import shlex
import subprocess
import sys
import tempfile


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest().upper()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    root = Path(__file__).resolve().parents[2]
    parser.add_argument('--build', type=Path,
        default=root / 'out/build/win-amd64-headless-regression-native')
    parser.add_argument('--output', type=Path)
    args = parser.parse_args()
    output = args.output or Path(tempfile.mkdtemp(prefix='harmony-gameplay-audit-'))
    output = output.resolve()
    args.build = args.build.resolve()
    output.mkdir(parents=True, exist_ok=True)
    ninja = (args.build / 'build.ninja').read_text()
    compile_block = re.search(
        r'build [^\n]*system/session_admission_test.cpp.obj:.*?\n(?=\n)', ninja, re.S).group(0)
    link_block = next(b for b in ninja.split('\n\n')
        if 'unit_tests.exe' in b and 'CXX_EXECUTABLE_LINKER' in b)
    def variable(block, key):
        return re.search(r'^  ' + key + r' = (.*)$', block, re.M).group(1).replace('$:', ':').replace('$ ', ' ')
    cache = (args.build / 'CMakeCache.txt').read_text()
    compiler = re.search(r'^CMAKE_CXX_COMPILER:FILEPATH=(.*)$', cache, re.M).group(1)
    runtime = root / 'out/reconcile-sdk/out/win-amd64/rexruntimerd.dll'
    source_paths = [root / 'tools/master_server/server.py',
        root / 'thirdparty/patches/rexglue-harmony-online-directory.patch', runtime]
    before = {str(p.relative_to(root)): sha(p) for p in source_paths}
    command = [compiler]
    for key in ('DEFINES', 'FLAGS', 'INCLUDES'):
        command += shlex.split(variable(compile_block, key))
    command += [str(Path(__file__).with_name('native_audit.cpp'))]
    command += shlex.split(variable(link_block, 'LINK_LIBRARIES').replace('\\', '/'))
    executable = output / 'native_audit.exe'
    command += ['-o', str(executable)]
    (output / 'compile-command.json').write_text(json.dumps(command, indent=2))
    env = dict(os.environ)
    env['PATH'] = str(runtime.parent) + os.pathsep + env.get('PATH', '')
    env['PYTHONPATH'] = str(root)
    results = {}
    jobs = [('compile', command, args.build),
        ('native-audit', [str(executable), '[gameplay-audit]', '--reporter', 'compact'], root),
        ('server-audit', [sys.executable, '-B', str(Path(__file__).with_name('server_audit.py'))], root)]
    for name, command, cwd in jobs:
        if name == 'native-audit' and results.get('compile') != 0:
            continue
        result = subprocess.run(command, cwd=cwd, env=env, text=True,
            stdout=subprocess.PIPE, stderr=subprocess.STDOUT, timeout=120)
        (output / (name + '.log')).write_text(result.stdout)
        results[name] = result.returncode
        print(name + ': exit=' + str(result.returncode))
        if name != 'compile':
            print(result.stdout)
    after = {str(p.relative_to(root)): sha(p) for p in source_paths}
    report = dict(results=results, hashes_before=before, hashes_after=after,
        protected_files_unchanged=before == after,
        meaning='Characterization of defects, not acceptance of a fix')
    (output / 'result.json').write_text(json.dumps(report, indent=2) + '\n')
    print('Evidence: ' + str(output))
    return int(before != after or any(results.values()))

if __name__ == '__main__':
    raise SystemExit(main())
