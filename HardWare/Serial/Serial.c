#include "Serial.h"
#include "usart.h"

uint8_t receivedata[50];

int fputc(int ch, FILE *f) {
    HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xffff);
    return ch;
}

void Serial_Init(void){
HAL_UARTEx_ReceiveToIdle_DMA(&huart1,receivedata,sizeof(receivedata));
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart,uint16_t Size){
   if(huart==&huart1){
  HAL_UART_Transmit_DMA(&huart1,receivedata,Size);		 
	
	HAL_UARTEx_ReceiveToIdle_DMA(&huart1,receivedata,sizeof(receivedata));
}}
