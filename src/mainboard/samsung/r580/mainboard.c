/* SPDX-License-Identifier: GPL-2.0-only */
/* copy for EasyNote LM85 (MS2290) */
#include <device/device.h>
#include <northbridge/intel/ironlake/ironlake.h>
#include <southbridge/intel/bd82x6x/pch.h>
#include <ec/acpi/ec.h>
#include <drivers/intel/gma/int15.h>
#include <pc80/keyboard.h>

static void mainboard_enable(struct device *dev)
{
	int i;
	const u8 dmp[256] = {
		0x00, 0x20, 0x00, 0x00, 0x00, 0x02, 0x89, 0xe4, 0x30, 0x00, 0x40, 0x14, 0x00, 0x00, 0x00, 0x11,
		0x03, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x00, 0xf4, 0x01, 0x00, 0x00, 0x01,
		0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x62, 0x01, 0x04, 0x00, 0x08, 0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08,
		0x42, 0x07, 0x09, 0x09, 0xf0, 0x00, 0x00, 0xf0, 0xa9, 0x00, 0x00, 0x06, 0x00, 0x00, 0xff, 0x00,
		0x00, 0x01, 0x00, 0x04, 0xff, 0xff, 0x00, 0x00, 0x00, 0xb1, 0x00, 0x00, 0x00, 0x00, 0x04, 0x0b,
		0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x28, 0x1b, 0x21, 0x00, 0x2c, 0x3b, 0x13, 0x00,
		0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x55, 0x5a, 0x57, 0x5c, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x45, 0x00, 0x00, 0x00,
		0x52, 0x10, 0x52, 0x10, 0x64, 0x00, 0x00, 0x00, 0x74, 0x30, 0x00, 0x60, 0x00, 0x00, 0xaf, 0x0b,
		0x30, 0x45, 0x2e, 0x30, 0x38, 0x41, 0x43, 0x2e, 0x30, 0x31, 0x2e, 0x31, 0x36, 0x20, 0x00, 0x00,
	};

	for (i = 0; i < 256; i++)
		ec_write (i, dmp[i]);

	install_intel_vga_int15_handler(GMA_INT15_ACTIVE_LFP_INT_LVDS, GMA_INT15_PANEL_FIT_DEFAULT, GMA_INT15_BOOT_DISPLAY_LFP, 2);

	/* This sneaked in here, because EasyNote has no SuperIO chip.
	 */
	pc_keyboard_init(NO_AUX_DEVICE);
}

struct chip_operations mainboard_ops = {
	.enable_dev = mainboard_enable,
};
