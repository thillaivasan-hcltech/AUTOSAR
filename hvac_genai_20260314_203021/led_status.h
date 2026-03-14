/* AUTOSAR compliant led_status.h */
#ifndef LED_STATUS_H
#define LED_STATUS_H

#include "Std_Types.h"

#define LED_STATUS_SW_MAJOR_VERSION 1
#define LED_STATUS_SW_MINOR_VERSION 0
#define LED_STATUS_SW_PATCH_VERSION 0

FUNC(Std_ReturnType, LED_STATUS_CODE) LedStatus_Init(void);
FUNC(Std_ReturnType, LED_STATUS_CODE) LedStatus_SetPosition(uint8 pos);
FUNC(Std_ReturnType, LED_STATUS_CODE) LedStatus_PowerOk(void);
FUNC(Std_ReturnType, LED_STATUS_CODE) LedStatus_Error(void);

#endif /* LED_STATUS_H */
