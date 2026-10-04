import importlib.util
from pathlib import Path
import tempfile
import unittest
import json
import sys
from unittest.mock import patch

import steam_title as m

class SteamIdentityTests(unittest.TestCase):
 def test_registered_reaper_is_accepted(self):
  with tempfile.TemporaryDirectory() as t:
   root=Path(t);exe=root/'reaper';exe.touch();p=root/'12';p.mkdir()
   (p/'stat').write_text('12 (reaper) S 1 12 12')
   (p/'comm').write_text('reaper\n');(p/'cmdline').write_bytes(b'reaper\0SteamLaunch\0AppId=123\0--\0')
   (p/'exe').symlink_to(exe)
   self.assertEqual(m.steam_identity({'appid':123,'reaper':str(exe)},root,12)['appid'],123)
 def test_wrong_app_identity_is_rejected(self):
  with tempfile.TemporaryDirectory() as t:
   root=Path(t);p=root/'12';p.mkdir();(p/'stat').write_text('12 (reaper) S 1 12 12');(p/'comm').write_text('reaper');(p/'cmdline').write_bytes(b'reaper\0SteamLaunch\0AppId=456\0')
   with self.assertRaisesRegex(ValueError,'registered Steam'):m.steam_identity({'appid':123,'reaper':'/expected'},root,12)
 def test_wrong_reaper_binary_is_rejected(self):
  with tempfile.TemporaryDirectory() as t:
   root=Path(t);p=root/'12';p.mkdir();(p/'stat').write_text('12 (reaper) S 1 12 12');(p/'comm').write_text('reaper');(p/'cmdline').write_bytes(b'reaper\0SteamLaunch\0AppId=123\0');(p/'exe').symlink_to(root/'wrong')
   with self.assertRaisesRegex(ValueError,'unexpected Steam'):m.steam_identity({'appid':123,'reaper':str(root/'expected')},root,12)
 def test_plain_ssh_parent_is_rejected(self):
  with tempfile.TemporaryDirectory() as t:
   root=Path(t);p=root/'12';p.mkdir();(p/'stat').write_text('12 (python) S 1 12 12');(p/'comm').write_text('python3')
   with self.assertRaisesRegex(ValueError,'registered Steam'):m.steam_identity({'appid':123,'reaper':'/expected'},root,12)

class SteamLaunchTests(unittest.TestCase):
 def test_existing_steam_display_is_validated_and_used(self):
  with tempfile.TemporaryDirectory() as t:
   root=Path(t);(root/'bin').mkdir();(root/'logs').mkdir()
   (root/'bin/steam-entry.json').write_text(json.dumps({'appid':123,'reaper':'/reaper'}));(root/'bin/steam-entry.json').chmod(0o600)
   session={'environment':{'XDG_RUNTIME_DIR':'/run/user/1000','DISPLAY':':0'}}
   def run(ns):
    selected=m.h.discover_session('gaming')
    self.assertEqual(selected['environment']['DISPLAY'],':1')
    self.assertEqual(ns.video_driver,'x11');self.assertEqual(ns.arg,['--graphics-probe','{run}/runtime.log'])
    p=root/'logs'/ns.run_id;p.mkdir();(p/'receipt.json').write_text(json.dumps({'stage':'complete','exit_code':0}))
   with patch.object(sys,'argv',['steam-title','--root',str(root),'--build-id','build','--data-root',str(root),'--profile-root',str(root),'--video-driver','x11','--graphics-probe']), patch.object(m,'steam_identity',return_value={'appid':123}), patch.object(m.h,'discover_session',return_value=session), patch.object(m.h,'validate_environment',autospec=True,side_effect=lambda env,uid:env), patch.object(m.h,'remote_run',side_effect=run), patch.dict(m.os.environ,{'XDG_RUNTIME_DIR':'/run/user/1000','DISPLAY':':1'},clear=True):
    self.assertEqual(m.main(),0)
 def test_foreign_runtime_is_rejected_before_launch(self):
  with tempfile.TemporaryDirectory() as t:
   root=Path(t);(root/'bin').mkdir();(root/'bin/steam-entry.json').write_text(json.dumps({'appid':123,'reaper':'/reaper'}));(root/'bin/steam-entry.json').chmod(0o600)
   def run(ns):m.h.discover_session('gaming')
   with patch.object(sys,'argv',['steam-title','--root',str(root),'--build-id','build','--data-root',str(root),'--profile-root',str(root)]), patch.object(m,'steam_identity',return_value={'appid':123}), patch.object(m.h,'discover_session',return_value={'environment':{'XDG_RUNTIME_DIR':'/correct'}}), patch.object(m.h,'remote_run',side_effect=run), patch.dict(m.os.environ,{'XDG_RUNTIME_DIR':'/foreign'},clear=True), self.assertRaisesRegex(ValueError,'runtime directory differs'):
    m.main()

if __name__=='__main__':unittest.main()
