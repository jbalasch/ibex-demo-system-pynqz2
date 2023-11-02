
#ifndef AES_IP_H
#define AES_IP_H

#include <stdint.h>
#include "common.h"

void sboxAES(mask * mval);
void shiftRowsAES(maskState * mval);
void mixColumnsAES(mask * st0, mask * st1, mask * st2, mask * st3);
void nextRoundKeyAES(maskState * mval, uint8_t rcon);

#endif