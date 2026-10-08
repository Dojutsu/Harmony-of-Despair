import contextlib
import importlib.util
import io
import os
from pathlib import Path
import stat
import tempfile
import unittest
from unittest import mock
import time
import struct

spec = importlib.util.spec_from_file_location("invitation", Path(__file__).with_name("private_lan_invitation.py"))
invitation = importlib.util.module_from_spec(spec)
spec.loader.exec_module(invitation)

class Invitations(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory(prefix="fsc-private-invitation-test-")
        self.root = Path(self.temporary.name)
    def tearDown(self):
        self.temporary.cleanup()
    def test_distinct_private_bounded_grants(self):
        output = self.root / "invites"
        with contextlib.redirect_stdout(io.StringIO()) as log:
            paths = invitation.generate(output, 1, [2, 3, 4, 5, 6], 3600)
        self.assertEqual(log.getvalue(), "")
        self.assertEqual(stat.S_IMODE(output.stat().st_mode), 0o700)
        self.assertEqual(len(paths), 6)
        host = paths[0].read_bytes()
        self.assertEqual(len(host), 304)
        self.assertEqual(host[:8], b"HPLI\x01\x00\x05\x00")
        secrets = set()
        for index, path in enumerate(paths[1:]):
            data = path.read_bytes()
            self.assertEqual(len(data), 80)
            self.assertEqual(data[:8], b"HPLI\x01\x01\x01\x00")
            self.assertEqual(data[8:24], host[8:24])
            self.assertEqual(data[24:], host[24 + 56 * index:80 + 56 * index])
            self.assertEqual(stat.S_IMODE(path.stat().st_mode), 0o600)
            self.assertEqual(path.stat().st_uid, os.geteuid())
            self.assertEqual(path.stat().st_nlink, 1)
            secrets.add(data[48:80])
        self.assertEqual(len(secrets), 5)
    def test_previous_invitation_not_overwritten(self):
        output = self.root / "invites"
        paths = invitation.generate(output, 1, [2], 3600)
        before = {path: path.read_bytes() for path in paths}
        with self.assertRaises(FileExistsError):
            invitation.generate(output, 1, [2], 3600)
        self.assertEqual(before, {path: path.read_bytes() for path in paths})
    def test_fresh_secrets_per_invitation(self):
        first = invitation.generate(self.root / "first", 1, [2], 3600)
        second = invitation.generate(self.root / "second", 1, [2], 3600)
        self.assertNotEqual(first[1].read_bytes()[32:], second[1].read_bytes()[32:])
    def test_invalid_boundaries_create_nothing(self):
        for host, clients, expiry in [(0,[2],1),(1,[],1),(1,[1],1),(1,[2,2],1),
                                     (1,[2,3,4,5,6,7],1),(1,[2],0),(1,[2],604801)]:
            with self.subTest(host=host, clients=clients, expiry=expiry):
                with self.assertRaises(ValueError):
                    invitation.generate(self.root / "bad", host, clients, expiry)
                self.assertFalse((self.root / "bad").exists())
    def test_symlink_ancestor_refused(self):
        (self.root / "real").mkdir()
        (self.root / "alias").symlink_to(self.root / "real", target_is_directory=True)
        with self.assertRaises(OSError):
            invitation.generate(self.root / "alias" / "invites", 1, [2], 3600)
        self.assertFalse((self.root / "real" / "invites").exists())
    def test_noncanonical_components_refused(self):
        with self.assertRaises(ValueError):
            invitation.generate(self.root / ".." / self.root.name / "invites", 1, [2], 3600)
        self.assertFalse((self.root / "invites").exists())

    def test_import_matching_private_client_without_exposing_keys(self):
        paths = invitation.generate(self.root / "sender", 1, [2, 3], 3600)
        with contextlib.redirect_stdout(io.StringIO()) as log:
            installed = invitation.import_invitation(paths[1], self.root / "receiver", 2)
        self.assertEqual(log.getvalue(), "")
        self.assertEqual(installed.read_bytes(), paths[1].read_bytes())
        self.assertEqual(stat.S_IMODE(installed.stat().st_mode), 0o600)
        self.assertEqual(stat.S_IMODE(installed.parent.stat().st_mode), 0o700)
        self.assertEqual(installed.stat().st_nlink, 1)
        self.assertEqual(invitation.inspect_invitation(installed, 2)["role"], "client")
        host = invitation.import_invitation(paths[0], self.root / "host-copy", 1)
        self.assertEqual(invitation.inspect_invitation(host, 1)["clients"], 2)

    def test_import_requires_authorized_profile_before_creating_output(self):
        paths = invitation.generate(self.root / "sender", 1, [2], 3600)
        for path, expected in [(paths[1],1),(paths[1],3),(paths[0],2),(paths[1],0)]:
            with self.subTest(expected=expected):
                with self.assertRaises(ValueError):
                    invitation.import_invitation(path, self.root / "receiver", expected)
                self.assertFalse((self.root / "receiver").exists())

    def test_import_rejects_symlinks_hardlinks_and_public_modes(self):
        paths = invitation.generate(self.root / "sender", 1, [2], 3600)
        source = paths[1]
        alias = source.parent / "alias"
        alias.symlink_to(source)
        with self.assertRaises(OSError):
            invitation.import_invitation(alias, self.root / "receiver", 2)
        alias.unlink()
        os.link(source, alias)
        with self.assertRaises(ValueError):
            invitation.import_invitation(source, self.root / "receiver", 2)
        alias.unlink()
        for mode in (0o644,0o400,0o700,0o660):
            source.chmod(mode)
            with self.assertRaises(ValueError):
                invitation.import_invitation(source, self.root / "receiver", 2)
        source.chmod(0o600)
        source.parent.chmod(0o755)
        with self.assertRaises(ValueError):
            invitation.import_invitation(source, self.root / "receiver", 2)
        self.assertFalse((self.root / "receiver").exists())

    def test_import_rejects_bounded_malformed_contents(self):
        paths = invitation.generate(self.root / "sender", 1, [2,3], 3600)
        original = paths[0].read_bytes()
        variants = [original+b"x", original[:79], b"x"*305]
        for position, value in [(0,ord('X')),(4,2),(5,2),(6,0),(7,1)]:
            damaged = bytearray(original);damaged[position]=value;variants.append(damaged)
        for expiry in (0,int(time.time())-1,int(time.time())+604810):
            damaged=bytearray(original);struct.pack_into('>Q',damaged,16,expiry);variants.append(damaged)
        for start,stop in [(8,16),(24,32),(32,48),(48,80)]:
            damaged=bytearray(original);damaged[start:stop]=bytes(stop-start);variants.append(damaged)
        for start,stop in [(80,88),(88,104),(104,136)]:
            damaged=bytearray(original);damaged[start:stop]=original[start-56:stop-56];variants.append(damaged)
        for data in variants:
            paths[0].write_bytes(data)
            with self.assertRaises(ValueError):
                invitation.import_invitation(paths[0], self.root / "receiver", 1)
            self.assertFalse((self.root / "receiver").exists())

    def test_import_preserves_existing_output(self):
        paths=invitation.generate(self.root / "sender",1,[2],3600)
        installed=invitation.import_invitation(paths[1],self.root / "receiver",2)
        before=installed.read_bytes()
        with self.assertRaises(FileExistsError):
            invitation.import_invitation(paths[1],self.root / "receiver",2)
        self.assertEqual(installed.read_bytes(),before)

    def test_import_rolls_back_only_created_files_on_io_failure(self):
        paths=invitation.generate(self.root / "sender",1,[2],3600)
        with mock.patch.object(invitation.os,'write',side_effect=OSError('fixture write failure')):
            with self.assertRaises(OSError):
                invitation.import_invitation(paths[1],self.root / "receiver",2)
        self.assertFalse((self.root / "receiver").exists())
        self.assertTrue(paths[1].exists())

    def test_import_detects_source_changes_while_reading(self):
        paths=invitation.generate(self.root / "sender",1,[2],3600)
        original_read=invitation.os.read
        changed=False
        def changing_read(descriptor,size):
            nonlocal changed
            result=original_read(descriptor,size)
            if result and not changed:
                changed=True
                with paths[1].open('ab') as output:output.write(b'x')
            return result
        with mock.patch.object(invitation.os,'read',side_effect=changing_read):
            with self.assertRaises(ValueError):
                invitation.import_invitation(paths[1],self.root / "receiver",2)
        self.assertFalse((self.root / "receiver").exists())

    def test_literal_dot_or_relative_paths_are_refused(self):
        for path in ['relative',str(self.root)+'/./receiver',str(self.root)+'//receiver',str(self.root)+'/../receiver']:
            with self.assertRaises(ValueError):
                invitation.generate(path,1,[2],3600)


if __name__ == "__main__":
    unittest.main()
