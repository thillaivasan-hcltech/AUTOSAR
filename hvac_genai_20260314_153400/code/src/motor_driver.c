#include "motor_driver.h"

#define MOTOR_DRIVER_START_SEC_CODE
#include "motor_driver_MemMap.h"

FUNC(Std_ReturnType, MOTOR_DRIVER_CODE) motor_driver_init(P2VAR(motor_driver_t, AUTOMATIC, RTE_APPL_DATA) inst) {
    if (inst == NULL) { return E_NOT_OK; }
    inst->enabled = FALSE;
    inst->dir = MOTOR_DIR_STOP;
    inst->pwm_duty = 0U;
    return E_OK;
}

FUNC(Std_ReturnType, MOTOR_DRIVER_CODE) motor_drive(P2VAR(motor_driver_t, AUTOMATIC, RTE_APPL_DATA) inst, motor_dir_t dir, boolean enable, uint8 pwm) {
    if (inst == NULL) { return E_NOT_OK; }
    inst->dir = dir;
    inst->enabled = enable;
    inst->pwm_duty = pwm;
    return E_OK;
}

FUNC(Std_ReturnType, MOTOR_DRIVER_CODE) motor_stop(P2VAR(motor_driver_t, AUTOMATIC, RTE_APPL_DATA) inst) {
    if (inst == NULL) { return E_NOT_OK; }
    inst->enabled = FALSE;
    inst->dir = MOTOR_DIR_STOP;
    inst->pwm_duty = 0U;
    return E_OK;
}

FUNC(Std_ReturnType, MOTOR_DRIVER_CODE) motor_driver_status(P2CONST(motor_driver_t, AUTOMATIC, RTE_APPL_DATA) inst) {
    if (inst == NULL) { return E_NOT_OK; }
    return inst->enabled ? E_OK : E_NOT_OK;
}

#define MOTOR_DRIVER_STOP_SEC_CODE
#include "motor_driver_MemMap.h"
