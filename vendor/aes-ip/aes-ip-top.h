#ifndef AES_IP_TOP_H
#define AES_IP_TOP_H

#include <stdint.h>
#include "common.h"

void aes_ip_enc(uint8_t * ct, uint8_t * pt, uint8_t * key);

#endif