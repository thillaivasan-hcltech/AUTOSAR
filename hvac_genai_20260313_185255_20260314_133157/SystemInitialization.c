/* AUTOSAR System Initialization Module */
#include "system_init.h"

void SystemInitialization_Init(void) {
    // Initialize system components
    CommandParser_Init();
    FlapControl_Init();
    MotorDriver_Init();
    FeedbackProcessor_Init();
    LEDStatus_Init();
}
