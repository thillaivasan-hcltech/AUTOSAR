#include "Rte_MotorDriverSWC.h"

void MotorDriverSWC_Init(void)
{
    Rte_IWrite_MotorDriverSWC_Enabled(FALSE);
    Rte_IWrite_MotorDriverSWC_Dir(MOTOR_DIR_STOP);
    Rte_IWrite_MotorDriverSWC_PwmDuty(0U);
}

void MotorDriverSWC_Drive(MotorDirType dir, boolean enable, uint8 pwm)
{
    Rte_IWrite_MotorDriverSWC_Dir(dir);
    Rte_IWrite_MotorDriverSWC_Enabled(enable);
    Rte_IWrite_MotorDriverSWC_PwmDuty(pwm);
    /* OUTPUT ACTION: set GPIO/PWM as required */
}

void MotorDriverSWC_Stop(void)
{
    Rte_IWrite_MotorDriverSWC_Enabled(FALSE);
    Rte_IWrite_MotorDriverSWC_Dir(MOTOR_DIR_STOP);
    Rte_IWrite_MotorDriverSWC_PwmDuty(0U);
    /* OUTPUT ACTION: All outputs off */
}

boolean MotorDriverSWC_Status(void)
{
    boolean enabled;
    Rte_IRead_MotorDriverSWC_Enabled(&enabled);
    return enabled;
}
