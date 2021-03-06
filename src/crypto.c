/**
 * Punch BOOT
 *
 * Copyright (C) 2018 Jonas Blixt <jonpe960@gmail.com>
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */

#include <pb.h>
#include <crypto.h>

extern const uint8_t no_of_keys;
extern const struct pb_key keys[];

uint32_t pb_crypto_get_key(uint32_t key_index, struct pb_key **key)
{
    if (key_index >= no_of_keys)
        return PB_ERR;

    (*key) = (struct pb_key *) &keys[key_index];

    return PB_OK;
}

uint32_t pb_crypto_init(struct pb_crypto_backend *backend)
{
    UNUSED(backend);
    return PB_OK;
}
