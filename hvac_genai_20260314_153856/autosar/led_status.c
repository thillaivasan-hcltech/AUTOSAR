#include "led_status.h"
#include "Rte_LedStatus.h"
#include "Std_Types.h"
#include "Platform_Types.h"

#define LED_STATUS_START_SEC_CODE
#include "LedStatus_MemMap.h"

FUNC(Std_ReturnType, LED_STATUS_CODE) LedStatus_Init(void)
{
    Std_ReturnType ret = E_OK;
    /* Initialize internal state */
    static uint8 stateBits = 0U;
    return ret;
}

FUNC(Std_ReturnType, LED_STATUS_CODE) LedStatus_SetPosition(uint8 pos)
{
    Std_ReturnType ret = E_OK;
    /* One-hot encoding: Only one bit is set based on valid pos value */
    stateBits = 1U << (pos >> 5);
    return ret;
}

FUNC(Std_ReturnType, LED_STATUS_CODE) LedStatus_PowerOk(void)
{
    Std_ReturnType ret = E_OK;
    stateBits |= 0x80U; /* MSB Power LED indication */
    return ret;
}

FUNC(Std_ReturnType, LED_STATUS_CODE) LedStatus_Error(void)
{
    Std_ReturnType ret = E_OK;
    stateBits = 0xFFU; /* All on == FAULT */
    return ret;
}

#define LED_STATUS_STOP_SEC_CODE
#include "LedStatus_MemMap.h"
