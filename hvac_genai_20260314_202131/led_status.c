#include "led_status.h"
#include "Rte_LedStatus.h"
#include "Std_Types.h"

#define LED_STATUS_START_SEC_CODE
#include "LedStatus_MemMap.h"

static VAR(uint8, LED_STATUS_VAR) LedStatus_StateBits = 0U;

FUNC(Std_ReturnType, LED_STATUS_CODE) LedStatus_Init(void)
{
    LedStatus_StateBits = 0U;
    return E_OK;
}

FUNC(Std_ReturnType, LED_STATUS_CODE) LedStatus_SetPosition(uint8 pos)
{
    LedStatus_StateBits = 1U << (pos & 0x07U);
    return E_OK;
}

FUNC(Std_ReturnType, LED_STATUS_CODE) LedStatus_PowerOk(void)
{
    LedStatus_StateBits |= 0x80U;
    return E_OK;
}

FUNC(Std_ReturnType, LED_STATUS_CODE) LedStatus_Error(void)
{
    LedStatus_StateBits = 0xFFU;
    return E_OK;
}

#define LED_STATUS_STOP_SEC_CODE
#include "LedStatus_MemMap.h"
