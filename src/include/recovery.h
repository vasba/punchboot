#ifndef __RECOVERY_H__
#define __RECOVERY_H__

#include <types.h>

#define PB_CMD_TRANSFER_DATA 0xAA
#define PB_CMD_FLASH_BOOT 0xB0
#define PB_CMD_RESET      0xB1

struct pb_usb_command_hdr {
    u32 cmd;
    u32 payload_sz;
    u32 payload_crc;
    u32 header_crc;
} __attribute__ ((packed));

struct pb_chunk_hdr {
    u16 chunk_no;
    u16 chunk_sz;
} __attribute__ ((packed));

void recovery(void);
void recovery_cmd_event(u8 *bfr, u16 sz);


#endif
