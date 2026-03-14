/* AUTOSAR SWC for Motor Driver */
#include "Rte_SwcMotorDriver.h"

void SwcMotorDriver_Init(void)
{
    Rte_Write_MotorEnabled(FALSE);
    Rte_Write_MotorDirection(MOTOR_DIR_STOP);
    Rte_Write_MotorPwmDuty(0U);
}

void SwcMotorDriver_Drive(void)
{
    motor_dir_t dir;
    boolean enable;
    uint8_t pwm;
    Rte_Read_MotorDirection(&dir);
    Rte_Read_MotorEnable(&enable);
    Rte_Read_MotorPwmDuty(&pwm);
    /* OUTPUT ACTION: set GPIO/PWM as required */
}

void SwcMotorDriver_Stop(void)
{
    Rte_Write_MotorEnabled(FALSE);
    Rte_Write_MotorDirection(MOTOR_DIR_STOP);
    Rte_Write_MotorPwmDuty(0U);
    /* OUTPUT ACTION: All outputs off */
}

boolean SwcMotorDriver_Status(void)
{
    boolean enabled;
    Rte_Read_MotorEnabled(&enabled);
    return enabled;
}