/**
 * Punch BOOT
 *
 * Copyright (C) 2018 Jonas Persson <jonpe960@gmail.com>
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "pb_types.h"

#define PB_CONFIG_BOOT       0
#define PB_CONFIG_BOOT_COUNT 1

struct pb_config_item {
    const s8 index;
    const char description[16];
#define PB_CONFIG_ITEM_RW 1
#define PB_CONFIG_ITEM_RO 2
#define PB_CONFIG_ITEM_OTP 3
    const u8 access;
    const u32 default_value;
} __attribute__ ((packed));

#define PB_CONFIG_MAGIC 0xd276ec0c
struct pb_config_data {
    u32 _magic;
    u32 crc;
    u32 data[127];
};

u32 config_init(void);
u32 config_get_u32(u8 index, u32 *value);
u32 config_set_u32(u8 index, u32 value);
u32 config_commit(void);
u8* config_get_tbl(void);
u32 config_get_tbl_sz(void);

#endif