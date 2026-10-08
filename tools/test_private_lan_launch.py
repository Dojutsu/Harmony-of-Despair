import contextlib
import io
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
from unittest import mock
from private_lan_invitation import generate
from private_lan_launch import build_command, private_ipv4


class ProtectedLaunch(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory(prefix='fsc-private-launch-test-')
        self.root = Path(self.temporary.name)
        self.host, self.client = generate(self.root/'invites', 1, [2], 3600)
        self.game = Path('/bin/true')

    def tearDown(self):
        self.temporary.cleanup()

    def command(self, **values):
        options = dict(game=self.game, mode='client', invitation=str(self.client), local_xuid=2,
                       bind_ip='192.168.1.12', host_ip='192.168.1.11', name='Private',
                       discovery_port=30741, gameplay_port=30742, extra=['--renderer=vulkan'])
        options.update(values)
        return build_command(**options)

    def test_launch_uses_decimal_profile_and_only_private_file_path(self):
        with contextlib.redirect_stdout(io.StringIO()) as output:
            command = self.command()
        self.assertEqual(output.getvalue(), '')
        self.assertIn('--user_xuid=2', command)
        self.assertIn(f'--private_lan_invitation_file={self.client}', command)
        self.assertIn('--lan_online=true', command)
        self.assertIn('--direct_connect_address=192.168.1.11', command)
        self.assertIn('--private_lan_allow_legacy_diagnostics=false', command)
        self.assertIn('--session_directory_url=', command)
        self.assertIn('--nat_probe_credential=', command)
        self.assertIn('--renderer=vulkan', command)

    def test_offline_does_not_consume_invitation(self):
        with mock.patch('private_lan_launch.inspect_invitation', side_effect=AssertionError('Offline must not load a grant')):
            command = self.command(mode='offline', invitation=None, local_xuid=None, bind_ip=None, host_ip=None)
        self.assertIn('--lan_online=false', command)
        self.assertIn('--private_lan_invitation_file=', command)
        self.assertIn('--direct_connect_address=', command)
        self.assertNotIn('--lan_gameplay_port=30742', command)

    def test_expected_identity_and_role_required(self):
        for values in [dict(local_xuid=3),dict(mode='host'),dict(invitation=str(self.root/'missing')),
                       dict(local_xuid=None),dict(invitation=None),dict(host_ip=None),dict(bind_ip=None)]:
            with self.subTest(values=values):
                with self.assertRaises((ValueError,OSError)):
                    self.command(**values)
        host = self.command(mode='host', invitation=str(self.host),local_xuid=1,host_ip=None)
        self.assertIn('--direct_connect_address=',host)

    def test_public_endpoint_and_raw_override_refused(self):
        for value in ['8.8.8.8','100.64.0.1','0.0.0.0','224.0.0.1','host.local','::1']:
            with self.assertRaises(ValueError):self.command(host_ip=value)
        for option in ['--private_lan_allow_legacy_diagnostics=true','--session_directory_url=https://example.invalid',
                       '--nat_probe_credential=fixture','--lan_online=false','--direct_connect_address=8.8.8.8',
                       '--user_xuid=3','--user_name=other']:
            with self.assertRaises(ValueError):self.command(extra=[option])
        for value in ['127.0.0.1','10.0.0.1','172.16.0.1','172.31.255.254','192.168.0.1']:
            self.assertEqual(private_ipv4(value),value)

    def test_invalid_ports_names_and_executable_refused(self):
        for values in [dict(discovery_port=0),dict(gameplay_port=65536),dict(gameplay_port=30741),
                       dict(name=''),dict(name='x'*16),dict(name='bad\nname'),dict(game=self.root)]:
            with self.subTest(values=values):
                with self.assertRaises(ValueError):self.command(**values)

    def test_check_cli_prints_no_secret_and_does_not_execute_game(self):
        command = [sys.executable,'-B',str(Path(__file__).with_name('private_lan_launch.py')),
                   '--game',str(self.game),'--mode','client','--invitation',str(self.client),
                   '--xuid','2','--bind-ip','127.0.0.2','--host-ip','127.0.0.1','--check']
        result = subprocess.run(command, capture_output=True,text=True,check=True)
        self.assertEqual(result.stdout,'Launch configuration validated; title/hardware execution was not performed.\n')
        self.assertEqual(result.stderr,'')
        self.assertNotIn(self.client.read_bytes()[48:].hex(),result.stdout)


if __name__ == '__main__':
    unittest.main()
