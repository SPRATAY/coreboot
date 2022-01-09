## SPDX-License-Identifier: GPL-2.0-only
## copy for EasyNote LM85 (MS2290)

romstage-y += gpio.c

ramstage-$(CONFIG_MAINBOARD_USE_LIBGFXINIT) += gma-mainboard.ads
