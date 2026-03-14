#include "Rte_MotorDriverSWC.h"

void MotorDriver_Init(void) {
    Rte_IWrite_MotorDriverSWC_MotorDriver_Init_enabled(FALSE);
    Rte_IWrite_MotorDriverSWC_MotorDriver_Init_dir(MOTOR_DIR_STOP);
    Rte_IWrite_MotorDriverSWC_MotorDriver_Init_pwmDuty(0U);
}

void Motor_Drive(motor_dir_t dir, boolean enable, uint8 pwm) {
    Rte_IWrite_MotorDriverSWC_Motor_Drive_dir(dir);
    Rte_IWrite_MotorDriverSWC_Motor_Drive_enabled(enable);
    Rte_IWrite_MotorDriverSWC_Motor_Drive_pwmDuty(pwm);
    /* OUTPUT ACTION: set GPIO/PWM as required */
}

void Motor_Stop(void) {
    Rte_IWrite_MotorDriverSWC_Motor_Stop_enabled(FALSE);
    Rte_IWrite_MotorDriverSWC_Motor_Stop_dir(MOTOR_DIR_STOP);
    Rte_IWrite_MotorDriverSWC_Motor_Stop_pwmDuty(0U);
    /* OUTPUT ACTION: All outputs off */
}

boolean MotorDriver_Status(void) {
    boolean enabled = FALSE;
    Rte_IRead_MotorDriverSWC_MotorDriver_Status_enabled(&enabled);
    return enabled;
}
