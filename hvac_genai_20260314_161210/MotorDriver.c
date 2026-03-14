#include "MotorDriver.h"
#include "Std_Types.h"
#include "Platform_Types.h"

#define MOTORDRIVER_START_SEC_CODE
#include "MotorDriver_MemMap.h"

static boolean MotorDriver_Enabled = FALSE;
static motor_dir_t MotorDriver_Dir = MOTOR_DIR_STOP;
static uint8 MotorDriver_PwmDuty = 0U;

FUNC(Std_ReturnType, MOTORDRIVER_CODE) MotorDriver_Init(void)
{
    MotorDriver_Enabled = FALSE;
    MotorDriver_Dir = MOTOR_DIR_STOP;
    MotorDriver_PwmDuty = 0U;
    return E_OK;
}

FUNC(Std_ReturnType, MOTORDRIVER_CODE) MotorDriver_Drive(motor_dir_t dir, boolean enable, uint8 pwm)
{
    MotorDriver_Dir = dir;
    MotorDriver_Enabled = enable;
    MotorDriver_PwmDuty = pwm;
    return E_OK;
}

FUNC(Std_ReturnType, MOTORDRIVER_CODE) MotorDriver_Stop(void)
{
    MotorDriver_Enabled = FALSE;
    MotorDriver_Dir = MOTOR_DIR_STOP;
    MotorDriver_PwmDuty = 0U;
    return E_OK;
}

FUNC(Std_ReturnType, MOTORDRIVER_CODE) MotorDriver_Status(P2VAR(boolean, AUTOMATIC, RTE_APPL_DATA) status)
{
    if (status == NULL_PTR) {
        return E_NOT_OK;
    }
    *status = MotorDriver_Enabled;
    return E_OK;
}

#define MOTORDRIVER_STOP_SEC_CODE
#include "MotorDriver_MemMap.h"
