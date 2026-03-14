/* AUTOSAR Software Component for System Initialization */
#include "Rte_SystemInit.h"

void SystemInit_Init(void) {
    /* Initialize subsystems */
    Rte_Call_CommandParser_Init();
    Rte_Call_FlapControl_Init();
    Rte_Call_MotorDriver_Init();
    Rte_Call_FeedbackProcessor_Init();
    Rte_Call_LEDStatus_Init();
}
