#include "main.h"
#include "Encoder.h"
#include "gpio.h"
#include "tim.h"

void Encoder_Init(void){
HAL_TIM_Encoder_Start(&htim3,TIM_CHANNEL_ALL);
HAL_TIM_Encoder_Start(&htim1,TIM_CHANNEL_ALL);	
	__HAL_TIM_SET_COUNTER(&htim3,6000);
	__HAL_TIM_SET_COUNTER(&htim1,6000);
}

//左轮对应Tim3，为PB4，PB5引脚
//右轮对应Tim2，为PA15，PB3引脚
void Eco_GetValue(int*EcoValue,int n){
	 int LeftSpeed;
	 int RightSpeed;
	
	if(n==left_wheel){
	LeftSpeed=__HAL_TIM_GET_COUNTER(&htim3)-6000;
  __HAL_TIM_SET_COUNTER(&htim3,6000);
  *EcoValue=LeftSpeed;}
	
	if(n==right_wheel){
	RightSpeed=__HAL_TIM_GET_COUNTER(&htim1)-6000;
  __HAL_TIM_SET_COUNTER(&htim1,6000);
  *EcoValue=RightSpeed;}
}
