import importlib.util
from pathlib import Path
import tempfile
import unittest

spec = importlib.util.spec_from_file_location("support_sync", Path(__file__).with_name("sync_generated_support.py"))
module = importlib.util.module_from_spec(spec)
spec.loader.exec_module(module)


class SupportSyncTests(unittest.TestCase):
    def setUp(self):
        temporary = tempfile.TemporaryDirectory()
        self.addCleanup(temporary.cleanup)
        self.source = Path(temporary.name) / "source"
        self.sdk = Path(temporary.name) / "sdk"
        directory = self.sdk / "resources/templates"
        (directory / "codegen").mkdir(parents=True)
        (directory / "init").mkdir()
        self.template = directory / "codegen/pch_h.inja"
        self.template.write_text("ignored dynamic configuration {{ image_base }}\n" + module.PCH_START + "checked_memory();\n" + module.INCLUDE + "\n")
        (directory / "codegen/_indirect_call.inja").write_text("trusted_dispatch();\n")
        self.cmake_template = directory / "init/rexglue_cmake.inja"
        self.cmake_template.write_text("ignored {{ sdk_version }}\n" + module.CMAKE_START + '\nfunction(settings name)\n use({{ cmake_var("name") }})\nendfunction()\n\n' + module.CMAKE_END)
        self.header = self.source / "generated/default/title_pch.h"
        self.header.parent.mkdir(parents=True)
        self.prefix = "#define REX_IMAGE_BASE 0x82000000ull\n#define REX_IMAGE_SIZE 0x980000ull\n#define REX_FUNCTION_TABLE_BASE 0x8C000000ull\n#define REX_CONFIG_SKIP_LR\n"
        self.original = self.prefix + module.PCH_START + "old_support();\n"
        self.header.write_text(self.original)
        self.cmake = self.source / "generated/rexglue.cmake"
        self.cmake_original = "module_version_and_paths\n" + module.CMAKE_START + "\nold settings\n" + module.CMAKE_END + "\nunchanged_targets\n"
        self.cmake.write_text(self.cmake_original)

    def test_verify_write_and_idempotence_preserve_identity_and_cmake_surroundings(self):
        self.assertEqual(module.synchronize(self.source,self.sdk), (1,2))
        self.assertEqual(self.header.read_text(),self.original)
        self.assertEqual(self.cmake.read_text(),self.cmake_original)
        self.assertEqual(module.synchronize(self.source,self.sdk,True),(1,2))
        self.assertTrue(self.header.read_text().startswith(self.prefix))
        self.assertIn("trusted_dispatch();",self.header.read_text())
        self.assertTrue(self.cmake.read_text().startswith("module_version_and_paths\n"))
        self.assertTrue(self.cmake.read_text().endswith("unchanged_targets\n"))
        self.assertIn("use(${name})",self.cmake.read_text())
        self.assertEqual(module.synchronize(self.source,self.sdk),(1,0))

    def assert_no_writes(self):
        with self.assertRaises(ValueError):
            module.synchronize(self.source,self.sdk,True)
        self.assertEqual(self.header.read_text(),self.original)
        self.assertEqual(self.cmake.read_text(),self.cmake_original)

    def test_malformed_later_module_prevents_every_write(self):
        bad=self.source/"generated/z/z_pch.h"
        bad.parent.mkdir();bad.write_text("broken")
        self.assert_no_writes();self.assertEqual(bad.read_text(),"broken")

    def test_malformed_cmake_prevents_pch_write(self):
        self.cmake_original="broken";self.cmake.write_text(self.cmake_original)
        self.assert_no_writes()

    def test_unknown_cpp_expression_rejected(self):
        self.template.write_text(self.template.read_text()+"{{ hidden }}")
        self.assert_no_writes()

    def test_unknown_cmake_expression_rejected(self):
        self.cmake_template.write_text(self.cmake_template.read_text().replace("endfunction()","{{ unknown }}"))
        self.assert_no_writes()

    def test_duplicate_include_rejected(self):
        self.template.write_text(self.template.read_text()+module.INCLUDE)
        self.assert_no_writes()

    def test_duplicate_module_identity_rejected(self):
        self.original=self.original.replace(module.PCH_START,"#define REX_IMAGE_BASE 1\n"+module.PCH_START)
        self.header.write_text(self.original);self.assert_no_writes()

    def test_reversed_cmake_sections_rejected(self):
        self.cmake_original=module.CMAKE_END+module.CMAKE_START
        self.cmake.write_text(self.cmake_original);self.assert_no_writes()

    def test_no_modules_rejected(self):
        self.header.unlink()
        with self.assertRaises(ValueError):module.synchronize(self.source,self.sdk)


if __name__=="__main__":
    unittest.main()
