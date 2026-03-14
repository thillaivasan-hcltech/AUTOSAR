/* LedStatus.h - AUTOSAR Compliant Header */

#ifndef LEDSTATUS_H
#define LEDSTATUS_H

#include "Std_Types.h"
#include "Platform_Types.h"

#define LEDSTATUS_SW_MAJOR_VERSION 1
#define LEDSTATUS_SW_MINOR_VERSION 0
#define LEDSTATUS_SW_PATCH_VERSION 0

#define LED_POS_SIZE 8

typedef struct {
    uint8 stateBits;
} LedStatus_Type;

FUNC(Std_ReturnType, LEDSTATUS_CODE) LedStatus_Init(P2VAR(LedStatus_Type, AUTOMATIC, RTE_APPL_DATA) inst);
FUNC(Std_ReturnType, LEDSTATUS_CODE) LedStatus_SetPosition(P2VAR(LedStatus_Type, AUTOMATIC, RTE_APPL_DATA) inst, uint8 pos);
FUNC(Std_ReturnType, LEDSTATUS_CODE) LedStatus_PowerOk(P2VAR(LedStatus_Type, AUTOMATIC, RTE_APPL_DATA) inst);
FUNC(Std_ReturnType, LEDSTATUS_CODE) LedStatus_Error(P2VAR(LedStatus_Type, AUTOMATIC, RTE_APPL_DATA) inst);

#endif /* LEDSTATUS_H */
