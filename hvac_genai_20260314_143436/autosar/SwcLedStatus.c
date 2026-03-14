/* AUTOSAR SWC for LED Status Management */
#include "Rte_SwcLedStatus.h"

void SwcLedStatus_Init(void)
{
    Rte_Write_LedStateBits(0U);
}

void SwcLedStatus_SetPosition(void)
{
    uint8_t pos;
    Rte_Read_CurrentPosition(&pos);
    Rte_Write_LedStateBits(1U << (pos >> 5));
}

void SwcLedStatus_PowerOk(void)
{
    uint8_t stateBits;
    Rte_Read_LedStateBits(&stateBits);
    Rte_Write_LedStateBits(stateBits | 0x80U);
}

void SwcLedStatus_Error(void)
{
    Rte_Write_LedStateBits(0xFFU);
}