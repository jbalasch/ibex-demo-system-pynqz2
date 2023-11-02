#ifndef COMMON_H
#define COMMON_H

/* Security parameter */
#define n 2

/* Hardware acceleration */
#define HW_ACCEL 0

typedef unsigned char uint8_t;

typedef struct {
   uint8_t	L[n];
   uint8_t	R[n];
   uint8_t L2[2*n];
} mask;

typedef struct {
   mask 	st[16];
} maskState;

#endif