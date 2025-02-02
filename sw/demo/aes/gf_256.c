/*
	gf_256.c
*/

#include <stdint.h>

#include "common.h"

const static uint8_t inverse[256] = {
0x00,0x01,0x8D,0xF6,0xCB,0x52,0x7B,0xD1,0xE8,0x4F,0x29,0xC0,0xB0,0xE1,0xE5,0xC7,
0x74,0xB4,0xAA,0x4B,0x99,0x2B,0x60,0x5F,0x58,0x3F,0xFD,0xCC,0xFF,0x40,0xEE,0xB2,
0x3A,0x6E,0x5A,0xF1,0x55,0x4D,0xA8,0xC9,0xC1,0x0A,0x98,0x15,0x30,0x44,0xA2,0xC2,
0x2C,0x45,0x92,0x6C,0xF3,0x39,0x66,0x42,0xF2,0x35,0x20,0x6F,0x77,0xBB,0x59,0x19,
0x1D,0xFE,0x37,0x67,0x2D,0x31,0xF5,0x69,0xA7,0x64,0xAB,0x13,0x54,0x25,0xE9,0x09,
0xED,0x5C,0x05,0xCA,0x4C,0x24,0x87,0xBF,0x18,0x3E,0x22,0xF0,0x51,0xEC,0x61,0x17,
0x16,0x5E,0xAF,0xD3,0x49,0xA6,0x36,0x43,0xF4,0x47,0x91,0xDF,0x33,0x93,0x21,0x3B,
0x79,0xB7,0x97,0x85,0x10,0xB5,0xBA,0x3C,0xB6,0x70,0xD0,0x06,0xA1,0xFA,0x81,0x82,
0x83,0x7E,0x7F,0x80,0x96,0x73,0xBE,0x56,0x9B,0x9E,0x95,0xD9,0xF7,0x02,0xB9,0xA4,
0xDE,0x6A,0x32,0x6D,0xD8,0x8A,0x84,0x72,0x2A,0x14,0x9F,0x88,0xF9,0xDC,0x89,0x9A,
0xFB,0x7C,0x2E,0xC3,0x8F,0xB8,0x65,0x48,0x26,0xC8,0x12,0x4A,0xCE,0xE7,0xD2,0x62,
0x0C,0xE0,0x1F,0xEF,0x11,0x75,0x78,0x71,0xA5,0x8E,0x76,0x3D,0xBD,0xBC,0x86,0x57,
0x0B,0x28,0x2F,0xA3,0xDA,0xD4,0xE4,0x0F,0xA9,0x27,0x53,0x04,0x1B,0xFC,0xAC,0xE6,
0x7A,0x07,0xAE,0x63,0xC5,0xDB,0xE2,0xEA,0x94,0x8B,0xC4,0xD5,0x9D,0xF8,0x90,0x6B,
0xB1,0x0D,0xD6,0xEB,0xC6,0x0E,0xCF,0xAD,0x08,0x4E,0xD7,0xE3,0x5D,0x50,0x1E,0xB3,
0x5B,0x23,0x38,0x34,0x68,0x46,0x03,0x8C,0xDD,0x9C,0x7D,0xA0,0xCD,0x1A,0x41,0x1C
};

uint8_t Logtable[256] = {   
  0,   0,  25,   1,  50,   2,  26, 198,  75, 199,  27, 104,  51, 238, 223,   3,    
100,   4, 224,  14,  52, 141, 129, 239,  76, 113,   8, 200, 248, 105,  28, 193,    
125, 194,  29, 181, 249, 185,  39, 106,  77, 228, 166, 114, 154, 201,   9, 120,    
101,  47, 138,   5,  33,  15, 225,  36,  18, 240, 130,  69,  53, 147, 218, 142,    
150, 143, 219, 189,  54, 208, 206, 148,  19,  92, 210, 241,  64,  70, 131,  56,    
102, 221, 253,  48, 191,   6, 139,  98, 179,  37, 226, 152,  34, 136, 145,  16,    
126, 110,  72, 195, 163, 182,  30,  66,  58, 107,  40,  84, 250, 133,  61, 186,    
 43, 121,  10,  21, 155, 159,  94, 202,  78, 212, 172, 229, 243, 115, 167,  87,    
175,  88, 168,  80, 244, 234, 214, 116,  79, 174, 233, 213, 231, 230, 173, 232,    
 44, 215, 117, 122, 235,  22,  11, 245,  89, 203,  95, 176, 156, 169,  81, 160,    
127,  12, 246, 111,  23, 196,  73, 236, 216,  67,  31,  45, 164, 118, 123, 183,    
204, 187,  62,  90, 251,  96, 177, 134,  59,  82, 161, 108, 170,  85,  41, 157,    
151, 178, 135, 144,  97, 190, 220, 252, 188, 149, 207, 205,  55,  63,  91, 209,    
 83,  57, 132,  60,  65, 162, 109,  71,  20,  42, 158,  93,  86, 242, 211, 171,    
 68,  17, 146, 217,  35,  32,  46, 137, 180, 124, 184,  38, 119, 153, 227, 165,    
103,  74, 237, 222, 197,  49, 254,  24,  13,  99, 140, 128, 192, 247, 112,   7,    
};   

uint8_t Alogtable[256] = {   
  1,   3,   5,  15,  17,  51,  85, 255,  26,  46, 114, 150, 161, 248,  19,  53,    
 95, 225,  56,  72, 216, 115, 149, 164, 247,   2,   6,  10,  30,  34, 102, 170,    
229,  52,  92, 228,  55,  89, 235,  38, 106, 190, 217, 112, 144, 171, 230,  49,    
 83, 245,   4,  12,  20,  60,  68, 204,  79, 209, 104, 184, 211, 110, 178, 205,    
 76, 212, 103, 169, 224,  59,  77, 215,  98, 166, 241,   8,  24,  40, 120, 136,    
131, 158, 185, 208, 107, 189, 220, 127, 129, 152, 179, 206,  73, 219, 118, 154,    
181, 196,  87, 249,  16,  48,  80, 240,  11,  29,  39, 105, 187, 214,  97, 163,    
254,  25,  43, 125, 135, 146, 173, 236,  47, 113, 147, 174, 233,  32,  96, 160,    
251,  22,  58,  78, 210, 109, 183, 194,  93, 231,  50,  86, 250,  21,  63,  65,    
195,  94, 226,  61,  71, 201,  64, 192,  91, 237,  44, 116, 156, 191, 218, 117,    
159, 186, 213, 100, 172, 239,  42, 126, 130, 157, 188, 223, 122, 142, 137, 128,    
155, 182, 193,  88, 232,  35, 101, 175, 234,  37, 111, 177, 200,  67, 197,  84,    
252,  31,  33,  99, 165, 244,   7,   9,  27,  45, 119, 153, 176, 203,  70, 202,    
 69, 207,  74, 222, 121, 139, 134, 145, 168, 227,  62,  66, 198,  81, 243,  14,    
 18,  54,  90, 238,  41, 123, 141, 140, 143, 138, 133, 148, 167, 242,  13,  23,    
 57,  75, 221, 124, 132, 151, 162, 253,  28,  36, 108, 180, 199,  82, 246,   1,    
}; 

uint8_t square[256] = {
0x00, 0x01, 0x04, 0x05, 0x10, 0x11, 0x14, 0x15,
0x40, 0x41, 0x44, 0x45, 0x50, 0x51, 0x54, 0x55,
0x1b, 0x1a, 0x1f, 0x1e, 0x0b, 0x0a, 0x0f, 0x0e,
0x5b, 0x5a, 0x5f, 0x5e, 0x4b, 0x4a, 0x4f, 0x4e,
0x6c, 0x6d, 0x68, 0x69, 0x7c, 0x7d, 0x78, 0x79,
0x2c, 0x2d, 0x28, 0x29, 0x3c, 0x3d, 0x38, 0x39,
0x77, 0x76, 0x73, 0x72, 0x67, 0x66, 0x63, 0x62,
0x37, 0x36, 0x33, 0x32, 0x27, 0x26, 0x23, 0x22,
0xab, 0xaa, 0xaf, 0xae, 0xbb, 0xba, 0xbf, 0xbe,
0xeb, 0xea, 0xef, 0xee, 0xfb, 0xfa, 0xff, 0xfe,
0xb0, 0xb1, 0xb4, 0xb5, 0xa0, 0xa1, 0xa4, 0xa5,
0xf0, 0xf1, 0xf4, 0xf5, 0xe0, 0xe1, 0xe4, 0xe5,
0xc7, 0xc6, 0xc3, 0xc2, 0xd7, 0xd6, 0xd3, 0xd2,
0x87, 0x86, 0x83, 0x82, 0x97, 0x96, 0x93, 0x92,
0xdc, 0xdd, 0xd8, 0xd9, 0xcc, 0xcd, 0xc8, 0xc9,
0x9c, 0x9d, 0x98, 0x99, 0x8c, 0x8d, 0x88, 0x89,
0x9a, 0x9b, 0x9e, 0x9f, 0x8a, 0x8b, 0x8e, 0x8f,
0xda, 0xdb, 0xde, 0xdf, 0xca, 0xcb, 0xce, 0xcf,
0x81, 0x80, 0x85, 0x84, 0x91, 0x90, 0x95, 0x94,
0xc1, 0xc0, 0xc5, 0xc4, 0xd1, 0xd0, 0xd5, 0xd4,
0xf6, 0xf7, 0xf2, 0xf3, 0xe6, 0xe7, 0xe2, 0xe3,
0xb6, 0xb7, 0xb2, 0xb3, 0xa6, 0xa7, 0xa2, 0xa3,
0xed, 0xec, 0xe9, 0xe8, 0xfd, 0xfc, 0xf9, 0xf8,
0xad, 0xac, 0xa9, 0xa8, 0xbd, 0xbc, 0xb9, 0xb8,
0x31, 0x30, 0x35, 0x34, 0x21, 0x20, 0x25, 0x24,
0x71, 0x70, 0x75, 0x74, 0x61, 0x60, 0x65, 0x64,
0x2a, 0x2b, 0x2e, 0x2f, 0x3a, 0x3b, 0x3e, 0x3f,
0x6a, 0x6b, 0x6e, 0x6f, 0x7a, 0x7b, 0x7e, 0x7f,
0x5d, 0x5c, 0x59, 0x58, 0x4d, 0x4c, 0x49, 0x48,
0x1d, 0x1c, 0x19, 0x18, 0x0d, 0x0c, 0x09, 0x08,
0x46, 0x47, 0x42, 0x43, 0x56, 0x57, 0x52, 0x53,
0x06, 0x07, 0x02, 0x03, 0x16, 0x17, 0x12, 0x13,
};

/*
void gf256Multiply(uint8_t * res, uint8_t a, uint8_t b, uint8_t red)
{
	*res = 0;
	
	while (b > 0) 
	{
		*res = (b & 0x01) ? *res ^ a : *res;
		a = (a & 0x80) ? ((a << 1) ^ red) : (a << 1);
		b >>= 1;
	}
}

*/

/*
void gf256Multiply(uint8_t * res, uint8_t a, uint8_t b)
{
	if (a && b) 
		*res = Alogtable[(Logtable[a] + Logtable[b]) %255] ;
	else *res = 0;
}
*/

void gf256Multiply(uint8_t * res, uint8_t a, uint8_t b)
{

	#if HW_ACCEL==0

		uint32_t t = 0;
		uint8_t q;
		
		// first lookups
		t = Logtable[a] + Logtable[b];
		
		// mod 255
		q = t & 0xFF;
		t = (t>>8);
		t = t + q;
		
		// second lookup
		q = Alogtable[t];
		
		// conditional return
		*res = q * ((a+0xFF)>>8) * ((b+0xFF)>>8);
	#else
		
		asm (".insn r CUSTOM_0, 0, 0, %0, %1, %2" :
       "=r"(*res) :
       "r"(a), "r"(b));

	#endif
	
}


void gf256Square(uint8_t * res, uint8_t a)
{
	*res = square[a];
}


void gf256Inverse(uint8_t * res, uint8_t a)
{
	*res = inverse[a];
}