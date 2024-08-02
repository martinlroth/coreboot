/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef __AMD_PSP_DEF_H__
#define __AMD_PSP_DEF_H__

#include <types.h>
#include <commonlib/helpers.h>
#include <amdblocks/psp.h>

#define CORE_2_PSP_MSG_38_OFFSET	0x10998 /* 4 byte */
#define   CORE_2_PSP_MSG_38_FUSE_SPL		BIT(12)
#define   CORE_2_PSP_MSG_38_SPL_FUSE_ERROR	BIT(13)
#define   CORE_2_PSP_MSG_38_SPL_ENTRY_ERROR	BIT(14)
#define   CORE_2_PSP_MSG_38_SPL_ENTRY_MISSING	BIT(15)

/* x86 to PSP commands */
#define MBOX_BIOS_CMD_SMM_INFO			0x02
#define MBOX_BIOS_CMD_SX_INFO			0x03
#define   MBOX_BIOS_CMD_SX_INFO_SLEEP_TYPE_MAX	0x07
#define MBOX_BIOS_CMD_RSM_INFO			0x04
#define MBOX_BIOS_CMD_PSP_QUERY			0x05
#define MBOX_BIOS_CMD_BOOT_DONE			0x06
#define MBOX_BIOS_CMD_CLEAR_S3_STS		0x07
#define MBOX_BIOS_CMD_S3_DATA_INFO		0x08
#define MBOX_BIOS_CMD_NOP			0x09
#define MBOX_BIOS_CMD_PSB_AUTO_FUSING		0x21
#define MBOX_BIOS_CMD_SET_SPL_FUSE		0x2d
#define MBOX_BIOS_CMD_QUERY_SPL_FUSE		0x47
#define MBOX_BIOS_CMD_I2C_TPM_ARBITRATION	0x64
#define MBOX_BIOS_CMD_ABORT			0xfe

/* x86 to PSP commands, v1-only */
#define MBOX_BIOS_CMD_DRAM_INFO			0x01
#define MBOX_BIOS_CMD_SMU_FW			0x19
#define MBOX_BIOS_CMD_SMU_FW2			0x1a

#define SMN_PSP_PUBLIC_BASE			0x3800000

/* command/response format, BIOS builds this in memory
 *   mbox_buffer_header: generic header
 *   mbox_buffer:        command-specific buffer format
 *
 * AMD reference code aligns and pads all buffers to 32 bytes.
 */
struct mbox_buffer_header {
	u32 size;	/* total size of buffer */
	u32 status;	/* command status, filled by PSP if applicable */
} __packed;

/*
 * command-specific buffer definitions:  see NDA document #54267
 * The following commands need a buffer definition if they are to be used.
 * All other commands will work with the default buffer.
 * MBOX_BIOS_CMD_SMM_INFO		MBOX_BIOS_CMD_PSP_QUERY
 * MBOX_BIOS_CMD_SX_INFO		MBOX_BIOS_CMD_S3_DATA_INFO
 * MBOX_BIOS_CMD_RSM_INFO
 */

struct mbox_default_buffer {	/* command-response buffer unused by command */
	struct mbox_buffer_header header;
} __packed __aligned(32);

struct smm_req_buffer {
	uint64_t smm_base;		/* TSEG base */
	uint64_t smm_mask;		/* TSEG mask */
	uint64_t psp_smm_data_region;	/* PSP region in SMM space */
	uint64_t psp_smm_data_length;	/* PSP region length in SMM space */
	struct smm_trigger_info smm_trig_info;
#if CONFIG(SOC_AMD_COMMON_BLOCK_PSP_GEN2)
	struct smm_register_info smm_reg_info;
#endif
	uint64_t psp_mbox_smm_buffer_address;
	uint64_t psp_mbox_smm_flag_address;
} __packed;

struct mbox_cmd_smm_info_buffer {
	struct mbox_buffer_header header;
	struct smm_req_buffer req;
} __packed __aligned(32);

struct mbox_cmd_sx_info_buffer {
	struct mbox_buffer_header header;
	u8 sleep_type;
} __packed __aligned(32);

struct mbox_cmd_late_spl_buffer {
	struct mbox_buffer_header header;
	uint32_t	spl_value;
} __packed __aligned(32);

struct dtpm_config {
	uint32_t gpio;
} __packed;

enum dtpm_request_type {
	DTPM_REQUEST_ACQUIRE,	/* Acquire I2C bus */
	DTPM_REQUEST_RELEASE,	/* Release I2C bus */
	DTPM_REQUEST_CONFIG,	/* Provide DTPM info */
	DTPM_REQUEST_MAX,
};

struct mbox_cmd_dtpm_config_buffer {
	struct mbox_buffer_header header;
	uint32_t request_type;
	struct dtpm_config config;
} __packed __aligned(32);

#define PSP_INIT_TIMEOUT 10000 /* 10 seconds */
#define PSP_CMD_TIMEOUT 1000 /* 1 second */

#define C2P_BUFFER_MAXSIZE 0xc00 /* Core-to-PSP buffer */
#define P2C_BUFFER_MAXSIZE 0xc00 /* PSP-to-core buffer */

/* PSP to x86 status */
enum mbox_p2c_status {
	MBOX_PSP_SUCCESS		= 0x00,
	MBOX_PSP_INVALID_PARAMETER	= 0x01,
	MBOX_PSP_CRC_ERROR		= 0x02,
	MBOX_PSP_COMMAND_PROCESS_ERROR	= 0x04,
	MBOX_PSP_UNSUPPORTED		= 0x08,
	MBOX_PSP_SPI_BUSY_ASYNC		= 0x0a,
	MBOX_PSP_SPI_BUSY		= 0x0b,
};

uintptr_t get_psp_mmio_base(void);

void psp_print_cmd_status(int cmd_status, struct mbox_buffer_header *header);

/* This command needs to be implemented by the generation specific code. */
int send_psp_command(u32 command, void *buffer);

enum cb_err soc_read_c2p38(uint32_t *msg_38_value);

void enable_psp_smi(void);

enum mbox_p2c_status psp_smi_spi_get_info(struct mbox_default_buffer *buffer);
enum mbox_p2c_status psp_smi_spi_read(struct mbox_default_buffer *buffer);
enum mbox_p2c_status psp_smi_spi_write(struct mbox_default_buffer *buffer);
enum mbox_p2c_status psp_smi_spi_erase(struct mbox_default_buffer *buffer);

#endif /* __AMD_PSP_DEF_H__ */
