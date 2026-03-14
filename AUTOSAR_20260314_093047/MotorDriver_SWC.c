/* AUTOSAR Motor Driver SWC */
#include "Rte_MotorDriver.h"

void MotorDriver_Drive(motor_dir_t dir, boolean enable, uint8_t pwm)
{
    motor_drive(&motor_driver_instance, dir, enable, pwm);
}

void MotorDriver_Stop(void)
{
    motor_stop(&motor_driver_instance);
}

Std_ReturnType MotorDriver_GetStatus(void)
{
    return motor_driver_status(&motor_driver_instance);
}
