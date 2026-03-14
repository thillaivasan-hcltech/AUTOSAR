#include "MotorDriver.h"
#include "Rte_MotorDriver.h"
#include "Std_Types.h"
#include "Platform_Types.h"

#define MOTORDRIVER_START_SEC_CODE
#include "MotorDriver_MemMap.h"

static boolean enabled = FALSE;
static motor_dir_t dir = MOTOR_DIR_STOP;
static uint8 pwmDuty = 0U;

FUNC(void, MOTORDRIVER_CODE) MotorDriver_Init(void)
{
    enabled = FALSE;
    dir = MOTOR_DIR_STOP;
    pwmDuty = 0U;
}

FUNC(void, MOTORDRIVER_CODE) MotorDrive(motor_dir_t direction, boolean enable, uint8 pwm)
{
    dir = direction;
    enabled = enable;
    pwmDuty = pwm;
    /* OUTPUT ACTION: set GPIO/PWM as required */
}

FUNC(void, MOTORDRIVER_CODE) MotorStop(void)
{
    enabled = FALSE;
    dir = MOTOR_DIR_STOP;
    pwmDuty = 0U;
    /* OUTPUT ACTION: All outputs off */
}

FUNC(boolean, MOTORDRIVER_CODE) MotorDriver_Status(void)
{
    return enabled;
}

#define MOTORDRIVER_STOP_SEC_CODE
#include "MotorDriver_MemMap.h"
