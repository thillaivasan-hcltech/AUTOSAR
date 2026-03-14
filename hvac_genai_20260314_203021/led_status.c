/* AUTOSAR compliant led_status.c */
#include "led_status.h"
#include "Rte_LedStatus.h"
#include "Platform_Types.h"
#include "Std_Types.h"

#define LED_STATUS_START_SEC_CODE
#include "LedStatus_MemMap.h"

static VAR(uint8, LED_STATUS_VAR) stateBits = 0U;

FUNC(Std_ReturnType, LED_STATUS_CODE) LedStatus_Init(void) {
    stateBits = 0U;
    return E_OK;
}

FUNC(Std_ReturnType, LED_STATUS_CODE) LedStatus_SetPosition(uint8 pos) {
    stateBits = 1U << (pos & 0x07U);
    return E_OK;
}

FUNC(Std_ReturnType, LED_STATUS_CODE) LedStatus_PowerOk(void) {
    stateBits |= 0x80U;
    return E_OK;
}

FUNC(Std_ReturnType, LED_STATUS_CODE) LedStatus_Error(void) {
    stateBits = 0xFFU;
    return E_OK;
}

#define LED_STATUS_STOP_SEC_CODE
#include "LedStatus_MemMap.h"
