#ifndef __Motor_H
#define __Motor_H

#include "main.h" 
enum motor{left_motor,right_motor};

void Motor_Init(void);
void Set_PWM(int PWM,int n);
void Set_Motor(int pwm,int n);

#endif // __Motor_H
