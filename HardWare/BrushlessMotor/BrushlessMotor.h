#ifndef __BrushlessMotor_H__
#define __BrushlessMotor_H__

#include "stm32f1xx_hal.h"

void com_closeloop(void);
void com_readVoltage(void);
void com_setAbsAngle(int32_t ang1,int32_t ang2);
void com_setRelAngle(int32_t ang1,int32_t ang2);
void com_PVTcommand(int32_t ang1, uint16_t vel1, uint8_t per1,int32_t ang2, uint16_t vel2, uint8_t per2);
void BrushlessMotor_Init(void);
#endif /* __BrushlessMotor_H__ */
