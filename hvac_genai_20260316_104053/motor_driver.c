#include "motor_driver.h"
#include "Rte_MotorDriver.h"
#include "Det.h"
#include "Platform_Types.h"
#include "Std_Types.h"

#define MOTOR_DRIVER_MODULE_ID 104
#define MOTOR_DRIVER_VENDOR_ID 1
#define MOTOR_DRIVER_SW_MAJOR_VERSION 1
#define MOTOR_DRIVER_SW_MINOR_VERSION 0
#define MOTOR_DRIVER_SW_PATCH_VERSION 0

#define MOTOR_DRIVER_INSTANCE_ID 0
#define MOTOR_DRIVER_INIT_API_ID 0x01
#define MOTOR_DRIVER_DRIVE_API_ID 0x02
#define MOTOR_DRIVER_STOP_API_ID 0x03
#define MOTOR_DRIVER_STATUS_API_ID 0x04

#define MOTOR_DRIVER_DEV_ERROR_DETECT STD_ON

static boolean MotorDriver_Initialized = FALSE;

FUNC(void, MOTOR_DRIVER_CODE) MotorDriver_Init(P2CONST(MotorDriver_ConfigType, AUTOMATIC, RTE_APPL_CONST) ConfigPtr) {
    if (ConfigPtr == NULL_PTR) {
        #if (MOTOR_DRIVER_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(MOTOR_DRIVER_MODULE_ID, MOTOR_DRIVER_INSTANCE_ID, MOTOR_DRIVER_INIT_API_ID, DET_E_PARAM_POINTER);
        #endif
        return;
    }
    MotorDriver_Initialized = TRUE;
}

FUNC(void, MOTOR_DRIVER_CODE) MotorDriver_Drive(P2VAR(MotorDriver_Type, AUTOMATIC, RTE_APPL_DATA) inst, motor_dir_t dir, boolean enable, uint8 pwm) {
    if (inst == NULL_PTR) {
        #if (MOTOR_DRIVER_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(MOTOR_DRIVER_MODULE_ID, MOTOR_DRIVER_INSTANCE_ID, MOTOR_DRIVER_DRIVE_API_ID, DET_E_PARAM_POINTER);
        #endif
        return;
    }
    if (!MotorDriver_Initialized) {
        #if (MOTOR_DRIVER_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(MOTOR_DRIVER_MODULE_ID, MOTOR_DRIVER_INSTANCE_ID, MOTOR_DRIVER_DRIVE_API_ID, DET_E_UNINIT);
        #endif
        return;
    }
    // Drive logic
}

FUNC(void, MOTOR_DRIVER_CODE) MotorDriver_Stop(P2VAR(MotorDriver_Type, AUTOMATIC, RTE_APPL_DATA) inst) {
    if (inst == NULL_PTR) {
        #if (MOTOR_DRIVER_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(MOTOR_DRIVER_MODULE_ID, MOTOR_DRIVER_INSTANCE_ID, MOTOR_DRIVER_STOP_API_ID, DET_E_PARAM_POINTER);
        #endif
        return;
    }
    if (!MotorDriver_Initialized) {
        #if (MOTOR_DRIVER_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(MOTOR_DRIVER_MODULE_ID, MOTOR_DRIVER_INSTANCE_ID, MOTOR_DRIVER_STOP_API_ID, DET_E_UNINIT);
        #endif
        return;
    }
    // Stop logic
}

FUNC(Std_ReturnType, MOTOR_DRIVER_CODE) MotorDriver_Status(P2CONST(MotorDriver_Type, AUTOMATIC, RTE_APPL_DATA) inst) {
    if (inst == NULL_PTR) {
        #if (MOTOR_DRIVER_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(MOTOR_DRIVER_MODULE_ID, MOTOR_DRIVER_INSTANCE_ID, MOTOR_DRIVER_STATUS_API_ID, DET_E_PARAM_POINTER);
        #endif
        return E_NOT_OK;
    }
    if (!MotorDriver_Initialized) {
        #if (MOTOR_DRIVER_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(MOTOR_DRIVER_MODULE_ID, MOTOR_DRIVER_INSTANCE_ID, MOTOR_DRIVER_STATUS_API_ID, DET_E_UNINIT);
        #endif
        return E_NOT_OK;
    }
    // Status logic
    return E_OK;
}
