/* SPDX-License-Identifier: GPL-2.0-or-later */

#include <device/azalia_device.h>

const u32 cim_verb_data[] = {
	0x10ec0269,	/* Codec Vendor / Device ID: Realtek ALC269 */
	0x144dc06a,	/* Subsystem ID  */
	11,		/* Number of 4 dword sets */
    AZALIA_SUBVENDOR(0, 0x144dc06a),
    AZALIA_PIN_CFG(0, 0x11, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x12, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x15, 0x0121101f),
	AZALIA_PIN_CFG(0, 0x16, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x18, 0x01a11820),
	AZALIA_PIN_CFG(0, 0x19, 0x99a3092f),
	AZALIA_PIN_CFG(0, 0x1a, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x1b, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x1d, 0x40038205),
	AZALIA_PIN_CFG(0, 0x1e, 0x00000014),

    //0x80862804,	/* Codec Vendor / Device ID: Intel Ibexpeak HDMI */
	//0x80860101,	/* Subsystem ID  */
	//4,		/* Number of 4 dword sets */
	//AZALIA_SUBVENDOR(3, 0x80860101),
	//AZALIA_PIN_CFG(3, 0x04, 0x18560010),
	//AZALIA_PIN_CFG(3, 0x05, 0x58560020),
	//AZALIA_PIN_CFG(3, 0x06, 0x58560030),

};

const u32 pc_beep_verbs[0] = {};

AZALIA_ARRAY_SIZES;
