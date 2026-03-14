#ifndef LED_STATUS_H
#define LED_STATUS_H

#include "Std_Types.h"
#include "Platform_Types.h"

#define LED_POS_SIZE 8

FUNC(Std_ReturnType, LED_STATUS_CODE) LedStatus_Init(void);
FUNC(Std_ReturnType, LED_STATUS_CODE) LedStatus_SetPosition(uint8 pos);
FUNC(Std_ReturnType, LED_STATUS_CODE) LedStatus_PowerOk(void);
FUNC(Std_ReturnType, LED_STATUS_CODE) LedStatus_Error(void);

#endif /* LED_STATUS_H */
