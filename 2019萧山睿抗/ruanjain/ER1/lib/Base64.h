#ifndef _BASE64_H
#define _BASE64_H

#include "BaseDef.h"

typedef struct
{
	u8 len;
	void* data;
} Array;


void Base64Encode(Array bindata, Array *base64);
void Base64Decode(Array *base64);
#endif
