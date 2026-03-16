#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include "Std_Types.h"

typedef enum {
    MOTOR_DIR_STOP = 0,
    MOTOR_DIR_FWD,
    MOTOR_DIR_REV
} motor_dir_t;

typedef struct {
    boolean enabled;
    motor_dir_t dir;
    uint8 pwm_duty;
} MotorDriver_Type;

typedef struct {
    uint8 initial_pwm;
} MotorDriver_ConfigType;

FUNC(void, MOTOR_DRIVER_CODE) MotorDriver_Init(P2CONST(MotorDriver_ConfigType, AUTOMATIC, RTE_APPL_CONST) ConfigPtr);
FUNC(void, MOTOR_DRIVER_CODE) MotorDriver_Drive(P2VAR(MotorDriver_Type, AUTOMATIC, RTE_APPL_DATA) inst, motor_dir_t dir, boolean enable, uint8 pwm);
FUNC(void, MOTOR_DRIVER_CODE) MotorDriver_Stop(P2VAR(MotorDriver_Type, AUTOMATIC, RTE_APPL_DATA) inst);
FUNC(Std_ReturnType, MOTOR_DRIVER_CODE) MotorDriver_Status(P2CONST(MotorDriver_Type, AUTOMATIC, RTE_APPL_DATA) inst);

#endif /* MOTOR_DRIVER_H */
