#include "led_status.h"
#include "Rte_LedStatus.h"
#include "Det.h"
#include "Platform_Types.h"
#include "Std_Types.h"

#define LED_STATUS_MODULE_ID 103
#define LED_STATUS_VENDOR_ID 1
#define LED_STATUS_SW_MAJOR_VERSION 1
#define LED_STATUS_SW_MINOR_VERSION 0
#define LED_STATUS_SW_PATCH_VERSION 0

#define LED_STATUS_INSTANCE_ID 0
#define LED_STATUS_INIT_API_ID 0x01
#define LED_STATUS_SET_POSITION_API_ID 0x02
#define LED_STATUS_POWER_OK_API_ID 0x03
#define LED_STATUS_ERROR_API_ID 0x04

#define LED_STATUS_DEV_ERROR_DETECT STD_ON

static boolean LedStatus_Initialized = FALSE;

FUNC(void, LED_STATUS_CODE) LedStatus_Init(P2CONST(LedStatus_ConfigType, AUTOMATIC, RTE_APPL_CONST) ConfigPtr) {
    if (ConfigPtr == NULL_PTR) {
        #if (LED_STATUS_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(LED_STATUS_MODULE_ID, LED_STATUS_INSTANCE_ID, LED_STATUS_INIT_API_ID, DET_E_PARAM_POINTER);
        #endif
        return;
    }
    LedStatus_Initialized = TRUE;
}

FUNC(void, LED_STATUS_CODE) LedStatus_SetPosition(P2VAR(LedStatus_Type, AUTOMATIC, RTE_APPL_DATA) inst, uint8 pos) {
    if (inst == NULL_PTR) {
        #if (LED_STATUS_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(LED_STATUS_MODULE_ID, LED_STATUS_INSTANCE_ID, LED_STATUS_SET_POSITION_API_ID, DET_E_PARAM_POINTER);
        #endif
        return;
    }
    if (!LedStatus_Initialized) {
        #if (LED_STATUS_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(LED_STATUS_MODULE_ID, LED_STATUS_INSTANCE_ID, LED_STATUS_SET_POSITION_API_ID, DET_E_UNINIT);
        #endif
        return;
    }
    // Set position logic
}

FUNC(void, LED_STATUS_CODE) LedStatus_PowerOk(P2VAR(LedStatus_Type, AUTOMATIC, RTE_APPL_DATA) inst) {
    if (inst == NULL_PTR) {
        #if (LED_STATUS_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(LED_STATUS_MODULE_ID, LED_STATUS_INSTANCE_ID, LED_STATUS_POWER_OK_API_ID, DET_E_PARAM_POINTER);
        #endif
        return;
    }
    if (!LedStatus_Initialized) {
        #if (LED_STATUS_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(LED_STATUS_MODULE_ID, LED_STATUS_INSTANCE_ID, LED_STATUS_POWER_OK_API_ID, DET_E_UNINIT);
        #endif
        return;
    }
    // Power OK logic
}

FUNC(void, LED_STATUS_CODE) LedStatus_Error(P2VAR(LedStatus_Type, AUTOMATIC, RTE_APPL_DATA) inst) {
    if (inst == NULL_PTR) {
        #if (LED_STATUS_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(LED_STATUS_MODULE_ID, LED_STATUS_INSTANCE_ID, LED_STATUS_ERROR_API_ID, DET_E_PARAM_POINTER);
        #endif
        return;
    }
    if (!LedStatus_Initialized) {
        #if (LED_STATUS_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(LED_STATUS_MODULE_ID, LED_STATUS_INSTANCE_ID, LED_STATUS_ERROR_API_ID, DET_E_UNINIT);
        #endif
        return;
    }
    // Error logic
}
