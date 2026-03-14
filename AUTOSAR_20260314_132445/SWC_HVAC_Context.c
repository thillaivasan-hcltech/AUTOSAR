/* AUTOSAR SWC for HVAC Context */
#include "Rte_HVAC_Context.h"

void HVAC_Context_Init(void) {
    // Initialize components
    Rte_Call_CommandParser_Init();
    Rte_Call_FlapControl_Init();
    Rte_Call_MotorDriver_Init();
    Rte_Call_FeedbackProcessor_Init();
    Rte_Call_LEDStatus_Init();
}

void HVAC_Context_MainFunction(void) {
    // Main control loop
    if (Rte_Call_UART_ByteAvailable()) {
        uint8 command = Rte_Call_UART_Receive();
        Rte_Call_CommandParser_ProcessByte(command);
    }
    Rte_Call_FeedbackProcessor_Update();
    Rte_Call_FlapControl_Update();
    Rte_Call_LEDStatus_Update();
}
