/* AUTOSAR SWC for LED Status */
#include "Rte_LEDStatus.h"

void Rte_Runnable_LEDStatus_Init(void) {
    led_status_init();
}

void Rte_Runnable_LEDStatus_Error(void) {
    led_status_error();
}

void Rte_Runnable_LEDStatus_PowerOk(void) {
    led_status_power_ok();
}

void Rte_Runnable_LEDStatus_SetPosition(void) {
    led_status_set_position();
}
