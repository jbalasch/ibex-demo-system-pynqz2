#ifndef GF_256_H
#define GF_256_H

#include <stdint.h>
#include "common.h"

void gf256Multiply(uint8_t * res, uint8_t a, uint8_t b);
void gf256Square(uint8_t * res, uint8_t a);
void gf256Inverse(uint8_t * res, uint8_t a);

#endif