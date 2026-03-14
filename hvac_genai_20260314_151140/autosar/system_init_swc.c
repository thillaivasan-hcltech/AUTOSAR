#include "Rte_SystemInitSWC.h"

void System_Init(uint8 initial_pos) {
    CommandParser_Init();
    FeedbackProcessor_Init();
    FlapControl_Init(initial_pos);
    MotorDriver_Init();
    LedStatus_Init();
    LedStatus_PowerOk();
}
