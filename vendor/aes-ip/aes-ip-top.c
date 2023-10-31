#include <stdint.h>

#include "common.h"

#include "gf_256.h"
#include "masking.h"
#include "aes-ip.h"

static uint8_t rcon[10] = {
	0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36
};

void aes_ip_enc(uint8_t * ct, uint8_t * pt, uint8_t * key)
{
    int i, j;

	// Masked variables
	maskState mState, keyState;

    // IP Masking constants
	uint8_t L[n]; uint8_t L2[n*n]; 
	L[0] = 0x01;	L[1] = 0x5b;

    for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			gf256Multiply(&(L2[i*n+j]), L[i], L[j]);
	}

	// Initialize masked variables
	for(i=0;i<16;i++)
	{
		initMasks(&mState.st[i], &L[0], &L2[0]);
		initMasks(&keyState.st[i], &L[0], &L2[0]);
	}

	// Encode plaintext & key
	for(i=0; i<16; i++)
		encodeByte(&mState.st[i], pt[i]);
	for(i=0; i<16; i++)
		encodeByte(&keyState.st[i], key[i]);

	// First KeyAddition 
	for(i=0; i<16; i++)
		maskAddition(&mState.st[i], &mState.st[i], &keyState.st[i]);
		
	// Round iterations
	for(j=0; j<9; j++)
	{
		// SubBytes
		for(i=0; i<16; i++)
			sboxAES(&mState.st[i]);
				
		// ShiftRows
		shiftRowsAES(&mState); 
			
		// MixColumns
		for(i=0; i<4; i++)
			mixColumnsAES(&mState.st[4*i], &mState.st[4*i+1], &mState.st[4*i+2], &mState.st[4*i+3]);
				
		// NextRoundKey
		nextRoundKeyAES(&keyState, rcon[j]);
	
		// KeyAddition
		for(i=0; i<16; i++)
			maskAddition(&mState.st[i], &mState.st[i], &keyState.st[i]);
	}
		
	// SubBytes
	for(i=0; i<16; i++)
		sboxAES(&mState.st[i]);
			
	// ShiftRows
		shiftRowsAES(&mState);

	// NextRoundKey
		nextRoundKeyAES(&keyState, rcon[j]);
	
	// KeyAddition 
	for(i=0; i<16; i++)
		maskAddition(&mState.st[i], &mState.st[i], &keyState.st[i]);
    

	// Decode output
	for(i=0; i<16; i++)
		decodeByte(&ct[i],&mState.st[i]);
}