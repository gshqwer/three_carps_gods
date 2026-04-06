#include "Car_Task_main.h" 
#include "tim.h"

#define Encoder_T 10
#define SpeedPID_T 20
#define LocationPID_T 40
#define Key_T 10

char buffer_leftspeed[20];
char buffer_rightspeed[20];
char buffer_location[8][1];

uint8_t Car_flag=0;

int LeftEcoValue;
int RightEcoValue;
uint8_t KeyValue;

float LeftSpeed;
float RightSpeed;
uint8_t Location[8];

PID_Control LocationPID={.Setpoint=0,.outMax=2,.outMin=-2,.Kp=0.3,.Ki=0,.Kd=0.5};
PID_Control LeftSpeedPID={.Setpoint=1,.outMax=999,.outMin=-999,.Kp=3,.Ki=5,.Kd=0};
PID_Control RightSpeedPID={.Setpoint=1,.outMax=999,.outMin=-999,.Kp=3,.Ki=5,.Kd=0};

void OLED_ShowCarInfo(void){
OLED_NewFrame();
		
sprintf(buffer_leftspeed,"LeftSpeed:%.2f",(float)LeftEcoValue/Encoder_T);		
sprintf(buffer_rightspeed,"RightSpeed:%.2f",(float)RightEcoValue/Encoder_T);

for(int i=0;i<8;i++){
sprintf(buffer_location[i],"%d",Location[i]);
OLED_PrintASCIIString(i*6,23,buffer_location[i],&afont12x6,OLED_COLOR_NORMAL);	
}

OLED_PrintASCIIString(0,0,buffer_leftspeed,&afont12x6,OLED_COLOR_NORMAL);
OLED_PrintASCIIString(0,10,buffer_rightspeed,&afont12x6,OLED_COLOR_NORMAL);

OLED_ShowFrame();
}

void Car_Task_Init(void){
OLED_Init();
Encoder_Init();
Motor_Init();
Serial_Init();
HAL_TIM_Base_Start_IT(&htim4);
LeftSpeed=LeftSpeedPID.Setpoint;
RightSpeed=RightSpeedPID.Setpoint;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){ 
  if(htim==&htim4){
		static uint16_t Key_state=0;
		static uint16_t Ecoder_state=0;
		static uint16_t SpeedPID_state=0;
		static uint16_t LocationPID_state=0;
		
		Key_state++;
		Ecoder_state++;
		SpeedPID_state++;
		LocationPID_state++;
		
		if(Key_state==Key_T){Key_GetNum(&KeyValue);}
		
		if(Ecoder_state==Encoder_T){
		Ecoder_state=0;
    Eco_GetValue(&LeftEcoValue,left_wheel);
		Eco_GetValue(&RightEcoValue,right_wheel);
		}
		
		if(KeyValue==1){Car_flag=!Car_flag;}
		if(Car_flag){
		if(LocationPID_state==LocationPID_T){
		LocationPID_state=0;
		LocationPID.Currentpoint=Get_Location(Location);
		PID_Main(&LocationPID);
		LeftSpeedPID.Setpoint=LeftSpeed-LocationPID.Outpoint*2;
		RightSpeedPID.Setpoint=RightSpeed+LocationPID.Outpoint*2;				
		}
		
		if(SpeedPID_state==SpeedPID_T){
		SpeedPID_state=0;
		LeftSpeedPID.Currentpoint=(float)LeftEcoValue/Encoder_T;
		RightSpeedPID.Currentpoint=(float)RightEcoValue/Encoder_T;
		PID_Main(&LeftSpeedPID);
		PID_Main(&RightSpeedPID);
		Set_Motor(LeftSpeedPID.Outpoint,left_motor);
    Set_Motor(RightSpeedPID.Outpoint,right_motor);
		}}
		else{
		Set_Motor(0,left_motor);
    Set_Motor(0,right_motor);}
}}
