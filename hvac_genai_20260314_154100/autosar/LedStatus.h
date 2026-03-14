#ifndef LEDSTATUS_H
#define LEDSTATUS_H

#include "Std_Types.h"

FUNC(void, LEDSTATUS_CODE) LedStatus_Init(void);
FUNC(void, LEDSTATUS_CODE) LedStatus_SetPosition(uint8 pos);
FUNC(void, LEDSTATUS_CODE) LedStatus_PowerOk(void);
FUNC(void, LEDSTATUS_CODE) LedStatus_Error(void);

#endif /* LEDSTATUS_H */
