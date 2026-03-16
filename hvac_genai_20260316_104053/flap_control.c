#include "flap_control.h"
#include "Rte_FlapControl.h"
#include "Det.h"
#include "Platform_Types.h"
#include "Std_Types.h"

#define FLAP_CONTROL_MODULE_ID 102
#define FLAP_CONTROL_VENDOR_ID 1
#define FLAP_CONTROL_SW_MAJOR_VERSION 1
#define FLAP_CONTROL_SW_MINOR_VERSION 0
#define FLAP_CONTROL_SW_PATCH_VERSION 0

#define FLAP_CONTROL_INSTANCE_ID 0
#define FLAP_CONTROL_INIT_API_ID 0x01
#define FLAP_CONTROL_UPDATE_API_ID 0x02

#define FLAP_CONTROL_DEV_ERROR_DETECT STD_ON

static boolean FlapControl_Initialized = FALSE;

FUNC(void, FLAP_CONTROL_CODE) FlapControl_Init(P2CONST(FlapControl_ConfigType, AUTOMATIC, RTE_APPL_CONST) ConfigPtr) {
    if (ConfigPtr == NULL_PTR) {
        #if (FLAP_CONTROL_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(FLAP_CONTROL_MODULE_ID, FLAP_CONTROL_INSTANCE_ID, FLAP_CONTROL_INIT_API_ID, DET_E_PARAM_POINTER);
        #endif
        return;
    }
    FlapControl_Initialized = TRUE;
}

FUNC(Std_ReturnType, FLAP_CONTROL_CODE) FlapControl_Update(P2VAR(FlapControl_Type, AUTOMATIC, RTE_APPL_DATA) inst, uint8 cmd_pos, boolean cmd_valid, uint8 fb_pos, boolean fb_valid) {
    if (inst == NULL_PTR) {
        #if (FLAP_CONTROL_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(FLAP_CONTROL_MODULE_ID, FLAP_CONTROL_INSTANCE_ID, FLAP_CONTROL_UPDATE_API_ID, DET_E_PARAM_POINTER);
        #endif
        return E_NOT_OK;
    }
    if (!FlapControl_Initialized) {
        #if (FLAP_CONTROL_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(FLAP_CONTROL_MODULE_ID, FLAP_CONTROL_INSTANCE_ID, FLAP_CONTROL_UPDATE_API_ID, DET_E_UNINIT);
        #endif
        return E_NOT_OK;
    }
    // Update logic
    return E_OK;
}
