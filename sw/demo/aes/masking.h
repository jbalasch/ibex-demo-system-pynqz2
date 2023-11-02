#ifndef MASKING_H
#define MASKING_H

#include <stdint.h>
#include "common.h"

void initMasks(mask * mval, uint8_t * L, uint8_t * L2);
void copyMasks(mask * mout, mask * min);

void refreshMask(mask * mout, mask * min);
void refreshArrays(uint8_t * Lout, uint8_t * Rout, uint8_t * Lin, uint8_t * Rin, int size);

void halfEncode(mask * mval, uint8_t val);
void encodeByte(mask * mval, uint8_t val);
void decodeByte(uint8_t * val, mask * mval);

void maskAddition(mask * out, mask * op1, mask * op2);
void maskSquaring(mask * out, mask * op);
void maskSquaring2(mask * out, mask * op);
void maskSquaring4(mask * out, mask * op);
void maskMultiplication(mask * out, mask * op1, mask * op2);
void maskMultiplication2(mask * out, mask * op1, mask * op2);
void maskMultConst(mask * out, mask * op1, uint8_t op2);
void maskAddConst(mask * mval, mask * op1, uint8_t val);

#endif