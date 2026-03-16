#include "Rte_MotorDriver.h"
#include "MotorDriver_MemMap.h"

#define MOTORDRIVER_START_SEC_CODE
#include "MotorDriver_MemMap.h"

static boolean enabled = FALSE;
static motor_dir_t dir = MOTOR_DIR_STOP;
static uint8 pwmDuty = 0U;

FUNC(Std_ReturnType, MOTORDRIVER_CODE) MotorDriver_Init(void) {
    enabled = FALSE;
    dir = MOTOR_DIR_STOP;
    pwmDuty = 0U;
    return E_OK;
}

FUNC(Std_ReturnType, MOTORDRIVER_CODE) MotorDriver_Drive(motor_dir_t direction, boolean enable, uint8 pwm) {
    dir = direction;
    enabled = enable;
    pwmDuty = pwm;
    return E_OK;
}

FUNC(Std_ReturnType, MOTORDRIVER_CODE) MotorDriver_Stop(void) {
    enabled = FALSE;
    dir = MOTOR_DIR_STOP;
    pwmDuty = 0U;
    return E_OK;
}

FUNC(Std_ReturnType, MOTORDRIVER_CODE) MotorDriver_Status(P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) status) {
    if (status == NULL_PTR) {
        return E_NOT_OK;
    }
    *status = enabled;
    return E_OK;
}

#define MOTORDRIVER_STOP_SEC_CODE
#include "MotorDriver_MemMap.h"
