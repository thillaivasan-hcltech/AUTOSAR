#ifndef LEDSTATUS_H
#define LEDSTATUS_H

#include "Std_Types.h"

#define LEDSTATUS_SW_MAJOR_VERSION 1U
#define LEDSTATUS_SW_MINOR_VERSION 0U
#define LEDSTATUS_SW_PATCH_VERSION 0U

FUNC(Std_ReturnType, LEDSTATUS_CODE) LedStatus_Init(void);
FUNC(Std_ReturnType, LEDSTATUS_CODE) LedStatus_SetPosition(uint8 pos);
FUNC(Std_ReturnType, LEDSTATUS_CODE) LedStatus_PowerOk(void);
FUNC(Std_ReturnType, LEDSTATUS_CODE) LedStatus_Error(void);

#endif /* LEDSTATUS_H */
