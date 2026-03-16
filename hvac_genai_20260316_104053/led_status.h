#ifndef LED_STATUS_H
#define LED_STATUS_H

#include "Std_Types.h"

#define LED_POS_SIZE 8

typedef struct {
    uint8 state_bits;
} LedStatus_Type;

typedef struct {
    uint8 initial_state;
} LedStatus_ConfigType;

FUNC(void, LED_STATUS_CODE) LedStatus_Init(P2CONST(LedStatus_ConfigType, AUTOMATIC, RTE_APPL_CONST) ConfigPtr);
FUNC(void, LED_STATUS_CODE) LedStatus_SetPosition(P2VAR(LedStatus_Type, AUTOMATIC, RTE_APPL_DATA) inst, uint8 pos);
FUNC(void, LED_STATUS_CODE) LedStatus_PowerOk(P2VAR(LedStatus_Type, AUTOMATIC, RTE_APPL_DATA) inst);
FUNC(void, LED_STATUS_CODE) LedStatus_Error(P2VAR(LedStatus_Type, AUTOMATIC, RTE_APPL_DATA) inst);

#endif /* LED_STATUS_H */
