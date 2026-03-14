#include "LedStatus.h"
#include "Rte_LedStatus.h"
#include "Std_Types.h"
#include "Platform_Types.h"

#define LEDSTATUS_START_SEC_CODE
#include "LedStatus_MemMap.h"

static uint8 stateBits = 0U;

FUNC(void, LEDSTATUS_CODE) LedStatus_Init(void)
{
    stateBits = 0U;
}

FUNC(void, LEDSTATUS_CODE) LedStatus_SetPosition(uint8 pos)
{
    stateBits = 1U << (pos >> 5);
}

FUNC(void, LEDSTATUS_CODE) LedStatus_PowerOk(void)
{
    stateBits |= 0x80U;
}

FUNC(void, LEDSTATUS_CODE) LedStatus_Error(void)
{
    stateBits = 0xFFU;
}

#define LEDSTATUS_STOP_SEC_CODE
#include "LedStatus_MemMap.h"
