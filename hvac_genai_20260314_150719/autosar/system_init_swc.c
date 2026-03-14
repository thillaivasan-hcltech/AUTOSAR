#include "Rte_SystemInit.h"

void SystemInit(void)
{
    CommandParser_Init();
    FeedbackProcessor_Init();
    FlapControl_Init();
    MotorDriver_Init();
    LedStatus_Init();
    LedStatus_PowerOk();
}
