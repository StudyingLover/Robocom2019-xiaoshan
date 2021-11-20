#ifndef _SOUND_H
#define _SOUND_H
#include "DEVICE.h"
#include "Sound.h"

class Sound : public DEVICE
{
public:
	U16 getSoundPres(unsigned char addess, bool isShowErr = true);
	U16 getSoundFreq(unsigned char addess, bool isShowErr = true);
	void test();
};

extern Sound sound;

#endif