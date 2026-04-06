#include "main.h"
#include "LineFollower.h"

float Get_Location(uint8_t* Location){
float LocationWeight[8]={-0.4,-0.3,-0.2,-0.1,0.1,0.2,0.3,0.4};	
float sum=0;

if(HAL_GPIO_ReadPin(X1_GPIO_Port,X1_Pin)==GPIO_PIN_RESET){Location[0]=0;}
if(HAL_GPIO_ReadPin(X1_GPIO_Port,X1_Pin)==GPIO_PIN_SET){Location[0]=1;}

if(HAL_GPIO_ReadPin(X2_GPIO_Port,X2_Pin)==GPIO_PIN_RESET){Location[1]=0;}
if(HAL_GPIO_ReadPin(X2_GPIO_Port,X2_Pin)==GPIO_PIN_SET){Location[1]=1;}

if(HAL_GPIO_ReadPin(X3_GPIO_Port,X3_Pin)==GPIO_PIN_RESET){Location[2]=0;}
if(HAL_GPIO_ReadPin(X3_GPIO_Port,X3_Pin)==GPIO_PIN_SET){Location[2]=1;}

if(HAL_GPIO_ReadPin(X4_GPIO_Port,X4_Pin)==GPIO_PIN_RESET){Location[3]=0;}
if(HAL_GPIO_ReadPin(X4_GPIO_Port,X4_Pin)==GPIO_PIN_SET){Location[3]=1;}

if(HAL_GPIO_ReadPin(X5_GPIO_Port,X5_Pin)==GPIO_PIN_RESET){Location[4]=0;}
if(HAL_GPIO_ReadPin(X5_GPIO_Port,X5_Pin)==GPIO_PIN_SET){Location[4]=1;}

if(HAL_GPIO_ReadPin(X6_GPIO_Port,X6_Pin)==GPIO_PIN_RESET){Location[5]=0;}
if(HAL_GPIO_ReadPin(X6_GPIO_Port,X6_Pin)==GPIO_PIN_SET){Location[5]=1;}

if(HAL_GPIO_ReadPin(X7_GPIO_Port,X7_Pin)==GPIO_PIN_RESET){Location[6]=0;}
if(HAL_GPIO_ReadPin(X7_GPIO_Port,X7_Pin)==GPIO_PIN_SET){Location[6]=1;}

if(HAL_GPIO_ReadPin(X8_GPIO_Port,X8_Pin)==GPIO_PIN_RESET){Location[7]=0;}
if(HAL_GPIO_ReadPin(X8_GPIO_Port,X8_Pin)==GPIO_PIN_SET){Location[7]=1;}

for(int i=0;i<8;i++){
sum+=Location[i]*LocationWeight[i];
}
return sum;
}
