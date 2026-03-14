/* LedStatus.c - AUTOSAR Compliant Source */

#include "LedStatus.h"

#define LEDSTATUS_START_SEC_CODE
#include "LedStatus_MemMap.h"

FUNC(Std_ReturnType, LEDSTATUS_CODE) LedStatus_Init(P2VAR(LedStatus_Type, AUTOMATIC, RTE_APPL_DATA) inst) {
    if (inst == NULL_PTR) {
        return E_NOT_OK;
    }
    inst->stateBits = 0U;
    return E_OK;
}

FUNC(Std_ReturnType, LEDSTATUS_CODE) LedStatus_SetPosition(P2VAR(LedStatus_Type, AUTOMATIC, RTE_APPL_DATA) inst, uint8 pos) {
    if (inst == NULL_PTR) {
        return E_NOT_OK;
    }
    inst->stateBits = 1U << (pos & 0x07U);
    return E_OK;
}

FUNC(Std_ReturnType, LEDSTATUS_CODE) LedStatus_PowerOk(P2VAR(LedStatus_Type, AUTOMATIC, RTE_APPL_DATA) inst) {
    if (inst == NULL_PTR) {
        return E_NOT_OK;
    }
    inst->stateBits |= 0x80U;
    return E_OK;
}

FUNC(Std_ReturnType, LEDSTATUS_CODE) LedStatus_Error(P2VAR(LedStatus_Type, AUTOMATIC, RTE_APPL_DATA) inst) {
    if (inst == NULL_PTR) {
        return E_NOT_OK;
    }
    inst->stateBits = 0xFFU;
    return E_OK;
}

#define LEDSTATUS_STOP_SEC_CODE
#include "LedStatus_MemMap.h"
