#include "Rte_MotorDriverSWC.h"

#define MOTOR_DRIVER_SWC_START_SEC_CODE
#include "MotorDriverSWC_MemMap.h"

FUNC(Std_ReturnType, MOTOR_DRIVER_SWC_CODE) MotorDriverSWC_Init(void)
{
    /* Local static instance for state management */
    static motor_driver_t motorDriverInstance;
    motor_driver_init(&motorDriverInstance);
    return E_OK;
}

FUNC(Std_ReturnType, MOTOR_DRIVER_SWC_CODE) MotorDriverSWC_Drive(void)
{
    Std_ReturnType ret;
    uint8 direction, pwmDuty;
    boolean enable;
    static motor_driver_t motorDriverInstance;

    ret = Rte_Read_MotorDriverSWC_Direction(&direction);
    if (ret != E_OK) {
        return E_NOT_OK;
    }

    ret = Rte_Read_MotorDriverSWC_Enable(&enable);
    if (ret != E_OK) {
        return E_NOT_OK;
    }

    ret = Rte_Read_MotorDriverSWC_PWMDuty(&pwmDuty);
    if (ret != E_OK) {
        return E_NOT_OK;
    }

    motor_drive(&motorDriverInstance, (motor_dir_t)direction, enable, pwmDuty);
    return E_OK;
}

FUNC(Std_ReturnType, MOTOR_DRIVER_SWC_CODE) MotorDriverSWC_Stop(void)
{
    static motor_driver_t motorDriverInstance;
    motor_stop(&motorDriverInstance);
    return E_OK;
}

#define MOTOR_DRIVER_SWC_STOP_SEC_CODE
#include "MotorDriverSWC_MemMap.h"
