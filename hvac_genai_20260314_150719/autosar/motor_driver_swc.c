#include "Rte_MotorDriver.h"

void MotorDriver_Init(void)
{
    Rte_Write_MotorDriver_Enabled(false);
    Rte_Write_MotorDriver_Direction(MOTOR_DIR_STOP);
    Rte_Write_MotorDriver_PwmDuty(0U);
}

void MotorDrive(void)
{
    motor_dir_t dir;
    bool enable;
    uint8_t pwm;
    Rte_Read_MotorDriver_Direction(&dir);
    Rte_Read_MotorDriver_Enable(&enable);
    Rte_Read_MotorDriver_PwmDuty(&pwm);
    Rte_Write_MotorDriver_Enabled(enable);
    Rte_Write_MotorDriver_Direction(dir);
    Rte_Write_MotorDriver_PwmDuty(pwm);
}

void MotorStop(void)
{
    Rte_Write_MotorDriver_Enabled(false);
    Rte_Write_MotorDriver_Direction(MOTOR_DIR_STOP);
    Rte_Write_MotorDriver_PwmDuty(0U);
}
