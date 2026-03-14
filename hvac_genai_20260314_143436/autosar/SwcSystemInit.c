/* AUTOSAR SWC for System Initialization */
#include "Rte_SwcSystemInit.h"

void SwcSystemInit_Init(void)
{
    uint8_t initialPos = 0x00U;
    Rte_Write_InitialPosition(initialPos);
    SwcCommandParser_Init();
    SwcFeedbackProcessor_Init();
    SwcFlapControl_Init();
    SwcMotorDriver_Init();
    SwcLedStatus_Init();
    SwcLedStatus_PowerOk();
}