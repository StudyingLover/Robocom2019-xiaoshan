#ifndef _Servo_Motor_H
#define _Servo_Motor_H
#include "DEVICE.H"

class Servo_Motor : public DEVICE
{
public:
	unsigned char SetAction(unsigned char addess, float speed, float angle);
	bool GetBusy(unsigned char addess, bool isShowErr = true);
	void WaitBusy(unsigned char addess, bool isShowErr = true);
	void test();
};

extern Servo_Motor servo;

#endif