#include "Rte_LedStatusSWC.h"

void LedStatusSWC_Init(void)
{
    Rte_IWrite_LedStatusSWC_StateBits(0U);
}

void LedStatusSWC_SetPosition(uint8 pos)
{
    Rte_IWrite_LedStatusSWC_StateBits(1U << (pos >> 5));
}

void LedStatusSWC_PowerOk(void)
{
    uint8 stateBits;
    Rte_IRead_LedStatusSWC_StateBits(&stateBits);
    Rte_IWrite_LedStatusSWC_StateBits(stateBits | 0x80U);
}

void LedStatusSWC_Error(void)
{
    Rte_IWrite_LedStatusSWC_StateBits(0xFFU);
}
