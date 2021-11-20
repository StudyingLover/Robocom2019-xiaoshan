#ifndef _generalMotor_H
#define _generalMotor_H
#include "DEVICE.H"






class GeneralMotor : public DEVICE
{
public:
	unsigned char SetAction(uint8_t addess, int8_t speed, bool stop);
};

extern GeneralMotor generalMotor;

#endif



