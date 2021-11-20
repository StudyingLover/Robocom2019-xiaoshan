#ifndef _ThreePatrol_H_
#define _ThreePatrol_H_

#include "System.h"

//�����Ѳ��
class ThreePatrol
{
public:
    void Init(PORT ml, PORT mr, PORT g1, PORT g2, PORT g3, u16 t1, u16 t2, u16 t3, bool isBeep = false);

    void Motor_Control(double sl, double sr);
    void Gray_BatchRead();

    //                        ����1      ����ʱ��
    void Get_Gray_hreshold(double ratio, u32 time);


    //                   �ٶ�          ����1         ����2        ǰ�����      
    void Case_black_Stop(double speed, double adj1, double adj2, double lengh);

    //               �ٶ�          ����1         ����2      
    void Patrol_Line(double speed, double adj1, double adj2, double Ratio = 100);

    //                       �ٶ�          ����1         ����2        ǰ�����   
    void Encoder_Patrol_Line(double speed, double adj1, double adj2, double lengh);


    void Turn_Right(double Pre_turn_time, double speed);

    void Turn_Left(double Pre_turn_time, double speed);


    u16 t[3];

private:
    PORT ml;
    PORT mr;
    PORT g[3];
    
    u16 v[3];
    u8 flag = 0;
    bool isBeep;

};

extern ThreePatrol threePatrol;











#endif















