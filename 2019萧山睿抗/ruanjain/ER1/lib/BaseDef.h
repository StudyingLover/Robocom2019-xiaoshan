#ifndef _BASEDEF_H
#define _BASEDEF_H
#include "stdint.h"

typedef int8_t                  S8;  //!< 8-bit signed integer.
typedef uint8_t                 U8;  //!< 8-bit unsigned integer.
typedef int16_t                 S16;  //!< 16-bit signed integer.
typedef uint16_t                U16;  //!< 16-bit unsigned integer.
typedef int8_t                  s8;  //!< 8-bit signed integer.
typedef uint8_t                 u8;  //!< 8-bit unsigned integer.
typedef int16_t                 s16;  //!< 16-bit signed integer.
typedef uint16_t                u16;  //!< 16-bit unsigned integer.
typedef uint16_t                le16_t;
typedef uint16_t                be16_t;
typedef int32_t                 S32;  //!< 32-bit signed integer.
typedef uint32_t                U32;  //!< 32-bit unsigned integer.
typedef int32_t                 s32;  //!< 32-bit signed integer.
typedef uint32_t                u32;  //!< 32-bit unsigned integer.
typedef uint32_t                le32_t;
typedef uint32_t                be32_t;
typedef int64_t                 S64;  //!< 64-bit signed integer.
typedef uint64_t                U64;  //!< 64-bit unsigned integer.
typedef float                   F32;  //!< 32-bit floating-point number.
typedef double                  F64;  //!< 64-bit floating-point number.
typedef uint32_t                iram_size_t;



typedef s32     int32;
typedef u32    uint32;
typedef s8      int8;
typedef u8     uint8;
typedef s16     int16;
typedef u16    uint16;

#define Min(a, b)           (((a) < (b)) ?  (a) : (b))
#define Max(a, b)           (((a) > (b)) ?  (a) : (b))


typedef struct
{
	uint32_t bit0 : 1;
	uint32_t bit1 : 1;
	uint32_t bit2 : 1;
	uint32_t bit3 : 1;
	uint32_t bit4 : 1;
	uint32_t bit5 : 1;
	uint32_t bit6 : 1;
	uint32_t bit7 : 1;
	uint32_t bit8 : 1;
	uint32_t bit9 : 1;
	uint32_t bit10 : 1;
	uint32_t bit11 : 1;
	uint32_t bit12 : 1;
	uint32_t bit13 : 1;
	uint32_t bit14 : 1;
	uint32_t bit15 : 1;
	uint32_t bit16 : 1;
	uint32_t bit17 : 1;
	uint32_t bit18 : 1;
	uint32_t bit19 : 1;
	uint32_t bit20 : 1;
	uint32_t bit21 : 1;
	uint32_t bit22 : 1;
	uint32_t bit23 : 1;
	uint32_t bit24 : 1;
	uint32_t bit25 : 1;
	uint32_t bit26 : 1;
	uint32_t bit27 : 1;
	uint32_t bit28 : 1;
	uint32_t bit29 : 1;
	uint32_t bit30 : 1;
	uint32_t bit31 : 1;
}BIT;



#endif

