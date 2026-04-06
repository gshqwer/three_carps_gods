#ifndef __PID_H
#define __PID_H

#include "main.h"

typedef struct {
float errorC;//errorC当前误差
float errorL;//errorL前误差
float errorI;//errorI积分误差
float errorD;//errorD微分误差
float Setpoint;//Setpoint设定值
float Currentpoint;//Currentpoint当前值
float Outpoint;//Outpoint输出值
float Kp;
float Ki;
float Kd;	
float outMax;
float outMin;	
}PID_Control;

void PID_Main(PID_Control*PID);

#endif // __PID_H
