#ifndef _GESTURESENSOR_H
#define _GESTURESENSOR_H

#include "DEVICE.H"

typedef enum
{
	GESTURE_NONE,
	GESTURE_UP,
	GESTURE_DOWN,
	GESTURE_LEFT,
	GESTURE_RIGHT,
}GestureDef;




class GestureSensor : public DEVICE
{
public:
	GestureDef getGesture(u8 addess);
};

extern GestureSensor gestureSensor;


#endif

