#include "Rte_SystemInitSWC.h"

void SystemInitSWC_Init(uint8 initial_pos)
{
    CommandParserSWC_Init();
    FeedbackProcessorSWC_Init();
    FlapControlSWC_Init(initial_pos);
    MotorDriverSWC_Init();
    LedStatusSWC_Init();
    LedStatusSWC_PowerOk();
}
