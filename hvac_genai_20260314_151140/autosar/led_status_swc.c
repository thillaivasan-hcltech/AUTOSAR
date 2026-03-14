#include "Rte_LedStatusSWC.h"

void LedStatus_Init(void) {
    Rte_IWrite_LedStatusSWC_LedStatus_Init_stateBits(0U);
}

void LedStatus_SetPosition(uint8 pos) {
    uint8 stateBits = 1U << (pos >> 5);
    Rte_IWrite_LedStatusSWC_LedStatus_SetPosition_stateBits(stateBits);
}

void LedStatus_PowerOk(void) {
    uint8 stateBits = 0;
    Rte_IRead_LedStatusSWC_LedStatus_PowerOk_stateBits(&stateBits);
    stateBits |= 0x80U;
    Rte_IWrite_LedStatusSWC_LedStatus_PowerOk_stateBits(stateBits);
}

void LedStatus_Error(void) {
    Rte_IWrite_LedStatusSWC_LedStatus_Error_stateBits(0xFFU);
}
