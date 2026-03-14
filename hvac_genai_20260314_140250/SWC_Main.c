/* AUTOSAR SWC for Main Execution Loop */
#include "Rte_Main.h"

void Rte_Runnable_Main(void) {
    // Main execution loop logic
}

void Rte_Runnable_ADCRead(void) {
    ADC_read();
}

void Rte_Runnable_UARTByteAvailable(void) {
    UART_byte_available();
}

void Rte_Runnable_UARTReceive(void) {
    UART_receive();
}
