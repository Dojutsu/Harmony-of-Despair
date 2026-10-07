import importlib.util
from pathlib import Path
import tempfile
import unittest

spec = importlib.util.spec_from_file_location("sync_indirect", Path(__file__).with_name("sync_indirect_dispatch.py"))
module = importlib.util.module_from_spec(spec)
spec.loader.exec_module(module)


class DispatchSyncTests(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory()
        self.addCleanup(self.temporary.cleanup)
        self.root = Path(self.temporary.name)
        self.source, self.sdk = self.root / "source", self.root / "sdk"
        self.template = self.sdk / "resources/templates/codegen/_indirect_call.inja"
        self.template.parent.mkdir(parents=True)
        self.template.write_text(module.START + "trusted-dispatch\n")
        self.header = self.source / "generated/default/title_pch.h"
        self.header.parent.mkdir(parents=True)
        self.original = "#define REX_FUNCTION_TABLE_BASE 0x8C000000ull\n" + module.START + "old-dispatch\n" + module.END + "untouched-tail\n"
        self.header.write_text(self.original)

    def test_verify_then_write_preserves_module_identity_and_other_generated_content(self):
        self.assertEqual(module.synchronize(self.source, self.sdk), (1, 1))
        self.assertEqual(self.header.read_text(), self.original)
        self.assertEqual(module.synchronize(self.source, self.sdk, True), (1, 1))
        result = self.header.read_text()
        self.assertTrue(result.startswith("#define REX_FUNCTION_TABLE_BASE 0x8C000000ull\n"))
        self.assertTrue(result.endswith(module.END + "untouched-tail\n"))
        self.assertEqual(module.synchronize(self.source, self.sdk), (1, 0))

    def test_malformed_later_header_leaves_every_header_untouched(self):
        bad = self.source / "generated/z/z_pch.h"
        bad.parent.mkdir(parents=True)
        bad.write_text("broken")
        with self.assertRaises(ValueError):
            module.synchronize(self.source, self.sdk, True)
        self.assertEqual(self.header.read_text(), self.original)
        self.assertEqual(bad.read_text(), "broken")

    def test_dynamic_template_is_rejected_before_any_write(self):
        self.template.write_text(module.START + "{{ guest_table }}")
        with self.assertRaises(ValueError):
            module.synchronize(self.source, self.sdk, True)
        self.assertEqual(self.header.read_text(), self.original)

    def test_no_modules_is_rejected(self):
        self.header.unlink()
        with self.assertRaises(ValueError):
            module.synchronize(self.source, self.sdk)


if __name__ == "__main__":
    unittest.main()
