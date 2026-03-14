/* AUTOSAR Motor Control Component Implementation */
#include "Rte_MotorDriver.h"

void MotorDriver_Drive(void)
{
    /* Drive motor based on control logic */
    Rte_Write_MotorControl_Direction(MOTOR_FORWARD);
}

void MotorDriver_Stop(void)
{
    /* Stop motor operation */
    Rte_Write_MotorControl_Direction(MOTOR_STOP);
}
