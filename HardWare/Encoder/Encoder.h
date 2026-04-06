#ifndef __Encoder_H
#define __Encoder_H

#include "main.h"

enum motor_wheel{left_wheel,right_wheel};

void Encoder_Init(void);
void Eco_GetValue(int*EcoValue,int n);

#endif // __Encoder_H
