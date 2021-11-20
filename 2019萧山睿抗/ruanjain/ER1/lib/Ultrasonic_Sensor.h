#ifndef _Ultrasonic_Sensor_H
#define _Ultrasonic_Sensor_H

class Ultrasonic_Sensor : public DEVICE
{
public:
	int16_t Get_UltrasonicValue(uint8_t addess);
};

extern Ultrasonic_Sensor Ultrasonic;

#endif
