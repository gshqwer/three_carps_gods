#include "main.h"
#include "DRV8833.h"
#include "tim.h"

void Motor_Init(void){
HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_1);
HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_2);
HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_3);
HAL_TIM_PWM_Start(&htim2,TIM_CHANNEL_4);
}

void Set_PWM(int PWM,int n){
 if(n==1){__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_1,PWM);}
 if(n==2){__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,PWM);}
 if(n==3){__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,PWM);}
 if(n==4){__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_4,PWM);}}

 //AIN1:PA0 TIM2 CH1 
 //AIN2:PA1 TIM2 CH2
 //BIN1:PA2 TIM2 CH3
 //BIN2:PA3 TIM2 CH4
 //left motor:AIN1 AIN2
 //right_moptor:BIN1 BIN2
 void Set_Motor(int pwm,int n){
 if(n==left_motor){	 
 if(pwm<0){
 Set_PWM(-pwm,1);
 Set_PWM(0,2);} 
 
 if(pwm>=0){
 Set_PWM(0,1);
 Set_PWM(pwm,2);} 
}
 
if(n==right_motor){	 
 if(pwm>=0){
 Set_PWM(pwm,3);
 Set_PWM(0,4);} 
 
 if(pwm<0){
 Set_PWM(0,3);
 Set_PWM(-pwm,4);} 
}}
 
