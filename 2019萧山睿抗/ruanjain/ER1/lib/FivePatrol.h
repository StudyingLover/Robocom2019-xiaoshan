#ifndef _FivePatrol_H_
#define _FivePatrol_H_

#include "System.h"

//三光电巡线
class FivePatrol
{
public:
	void Init(PORT ml, PORT mr, PORT g1, PORT g2, PORT g3, PORT g4, PORT g5, u16 t1, u16 t2, u16 t3, u16 t4, u16 t5, bool isBeep = false);

	void Motor_Control(double sl, double sr);
	void Gray_BatchRead();

	//                        调整1      运行时间
	void Get_Gray_hreshold(double ratio, u32 time);


	//                   速度          调整1         调整2        前冲距离      
	void Case_black_Stop(double speed, double adj1, double adj2, double lengh, bool isStop = true);

	//               速度          调整1         调整2      
	void Patrol_Line(double speed, double adj1, double adj2, double Ratio = 100);

	//                       速度          调整1         调整2        前冲距离   
	void Encoder_Patrol_Line(double speed, double adj1, double adj2, double lengh);


	void Turn_Right(double Pre_turn_time, double speed);

	void Turn_Custom(double Pre_turn_time, double speedl, double speedr, double grayNum);

	void Turn_Left(double Pre_turn_time, double speed);

	void Encoder_Go(double speed, double code, bool isStop = true);

	void Choice();

	u16 t[5];

private:
	PORT ml;
	PORT mr;
	PORT g[5];

	u16 v[5];
	u8 flag = 0;
	bool isBeep;

};

extern FivePatrol fivePatrol;











#endif















