#include "LedStatus.h"
#include "Rte_LedStatus.h"
#include "Std_Types.h"
#include "Platform_Types.h"

#define LEDSTATUS_START_SEC_CODE
#include "LedStatus_MemMap.h"

static VAR(uint8, LEDSTATUS_VAR) LedStatus_StateBits = 0U;

FUNC(Std_ReturnType, LEDSTATUS_CODE) LedStatus_Init(void)
{
    LedStatus_StateBits = 0U;
    return E_OK;
}

FUNC(Std_ReturnType, LEDSTATUS_CODE) LedStatus_SetPosition(uint8 pos)
{
    LedStatus_StateBits = 1U << (pos & 0x07U);
    return E_OK;
}

FUNC(Std_ReturnType, LEDSTATUS_CODE) LedStatus_PowerOk(void)
{
    LedStatus_StateBits |= 0x80U;
    return E_OK;
}

FUNC(Std_ReturnType, LEDSTATUS_CODE) LedStatus_Error(void)
{
    LedStatus_StateBits = 0xFFU;
    return E_OK;
}

#define LEDSTATUS_STOP_SEC_CODE
#include "LedStatus_MemMap.h"
