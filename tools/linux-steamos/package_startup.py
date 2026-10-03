#!/usr/bin/env python3
"""Package a native startup build inside the pinned Steamrt4 runner."""
import argparse
from datetime import datetime, timezone
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import subprocess
import tarfile


def sha256(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def inside(path, root):
    return path == root or root in path.parents


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--harmony', required=True, type=Path)
    parser.add_argument('--sdk', required=True, type=Path)
    parser.add_argument('--output', required=True, type=Path)
    parser.add_argument('--build-id', required=True)
    args = parser.parse_args()
    if not re.fullmatch(r'[A-Za-z0-9][A-Za-z0-9._-]{0,79}', args.build_id):
        parser.error('build-id must be a simple directory name')
    build = Path(os.environ['HARMONY_BUILD_ROOT']).resolve()
    harmony, sdk, output = [p.resolve() for p in (args.harmony, args.sdk, args.output)]
    if not inside(output, build) or output.exists():
        parser.error('output must be a new directory inside the writable build root')
    if not inside(harmony, build) or not inside(sdk, build):
        parser.error('artifact directories must belong to this isolated build')
    version = subprocess.check_output(['clang-19', '--version'], text=True)
    if '19.1.7' not in version or '2.41' not in subprocess.check_output(['getconf', 'GNU_LIBC_VERSION'], text=True):
        parser.error('packaging requires the pinned Steamrt4 environment')
    candidates = [p for p in harmony.rglob('harmonyrecomp') if p.is_file()]
    if len(candidates) != 1:
        parser.error('expected exactly one native Harmony executable')
    executable = candidates[0]
    native = [executable, *sorted(executable.parent.glob('*.so'))]
    if len(list(executable.parent.glob('libharmonyrecomp_*.so'))) != 116:
        parser.error('expected all 116 native Harmony module libraries')
    if not any(p.name.startswith('librexgpu-xenos') for p in native):
        parser.error('Xenos platform plugin is missing from the executable directory')
    helpers = [p for p in sdk.rglob('linux_startup_test') if p.is_file()]
    if len(helpers) != 1:
        parser.error('expected one Linux startup contract test')
    # The helper must use the SAME packaged runtime ABI as Harmony. Its physical
    # execution is part of acceptance, rather than assuming equivalence from a name.
    native.append(helpers[0])
    binaries = {p.name: p.resolve() for p in native}
    dependencies = {}
    for original in native:
        result = subprocess.run(['ldd', str(original)], text=True, capture_output=True)
        if result.returncode or 'not found' in result.stdout:
            raise RuntimeError('ELF dependency resolution failed: ' + str(original) + '\n' + result.stdout + result.stderr)
        for line in result.stdout.splitlines():
            match = re.search(r'=>\s+(/\S+)\s+\(', line) or re.match(r'\s*(/\S+)\s+\(', line)
            if not match:
                continue
            linked = Path(match[1]); resolved = linked.resolve()
            if resolved.name in binaries:
                continue
            if inside(resolved, build):
                prior = binaries.get(linked.name)
                if prior and sha256(prior) != sha256(resolved):
                    raise RuntimeError('conflicting application library: ' + linked.name)
                binaries[linked.name] = resolved
                continue
            if not any(inside(resolved, Path(p)) for p in ['/usr/lib', '/lib', '/lib64']):
                raise RuntimeError('dependency is outside pinned userspace: ' + str(resolved))
            dependencies[linked.name] = resolved
    loader_name = 'ld-linux-x86-64.so.2'
    if loader_name not in dependencies:
        raise RuntimeError('pinned ELF interpreter was not found')
    binaries[loader_name] = dependencies.pop(loader_name)
    manifest = {'schema': 1, 'build_id': args.build_id, 'created_utc': datetime.now(timezone.utc).isoformat(),
                'architecture': 'linux/x86-64', 'scope': 'L1 asset-free native Harmony startup',
                'runtime': 'Steamrt4 4.0.20260805.254769', 'compiler': 'Clang 19.1.7',
                'carrier_image_id': 'sha256:bf8527eb54c3680e728d5b4b383a8ba730d72dae7236fbc8dff97ed6b224a731',
                'source': {}, 'files': {}}
    for label, variable in [('Harmony', 'HARMONY_SOURCE'), ('SDK', 'HARMONY_SDK')]:
        source = Path(os.environ[variable])
        status = subprocess.check_output(['git', '-C', str(source), 'status', '--porcelain'], text=True)
        if status:
            raise RuntimeError('source must be committed/clean before packaging: ' + label)
        manifest['source'][label] = subprocess.check_output(['git', '-C', str(source), 'rev-parse', 'HEAD'], text=True).strip()
    manifest['dependency_pins'] = subprocess.check_output(['git', '-C', os.environ['HARMONY_SDK'], 'submodule', 'status', '--recursive'], text=True).splitlines()
    output.mkdir()
    (output / 'bin').mkdir(); (output / 'lib').mkdir()
    for folder, files in [('bin', binaries), ('lib', dependencies)]:
        for name, source in sorted(files.items()):
            with source.open('rb') as stream:
                magic = stream.read(4)
            if '/' in name or magic != b'\x7fELF':
                raise RuntimeError('only regular ELF artifacts may be packaged: ' + name)
            dest = output / folder / name
            shutil.copyfile(source, dest)
            dest.chmod(0o755)
            manifest['files'][folder + '/' + name] = {'sha256': sha256(dest), 'mode': 0o755, 'bytes': dest.stat().st_size}
    (output / 'manifest.json').write_text(json.dumps(manifest, indent=2) + '\n')
    archive = output.with_suffix('.tar.gz')
    if archive.exists():
        raise RuntimeError('archive destination already exists')
    with tarfile.open(archive, 'w:gz') as tar:
        for path in sorted(output.rglob('*')):
            if path.is_file():
                tar.add(path, arcname=path.relative_to(output).as_posix(), recursive=False)
    print(json.dumps({'archive': str(archive), 'sha256': sha256(archive), 'bytes': archive.stat().st_size,
                      'files': len(manifest['files']), 'build_id': args.build_id}, indent=2))


if __name__ == '__main__':
    main()
