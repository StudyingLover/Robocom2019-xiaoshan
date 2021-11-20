#ifndef _BEEP_H
#define _BEEP_H

#include "DEVICE.H"
#define BEEP_PIN 47
class BEEP : public DEVICE
{
public:
	void setBeep(bool);
};

extern BEEP Beep;

#endif


