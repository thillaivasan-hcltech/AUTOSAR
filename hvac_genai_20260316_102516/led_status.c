#include "Rte_LedStatus.h"
#include "LedStatus_MemMap.h"

#define LEDSTATUS_START_SEC_CODE
#include "LedStatus_MemMap.h"

static uint8 stateBits = 0U;

FUNC(Std_ReturnType, LEDSTATUS_CODE) LedStatus_Init(void) {
    stateBits = 0U;
    return E_OK;
}

FUNC(Std_ReturnType, LEDSTATUS_CODE) LedStatus_SetPosition(uint8 pos) {
    stateBits = 1U << (pos & 0x07U);
    return E_OK;
}

FUNC(Std_ReturnType, LEDSTATUS_CODE) LedStatus_PowerOk(void) {
    stateBits |= 0x80U;
    return E_OK;
}

FUNC(Std_ReturnType, LEDSTATUS_CODE) LedStatus_Error(void) {
    stateBits = 0xFFU;
    return E_OK;
}

#define LEDSTATUS_STOP_SEC_CODE
#include "LedStatus_MemMap.h"
