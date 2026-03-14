#include "Rte_SystemInitSWC.h"

void SystemInit_Init(void)
{
    uint8_t initial_pos = 0x00U;
    Rte_Write_SystemInitSWC_InitialPosition(initial_pos);
    CommandParser_Init();
    FeedbackProcessor_Init();
    FlapControl_Init();
    MotorDriver_Init();
    LedStatus_Init();
    LedStatus_PowerOk();
}
