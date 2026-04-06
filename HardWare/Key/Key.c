#include "Key.h"

void Key_GetNum(uint8_t* key){
*key=0;	
if(HAL_GPIO_ReadPin(Key1_GPIO_Port,Key1_Pin)==GPIO_PIN_RESET){*key=1;}
if(HAL_GPIO_ReadPin(Key2_GPIO_Port,Key2_Pin)==GPIO_PIN_RESET){*key=2;}
if(HAL_GPIO_ReadPin(Key3_GPIO_Port,Key3_Pin)==GPIO_PIN_RESET){*key=3;}
if(HAL_GPIO_ReadPin(Key4_GPIO_Port,Key4_Pin)==GPIO_PIN_RESET){*key=4;}
}
