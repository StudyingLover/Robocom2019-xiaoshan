#pragma once

#include "DEVICE.H"
#include "system.H"
#define TEST_LED_PIN 49
class TEST_LED : public DEVICE
{
public:
	void setTestLed(bool);
};

extern TEST_LED TestLed;