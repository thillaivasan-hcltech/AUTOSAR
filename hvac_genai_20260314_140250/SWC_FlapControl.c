/* AUTOSAR SWC for Flap Control */
#include "Rte_FlapControl.h"

void Rte_Runnable_FlapControl_Init(void) {
    flap_control_init();
}

void Rte_Runnable_FlapControl_Update(void) {
    flap_control_update();
}
