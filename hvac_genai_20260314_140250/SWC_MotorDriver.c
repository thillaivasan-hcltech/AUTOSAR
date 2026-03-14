/* AUTOSAR SWC for Motor Driver */
#include "Rte_MotorDriver.h"

void Rte_Runnable_MotorDriver_Init(void) {
    motor_driver_init();
}

void Rte_Runnable_MotorDrive(void) {
    motor_drive();
}

void Rte_Runnable_MotorStop(void) {
    motor_stop();
}

void Rte_Runnable_MotorDriver_Status(void) {
    motor_driver_status();
}
