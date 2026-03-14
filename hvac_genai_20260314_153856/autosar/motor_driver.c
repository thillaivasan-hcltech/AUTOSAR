#include "motor_driver.h"
#include "Rte_MotorDriver.h"
#include "Std_Types.h"
#include "Platform_Types.h"

#define MOTOR_DRIVER_START_SEC_CODE
#include "MotorDriver_MemMap.h"

FUNC(Std_ReturnType, MOTOR_DRIVER_CODE) MotorDriver_Init(void)
{
    Std_ReturnType ret = E_OK;
    /* Initialize internal state */
    static boolean enabled = FALSE;
    static motor_dir_t dir = MOTOR_DIR_STOP;
    static uint8 pwmDuty = 0U;
    return ret;
}

FUNC(Std_ReturnType, MOTOR_DRIVER_CODE) MotorDrive(motor_dir_t dir, boolean enable, uint8 pwm)
{
    Std_ReturnType ret = E_OK;
    /* Set motor direction and PWM duty cycle */
    enabled = enable;
    dir = dir;
    pwmDuty = pwm;
    return ret;
}

FUNC(Std_ReturnType, MOTOR_DRIVER_CODE) MotorStop(void)
{
    Std_ReturnType ret = E_OK;
    enabled = FALSE;
    dir = MOTOR_DIR_STOP;
    pwmDuty = 0U;
    return ret;
}

FUNC(Std_ReturnType, MOTOR_DRIVER_CODE) MotorDriver_Status(P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) status)
{
    Std_ReturnType ret = E_OK;
    *status = enabled;
    return ret;
}

#define MOTOR_DRIVER_STOP_SEC_CODE
#include "MotorDriver_MemMap.h"
