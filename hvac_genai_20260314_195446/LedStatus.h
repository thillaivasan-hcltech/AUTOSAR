#ifndef LEDSTATUS_H
#define LEDSTATUS_H

#include "Std_Types.h"
#include "Platform_Types.h"

#define LEDSTATUS_SW_MAJOR_VERSION 1
#define LEDSTATUS_SW_MINOR_VERSION 0
#define LEDSTATUS_SW_PATCH_VERSION 0

#define LEDSTATUS_START_SEC_CODE
#include "LedStatus_MemMap.h"
FUNC(Std_ReturnType, LEDSTATUS_CODE) LedStatus_Init(void);
FUNC(Std_ReturnType, LEDSTATUS_CODE) LedStatus_SetPosition(uint8 pos);
FUNC(Std_ReturnType, LEDSTATUS_CODE) LedStatus_PowerOk(void);
FUNC(Std_ReturnType, LEDSTATUS_CODE) LedStatus_Error(void);
#define LEDSTATUS_STOP_SEC_CODE
#include "LedStatus_MemMap.h"

#endif /* LEDSTATUS_H */
