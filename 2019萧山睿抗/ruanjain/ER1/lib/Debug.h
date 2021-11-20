#ifndef _DEBUG_H
#define _DEBUG_H

#include "Arduino.h"

class Debug : public Print
{
public:
	Debug();
	virtual size_t write(uint8_t c);
private:

};


extern Debug dbg;



#endif


