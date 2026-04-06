#include "main.h"
#include "PID.h"

void PID_Main(PID_Control*PID){
  PID->errorL=PID->errorC;
	PID->errorC=PID->Setpoint-PID->Currentpoint;		
	if(PID->Ki){PID->errorI+=PID->errorC;}
	else{PID->errorI=0;}			
	if(PID->errorI>PID->outMax/PID->Ki){PID->errorI=PID->outMax/PID->Ki;}
	if(PID->errorI<PID->outMin/PID->Ki){PID->errorI=PID->outMin/PID->Ki;}			
//	PID->Outpoint=PID->Kp*PID->errorC+PID->Ki*PID->errorI+(1-0.5)*PID->Kd*(PID->errorC-PID->errorL)+0.5*PID->errorD;
  PID->Outpoint=PID->Kp*PID->errorC+PID->Ki*PID->errorI+PID->Kd*(PID->errorC-PID->errorL);
	if(PID->Outpoint>PID->outMax){PID->Outpoint=PID->outMax;}
	if(PID->Outpoint<PID->outMin){PID->Outpoint=PID->outMin;}	
}
