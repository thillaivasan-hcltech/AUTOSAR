/* AUTOSAR System Initialization SWC */
#include "Rte_SystemInit.h"

void SystemInit_Init(void)
{
    /* Initialize the HVAC system context */
    hvac_context_t ctx;
    uint8_t initial_pos = 0;
    system_init(&ctx, initial_pos);
}
