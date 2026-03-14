/* AUTOSAR compliant motor_driver.c */
#include "motor_driver.h"
#include "Rte_MotorDriver.h"
#include "Platform_Types.h"
#include "Std_Types.h"

#define MOTOR_DRIVER_START_SEC_CODE
#include "MotorDriver_MemMap.h"

static VAR(boolean, MOTOR_DRIVER_VAR) enabled = FALSE;
static VAR(motor_dir_t, MOTOR_DRIVER_VAR) dir = MOTOR_DIR_STOP;
static VAR(uint8, MOTOR_DRIVER_VAR) pwmDuty = 0U;

FUNC(Std_ReturnType, MOTOR_DRIVER_CODE) MotorDriver_Init(void) {
    enabled = FALSE;
    dir = MOTOR_DIR_STOP;
    pwmDuty = 0U;
    return E_OK;
}

FUNC(Std_ReturnType, MOTOR_DRIVER_CODE) MotorDriver_Drive(motor_dir_t direction, boolean enable, uint8 pwm) {
    dir = direction;
    enabled = enable;
    pwmDuty = pwm;
    return E_OK;
}

FUNC(Std_ReturnType, MOTOR_DRIVER_CODE) MotorDriver_Stop(void) {
    enabled = FALSE;
    dir = MOTOR_DIR_STOP;
    pwmDuty = 0U;
    return E_OK;
}

FUNC(Std_ReturnType, MOTOR_DRIVER_CODE) MotorDriver_Status(P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) status) {
    if (status == NULL_PTR) {
        return E_NOT_OK;
    }
    *status = enabled;
    return E_OK;
}

#define MOTOR_DRIVER_STOP_SEC_CODE
#include "MotorDriver_MemMap.h"
