#include "Rte_MotorDriverSWC.h"

void MotorDriver_Init(void)
{
    Rte_Write_MotorDriverSWC_Enabled(false);
    Rte_Write_MotorDriverSWC_Direction(MOTOR_DIR_STOP);
    Rte_Write_MotorDriverSWC_PwmDuty(0U);
}

void MotorDriver_Drive(void)
{
    motor_dir_t dir;
    bool enable;
    uint8_t pwm;

    Rte_Read_MotorDriverSWC_Direction(&dir);
    Rte_Read_MotorDriverSWC_Enable(&enable);
    Rte_Read_MotorDriverSWC_PwmDuty(&pwm);

    Rte_Write_MotorDriverSWC_Enabled(enable);
    Rte_Write_MotorDriverSWC_Direction(dir);
    Rte_Write_MotorDriverSWC_PwmDuty(pwm);
}

void MotorDriver_Stop(void)
{
    Rte_Write_MotorDriverSWC_Enabled(false);
    Rte_Write_MotorDriverSWC_Direction(MOTOR_DIR_STOP);
    Rte_Write_MotorDriverSWC_PwmDuty(0U);
}

bool MotorDriver_Status(void)
{
    bool enabled;
    Rte_Read_MotorDriverSWC_Enabled(&enabled);
    return enabled;
}
