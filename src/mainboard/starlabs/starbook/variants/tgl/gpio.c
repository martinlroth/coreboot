/* SPDX-License-Identifier: GPL-2.0-only */

#include <variants.h>

/* Early pad configuration in bootblock */
const struct pad_config early_gpio_table[] = {
	/* Debug Connector */
	PAD_CFG_NF(GPP_C20, NONE, DEEP, NF1),				/* RXD */
	PAD_CFG_NF(GPP_C21, NONE, DEEP, NF1),				/* TXD */
};

const struct pad_config *variant_early_gpio_table(size_t *num)
{
	*num = ARRAY_SIZE(early_gpio_table);
	return early_gpio_table;
}

/* Pad configuration in ramstage. */
const struct pad_config gpio_table[] = {
	/* General Purpose I/O Deep */
	PAD_CFG_NF(GPD0, NONE, DEEP, NF1),				/* Battery Low */
	PAD_CFG_NF(GPD1, NONE, DEEP, NF1),				/* Charger Connected */
	PAD_CFG_NF(GPD3, UP_20K, DEEP, NF1),				/* Power Button */
	PAD_CFG_NF(GPD4, NONE, DEEP, NF1),				/* Sleep S3 */
	PAD_CFG_NF(GPD5, NONE, DEEP, NF1),				/* Sleep S4 */
	PAD_CFG_NF(GPD8, NONE, DEEP, NF1),				/* Bluetooth Suspend */

	/* eSPI */
	// PAD_CFG_NF_IOSTANDBY_IGNORE(GPP_A0, UP_20K, DEEP, NF1),	/* eSPI IO 0 */
	// PAD_CFG_NF_IOSTANDBY_IGNORE(GPP_A1, UP_20K, DEEP, NF1),	/* eSPI IO 1 */
	// PAD_CFG_NF_IOSTANDBY_IGNORE(GPP_A2, UP_20K, DEEP, NF1),	/* eSPI IO 2 */
	// PAD_CFG_NF_IOSTANDBY_IGNORE(GPP_A3, UP_20K, DEEP, NF1),	/* eSPI IO 3 */
	// PAD_CFG_NF_IOSTANDBY_IGNORE(GPP_A4, UP_20K, DEEP, NF1),	/* eSPI CS 0 */
	// PAD_CFG_NF_IOSTANDBY_IGNORE(GPP_A5, UP_20K, DEEP, NF1),	/* eSPI Clk */
	// PAD_CFG_NF_IOSTANDBY_IGNORE(GPP_A6, NONE, DEEP, NF1),	/* eSPI Reset */

	/* Touchpad */
	PAD_CFG_NF(GPP_C16, NONE, DEEP, NF1),				/* Data */
	PAD_CFG_NF(GPP_C17, NONE, DEEP, NF1),				/* Clock */
	PAD_CFG_GPI_APIC_LOW(GPP_C8, NONE, PLTRST),			/* Interrupt */

	/* SSD */
	PAD_NC(GPP_D8, NONE),						/* Clock Request 3 */
	PAD_CFG_GPO(GPP_A11, 1, PLTRST),				/* Reset */
	PAD_CFG_GPO(GPP_D16, 1, PLTRST),				/* Enable */

	/* SATA */
	PAD_CFG_NF(GPP_A12, UP_20K, DEEP, NF1),				/* PEDET */

	/* Wireless */
	PAD_CFG_NF(GPP_F0, NONE, DEEP, NF1),				/* BRI Data */
	PAD_CFG_NF(GPP_F1, NONE, DEEP, NF1),				/* BRI Response */
	PAD_CFG_NF(GPP_F2, NONE, DEEP, NF1),				/* RGI Data */
	PAD_CFG_NF(GPP_F3, NONE, DEEP, NF1),				/* RGI Response */
	PAD_CFG_NF(GPP_A8, NONE, DEEP, NF2),				/* RF Reset */
	PAD_CFG_NF(GPP_A9, NONE, DEEP, NF2),				/* Modem Clock Request */

	/* Display */
	PAD_CFG_NF(GPP_E14, NONE, DEEP, NF1),				/* eDP Hot Plug */
	PAD_CFG_NF(GPP_A18, NONE, DEEP, NF1),				/* HDMI Hot Plug */
	PAD_CFG_NF(GPP_H16, NONE, DEEP, NF1),				/* HDMI Clock */
	PAD_CFG_NF(GPP_H17, NONE, DEEP, NF1),				/* HDMI Data */
	PAD_CFG_NF(GPP_B11, NONE, DEEP, NF1),				/* PMC Interrupt */
	PAD_CFG_NF(GPP_C6, NONE, PWROK, NF1),				/* SML Clock */
	PAD_CFG_NF(GPP_C7, NONE, PWROK, NF1),				/* SML Data */

	/* Webcam */
	PAD_CFG_TERM_GPO(GPP_D19, 1, UP_20K, DEEP),			/* Power */

	/* Retimer */
	PAD_NC(GPP_E18, NATIVE),					/* TBT0 TXD */
	PAD_NC(GPP_E19, NATIVE),					/* TBT0 RXD */
	PAD_CFG_GPO(GPP_A23, 0, DEEP),					/* Force Power */

	/* High-Definition Audio */
	PAD_CFG_NF(GPP_R0, NATIVE, DEEP, NF1),				/* Clock */
	PAD_CFG_NF(GPP_R1, NATIVE, DEEP, NF1),				/* Sync */
	PAD_CFG_NF(GPP_R2, NATIVE, DEEP, NF1),				/* Data Output */
	PAD_CFG_NF(GPP_R3, NATIVE, DEEP, NF1),				/* Data Input */
	PAD_NC(GPP_R4, NONE),						/* Reset */

	/* PCH */
	PAD_CFG_NF(GPP_H18, NONE, DEEP, NF1),				/* C10 Gate */
	PAD_CFG_NF(GPP_B13, NONE, DEEP, NF1),				/* Platform Reset */
	PAD_CFG_NF(GPP_B0, NONE, DEEP, NF1),				/* Vendor ID 0 */
	PAD_CFG_NF(GPP_B1, NONE, DEEP, NF1),				/* Vendor ID 1 */
	PAD_NC(GPP_B2, NONE),						/* Processor Hot */

	/* TPM */
	PAD_CFG_GPI_APIC_LOW(GPP_C14, NONE, PLTRST),			/* Interrupt */

	/* SMBus */
	PAD_CFG_NF(GPP_C0, NONE, DEEP, NF1),				/* Clock */
	PAD_CFG_NF(GPP_C1, NONE, DEEP, NF1),				/* Data */

	/* Config Straps 									[ Low      / High     ] */
	PAD_CFG_GPO(GPP_B14, 0, RSMRST),				/* Top Swap		[ Disabled / Enabled  ] */
	PAD_CFG_GPO(GPP_B18, 0, RSMRST),				/* Reboot Support	[ Enabled  / Disabled ] */
	PAD_CFG_GPO(GPP_C2, 1, RSMRST),					/* TLS Confidentiality	[ Disabled / Enabled  ] */
	PAD_CFG_GPO(GPP_B23, 0, DEEP),					/* XTAL			[ 38.4Mhz  / 19.2MHz  ] */
	PAD_CFG_GPO(GPP_C5, 0, RSMRST),					/* eSPI			[ Enabled  / Disabled ] */
	PAD_CFG_GPO(GPP_E6, 0, RSMRST),					/* JTAG ODT		[ Disabled / Enabled  ] */
	PAD_CFG_GPO(GPP_E21, 0, RSMRST),				/* TBT LSX #1		[ 1.8V     / 3.3V     ] */
	PAD_CFG_GPO(GPP_H0, 0, RSMRST),					/* BFX Strap 2 Bit 2	[ Disabled / Enabled  ] */
	PAD_CFG_GPO(GPP_H1, 0, RSMRST),					/* BFX Strap 2 Bit 3	[ Disabled / Enabled  ] */
	PAD_CFG_GPO(GPP_H2, 0, RSMRST),					/* BFX Strap 2 Bit 4	[ Disabled / Enabled  ] */
	PAD_CFG_GPO(GPP_F7, 0, RSMRST),					/* MCRO LDO		[ Disabled / Bypass   ] */
	PAD_CFG_GPO(GPD7, 0, RSMRST),					/* RTC Clock Delay	[ Disabled / 95ms     ] */

	/* GPD2:	LAN_WAKE#		*/
	PAD_NC(GPD2, NONE),
	/* GPD6:	SIO_SLP_A#		*/
	PAD_NC(GPD6, NONE),
	/* GPD9:	SIO_SLP_WLAN#		*/
	PAD_NC(GPD9, NONE),
	/* GPD10:	SIO_SLP_S5#		*/
	PAD_NC(GPD10, NONE),
	/* GPD11:	PM_LANPHY_EN		*/
	PAD_NC(GPD11, NONE),

	/* A7:	WLAN_PCM_CLK			*/
	PAD_NC(GPP_A7, NONE),
	/* A10:	WLAN_PCM_IN			*/
	PAD_NC(GPP_A10, NONE),
	/* A13:	Not Connected			*/
	PAD_NC(GPP_A13, NONE),
	/* A14:	Not Connected			*/
	PAD_NC(GPP_A14, NONE),
	/* A15	Not Connected			*/
	PAD_NC(GPP_A15, NONE),
	/* A16:	USB2_OCB_3			*/
	PAD_NC(GPP_A16, NONE),
	/* A17:	Not Connected			*/
	PAD_NC(GPP_A17, NONE),
	/* A19	Not Connected			*/
	PAD_NC(GPP_A19, NONE),
	/* A20:	Not Connected			*/
	PAD_NC(GPP_A20, NONE),
	/* A21	Not Connected			*/
	PAD_NC(GPP_A21, NONE),
	/* A22:	Not Connected			*/
	PAD_NC(GPP_A22, NONE),

	/* B3:	Not Connected			*/
	PAD_NC(GPP_B3, NONE),
	/* B4:	Not Connected			*/
	PAD_NC(GPP_B4, NONE),
	/* B5:	Not Connected			*/
	PAD_NC(GPP_B5, NONE),
	/* B6:	Not Connected			*/
	PAD_NC(GPP_B6, NONE),
	/* B7:	Not Connected			*/
	PAD_NC(GPP_B7, NONE),
	/* B8:	Not Connected			*/
	PAD_NC(GPP_B8, NONE),
	/* B9:	PWR_MON_I2C_SDA_R		*/
	PAD_NC(GPP_B9, NONE),
	/* B10:	PWR_MON_I2C_SCL_R		*/
	PAD_NC(GPP_B10, NONE),
	/* B12:	PM_SLP_S0_N			*/
	PAD_NC(GPP_B12, NONE),
	/* B15:	Not Connected			*/
	PAD_NC(GPP_B15, NONE),
	/* B16:	M2_PCH_SSD_PWREN		*/
	PAD_NC(GPP_B16, NONE),
	/* B17:	Not Connected			*/
	PAD_NC(GPP_B17, NONE),
	/* B19:	GSPI1_CS0_FPS_N			*/
	PAD_NC(GPP_B19, NONE),
	/* B20:	GSPI1_CLK_FPS			*/
	PAD_NC(GPP_B20, NONE),
	/* B21:	GSPI1_MISO_FPS			*/
	PAD_NC(GPP_B21, NONE),
	/* B22:	GSPI1_MOSI_FPS			*/
	PAD_CFG_GPO(GPP_B22, 0, DEEP),

	/* C3:	SML0_CLK			*/
	PAD_NC(GPP_C3, NONE),
	/* C4:	SML0_DATA			*/
	PAD_NC(GPP_C4, NONE),
	/* C9:	Not Connected			*/
	PAD_NC(GPP_C9, NONE),
	/* C10:	Not Connected			*/
	PAD_NC(GPP_C10, NONE),
	/* C11:	Not Connected			*/
	PAD_NC(GPP_C11, NONE),
	/* C12:	Not Connected			*/
	PAD_NC(GPP_C12, NONE),
	/* C13:	Not Connected			*/
	PAD_NC(GPP_C13, NONE),
	/* C15:	TPM_RST				*/
	PAD_NC(GPP_C15, NONE),
	/* C18:	TOUCH_I2C_SDA			*/
	PAD_NC(GPP_C18, NONE),
	/* C19:	TOUCH_I2C_CLK			*/
	PAD_NC(GPP_C19, NONE),
	/* C22:	Not Connected			*/
	PAD_NC(GPP_C22, NONE),
	/* C23:	WLAN_WAKE_N			*/
	PAD_NC(GPP_C23, NONE),

	/* D0:	ACCEL1_INT			*/
	PAD_NC(GPP_D0, NONE),
	/* D1:	ACCEL2_INT			*/
	PAD_NC(GPP_D1, NONE),
	/* D2:	Not Connected			*/
	PAD_NC(GPP_D2, NONE),
	/* D3:	Not Connected			*/
	PAD_NC(GPP_D3, NONE),
	/* D4:	Not Connected			*/
	PAD_NC(GPP_D4, NONE),
	/* D5:	CLKREQ0_M2_SSD_N		*/
	PAD_NC(GPP_D5, NONE),
	/* D6:	CLKREQ1_WLAN_N			*/
	PAD_NC(GPP_D6, NONE),
	/* D7:	LAN_CLKREQ#			*/
	PAD_NC(GPP_D7, NONE),
	/* D9:	Not Connected			*/
	PAD_NC(GPP_D9, NONE),
	/* D10:	Not Connected			*/
	PAD_NC(GPP_D10, NONE),
	/* D11:	Not Connected			*/
	PAD_NC(GPP_D11, NONE),
	/* D12:	Not Connected			*/
	PAD_NC(GPP_D12, NONE),
	/* D13:	Not Connected			*/
	PAD_NC(GPP_D13, NONE),
	/* D14:	Not Connected			*/
	PAD_NC(GPP_D14, NONE),
	/* D15:	Not Connected			*/
	PAD_NC(GPP_D15, NONE),
	/* D17:	Not Connected			*/
	PAD_NC(GPP_D17, NONE),
	/* D18:	Not Connected			*/
	PAD_NC(GPP_D18, NONE),

	/* E0:	SATAXPCIE_0_SATAGP_0		*/
	PAD_NC(GPP_E0, NONE),
	/* E1:	Not Connected			*/
	PAD_NC(GPP_E1, NONE),
	/* E2:	Not Connected			*/
	PAD_NC(GPP_E2, NONE),
	/* E3:	FPS_INT				*/
	PAD_NC(GPP_E3, NONE),
	/* E4:	Not Connected			*/
	PAD_NC(GPP_E4, NONE),
	/* E5:	Not Connected			*/
	PAD_NC(GPP_E5, NONE),
	/* E7:	EC_SMI_LP_N			*/
	PAD_NC(GPP_E7, NONE),
	/* E8:	EC_SLP_S0IX_N			*/
	PAD_NC(GPP_E8, NONE),
	/* E9:	USB2_TCP01_OC_N			*/
	PAD_NC(GPP_E9, NONE),
	/* E10:	SPI1_TCH_PNL_CS_N		*/
	PAD_NC(GPP_E10, NONE),
	/* E11:	SPI1_CLK			*/
	PAD_NC(GPP_E11, NONE),
	/* E12:	Not Connected			*/
	PAD_NC(GPP_E12, NONE),
	/* E13:	Not Connected			*/
	PAD_NC(GPP_E13, NONE),
	/* E15:	Not Connected			*/
	PAD_NC(GPP_E15, NONE),
	/* E16:	Not Connected			*/
	PAD_NC(GPP_E16, NONE),
	/* E17:	Not Connected			*/
	PAD_NC(GPP_E17, NONE),
	/* E20:	Not Connected			*/
	PAD_NC(GPP_E20, NONE),
	/* E22:	Not Connected			*/
	PAD_NC(GPP_E22, NONE),
	/* E23:	Not Connected			*/
	PAD_NC(GPP_E23, NONE),

	/* F4:	Not Connected			*/
	PAD_NC(GPP_F4, NONE),
	/* F5:	GPPC_F5_MODEM_CLKREQ		*/
	PAD_NC(GPP_F5, NONE),
	/* F6:					*/
	PAD_NC(GPP_F6, NONE),
	/* F8:	Not Connected			*/
	PAD_NC(GPP_F8, NONE),
	/* F9:	Not Connected			*/
	PAD_NC(GPP_F9, NONE),
	/* F10:	GPPC_F_10			*/
	PAD_CFG_GPO(GPP_F10, 0, DEEP),
	/* F11:	Not Connected			*/
	PAD_NC(GPP_F11, NONE),
	/* F12:	Not Connected			*/
	PAD_NC(GPP_F12, NONE),
	/* F13:	Not Connected			*/
	PAD_NC(GPP_F13, NONE),
	/* F14:	Not Connected			*/
	PAD_NC(GPP_F14, NONE),
	/* F15:	Not Connected			*/
	PAD_NC(GPP_F15, NONE),
	/* F16:	Not Connected			*/
	PAD_NC(GPP_F16, NONE),
	/* F17:	TOUCH_PANEL_RESET_N		*/
	PAD_NC(GPP_F17, NONE),
	/* F18:	TOUCH_PANEL_INT_N		*/
	PAD_NC(GPP_F18, NONE),
	/* F19:	Not Connected			*/
	PAD_NC(GPP_F19, NONE),
	/* F20:	Not Connected			*/
	PAD_NC(GPP_F20, NONE),
	/* F21:	Not Connected			*/
	PAD_NC(GPP_F21, NONE),
	/* F22:	Not Connected			*/
	PAD_NC(GPP_F22, NONE),
	/* F23:	Not Connected			*/
	PAD_NC(GPP_F23, NONE),

	/* H3:	Not Connected			*/
	PAD_NC(GPP_H3, NONE),
	/* H4:	GSENSOR_I2C_SDA			*/
	PAD_NC(GPP_H4, NONE),
	/* H5:	GSENSOR_I2C_SCL			*/
	PAD_NC(GPP_H5, NONE),
	/* H6:	Not Connected			*/
	PAD_NC(GPP_H6, NONE),
	/* H7:	Not Connected			*/
	PAD_NC(GPP_H7, NONE),
	/* H8:	Not Connected			*/
	PAD_NC(GPP_H8, NONE),
	/* H9:	Not Connected			*/
	PAD_NC(GPP_H9, NONE),
	/* H10:	Not Connected			*/
	PAD_NC(GPP_H10, NONE),
	/* H11:	Not Connected			*/
	PAD_NC(GPP_H11, NONE),
	/* H12:	Not Connected			*/
	PAD_NC(GPP_H12, NONE),
	/* H13:	Not Connected			*/
	PAD_NC(GPP_H13, NONE),
	/* H14:	Not Connected			*/
	PAD_NC(GPP_H14, NONE),
	/* H15:	Not Connected			*/
	PAD_NC(GPP_H15, NONE),
	/* H19:	UART_BT_WAKE_N			*/
	PAD_NC(GPP_H19, NONE),
	/* H20:	Not Connected			*/
	PAD_NC(GPP_H20, NONE),
	/* H21:	Not Connected			*/
	PAD_NC(GPP_H21, NONE),
	/* H22:	Not Connected			*/
	PAD_NC(GPP_H22, NONE),
	/* H23:	Not Connected			*/
	PAD_NC(GPP_H23, NONE),

	/* R5:	Not Connected			*/
	PAD_NC(GPP_R5, NONE),
	/* R6:	Not Connected			*/
	PAD_NC(GPP_R6, NONE),
	/* R7:	Not Connected			*/
	PAD_NC(GPP_R7, NONE),

	/* S0:	Not Connected			*/
	PAD_NC(GPP_S0, NONE),
	/* S1:	Not Connected			*/
	PAD_NC(GPP_S1, NONE),
	/* S2:	Not Connected			*/
	PAD_NC(GPP_S2, NONE),
	/* S3:	Not Connected			*/
	PAD_NC(GPP_S3, NONE),
	/* S4:	Not Connected			*/
	PAD_NC(GPP_S4, NONE),
	/* S5:	Not Connected			*/
	PAD_NC(GPP_S5, NONE),
	/* S6:	Not Connected			*/
	PAD_NC(GPP_S6, NONE),
	/* S7:	Not Connected			*/
	PAD_NC(GPP_S7, NONE),

	/* T2:	Not Connected			*/
	PAD_NC(GPP_T2, NONE),
	/* T3:	Not Connected			*/
	PAD_NC(GPP_T3, NONE),

	/* U4:	Not Connected			*/
	PAD_NC(GPP_U4, NONE),
	/* U5:	Not Connected			*/
	PAD_NC(GPP_U5, NONE),
};

const struct pad_config *variant_gpio_table(size_t *num)
{
	*num = ARRAY_SIZE(gpio_table);
	return gpio_table;
}
