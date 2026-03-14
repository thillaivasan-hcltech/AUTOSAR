#include "Rte_LedStatusSWC.h"

void LedStatus_Init(void)
{
    Rte_Write_LedStatusSWC_StateBits(0U);
}

void LedStatus_SetPosition(void)
{
    uint8_t pos;
    Rte_Read_LedStatusSWC_Position(&pos);
    Rte_Write_LedStatusSWC_StateBits(1U << (pos >> 5));
}

void LedStatus_PowerOk(void)
{
    uint8_t state_bits;
    Rte_Read_LedStatusSWC_StateBits(&state_bits);
    Rte_Write_LedStatusSWC_StateBits(state_bits | 0x80U);
}

void LedStatus_Error(void)
{
    Rte_Write_LedStatusSWC_StateBits(0xFFU);
}
