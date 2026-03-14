#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include "Std_Types.h"

#define MOTOR_DRIVER_START_SEC_CODE
#include "motor_driver_MemMap.h"

typedef enum {
    MOTOR_DIR_STOP = 0,
    MOTOR_DIR_FWD,
    MOTOR_DIR_REV
} motor_dir_t;

typedef struct {
    boolean enabled;
    motor_dir_t dir;
    uint8 pwm_duty;
} motor_driver_t;

FUNC(Std_ReturnType, MOTOR_DRIVER_CODE) motor_driver_init(P2VAR(motor_driver_t, AUTOMATIC, RTE_APPL_DATA) inst);
FUNC(Std_ReturnType, MOTOR_DRIVER_CODE) motor_drive(P2VAR(motor_driver_t, AUTOMATIC, RTE_APPL_DATA) inst, motor_dir_t dir, boolean enable, uint8 pwm);
FUNC(Std_ReturnType, MOTOR_DRIVER_CODE) motor_stop(P2VAR(motor_driver_t, AUTOMATIC, RTE_APPL_DATA) inst);
FUNC(Std_ReturnType, MOTOR_DRIVER_CODE) motor_driver_status(P2CONST(motor_driver_t, AUTOMATIC, RTE_APPL_DATA) inst);

#define MOTOR_DRIVER_STOP_SEC_CODE
#include "motor_driver_MemMap.h"

#endif /* MOTOR_DRIVER_H */
