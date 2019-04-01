#!/usr/bin/env python3
import ecdsa
import array
from hashlib import sha384
key_input = [0x20,0xf2,0xb4,0x48,0x21,0xb6,0x87,0x8a,0x35,0xe4,0x93,0x96,0xbc,0x71,0x82,0xb4,0xcb,0x27,
0xb5,0x18,0xd6,0x04,0x85,0x97,0x38,0xf4,0x98,0x4c,0x6d,0x27,0xc1,0x39,0xb1,0x4f,0xce,0x23,
0x8c,0xfb,0x09,0xc1,0x04,0x46,0x29,0x4c,0x98,0x90,0x10,0x2d,0xda,0x1f,0x0d,0x01,0x5f,0xe0,
0xb4,0x1a,0xc8,0x9a,0x3e,0x4f,0x53,0x37,0xad,0x1c,0x25,0x46,0x24,0xb3,0xf6,0xb1,0x61,0x62
,0xa2,0xe1,0x61,0x90,0x68,0xb2,0x11,0x68,0x75,0xed,0xf0,0xe1,0xa9,0x33,0x66,0x66,0xd1,0x5d,
0x4a,0x97,0x9b,0xb0,0x26,0x3d]

signature_input = [0x6a,0x1d,0xb1,0x63,0x4f,0x22,0x40,0x42,0xbf,0x96,0xf0,0x81,0x20,0x35,0xc1,0x43,0x5c,0x8f,
0x51,0x25,0xe0,0x59,0x10,0x3f,0x73,0xc8,0xdf,0xcb,0x38,0xda,0x0a,0xf4,0x4e,0x3d,0x38,0x76,
0x0b,0x5c,0x76,0xdc,0x18,0x30,0xb7,0x60,0x7b,0x25,0x01,0x6a,0x2c,0x04,0x4c,0xf2,0xe7,0x0e,
0xd1,0xad,0xc8,0x3a,0xed,0xc8,0x22,0xd6,0xdc,0x4e,0xe5,0x90,0xe4,0x33,0x69,0x75,0x90,0x07,
0x43,0x6d,0xc0,0xf8,0x69,0xab,0xa4,0xd7,0x0c,0x4a,0xe8,0xd5,0x04,0x6d,0x79,0xb1,0xe3,0x36,
0xda,0xc7,0x5f,0x50,0xb9,0x1a]

hash_input = [0xa8,0xd2,0x79,0x7f,0x8d,0xfb,0x87,0xdf,0xb0,0x06,0x69,0xc6,0xb0,0xcf,0x6d,0x9b,0x28,0xa3,0x79,
0xad,0xd5,0x49,0xc0,0x82,0xdb,0x5c,0x4e,0x9a,0x9e,0xee,0x3b,0x00,0xfb,0xa5,0x5d,0xbb,0x83,0xbb,
0x89,0xe4,0xd6,0x2b,0x3a,0x36,0xa7,0x9e,0xcf,0xa9]

# Convert input data to byte string
key_data = array.array('B')
key_data.extend(key_input)
signature_data = array.array('B')
signature_data.extend(signature_input)
hash_data = array.array('B')
hash_data.extend(hash_input)

vk = ecdsa.VerifyingKey.from_string(key_data.tostring(),
                                    curve=ecdsa.curves.NIST384p,
                                    hashfunc=sha384,
                                    validate_point=True)
r = ecdsa.util.string_to_number(signature_data.tostring()[0:48])
s = ecdsa.util.string_to_number(signature_data.tostring()[48:96])
n = ecdsa.util.string_to_number(hash_data.tostring())

sig = ecdsa.ecdsa.Signature(r,s)

print(vk.pubkey.verifies(n, sig))

