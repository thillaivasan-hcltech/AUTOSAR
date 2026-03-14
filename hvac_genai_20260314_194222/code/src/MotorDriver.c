/* MotorDriver.c - AUTOSAR Compliant Source */

#include "MotorDriver.h"

#define MOTORDRIVER_START_SEC_CODE
#include "MotorDriver_MemMap.h"

FUNC(Std_ReturnType, MOTORDRIVER_CODE) MotorDriver_Init(P2VAR(MotorDriver_Type, AUTOMATIC, RTE_APPL_DATA) inst) {
    if (inst == NULL_PTR) {
        return E_NOT_OK;
    }
    inst->enabled = FALSE;
    inst->dir = MOTOR_DIR_STOP;
    inst->pwmDuty = 0U;
    return E_OK;
}

FUNC(Std_ReturnType, MOTORDRIVER_CODE) MotorDriver_Drive(P2VAR(MotorDriver_Type, AUTOMATIC, RTE_APPL_DATA) inst, MotorDriver_DirType dir, boolean enable, uint8 pwm) {
    if (inst == NULL_PTR) {
        return E_NOT_OK;
    }
    inst->dir = dir;
    inst->enabled = enable;
    inst->pwmDuty = pwm;
    /* OUTPUT ACTION: set GPIO/PWM as required */
    return E_OK;
}

FUNC(Std_ReturnType, MOTORDRIVER_CODE) MotorDriver_Stop(P2VAR(MotorDriver_Type, AUTOMATIC, RTE_APPL_DATA) inst) {
    if (inst == NULL_PTR) {
        return E_NOT_OK;
    }
    inst->enabled = FALSE;
    inst->dir = MOTOR_DIR_STOP;
    inst->pwmDuty = 0U;
    /* OUTPUT ACTION: All outputs off */
    return E_OK;
}

FUNC(Std_ReturnType, MOTORDRIVER_CODE) MotorDriver_Status(P2CONST(MotorDriver_Type, AUTOMATIC, RTE_APPL_DATA) inst) {
    if (inst == NULL_PTR) {
        return E_NOT_OK;
    }
    return (inst->enabled) ? E_OK : E_NOT_OK;
}

#define MOTORDRIVER_STOP_SEC_CODE
#include "MotorDriver_MemMap.h"
