#include "feedback_processor.h"
#include "Rte_FeedbackProcessor.h"
#include "Det.h"
#include "Platform_Types.h"
#include "Std_Types.h"

#define FEEDBACK_PROCESSOR_MODULE_ID 101
#define FEEDBACK_PROCESSOR_VENDOR_ID 1
#define FEEDBACK_PROCESSOR_SW_MAJOR_VERSION 1
#define FEEDBACK_PROCESSOR_SW_MINOR_VERSION 0
#define FEEDBACK_PROCESSOR_SW_PATCH_VERSION 0

#define FEEDBACK_PROCESSOR_INSTANCE_ID 0
#define FEEDBACK_PROCESSOR_INIT_API_ID 0x01
#define FEEDBACK_PROCESSOR_UPDATE_API_ID 0x02
#define FEEDBACK_PROCESSOR_GET_API_ID 0x03

#define FEEDBACK_PROCESSOR_DEV_ERROR_DETECT STD_ON

static boolean FeedbackProcessor_Initialized = FALSE;

FUNC(void, FEEDBACK_PROCESSOR_CODE) FeedbackProcessor_Init(P2CONST(FeedbackProcessor_ConfigType, AUTOMATIC, RTE_APPL_CONST) ConfigPtr) {
    if (ConfigPtr == NULL_PTR) {
        #if (FEEDBACK_PROCESSOR_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(FEEDBACK_PROCESSOR_MODULE_ID, FEEDBACK_PROCESSOR_INSTANCE_ID, FEEDBACK_PROCESSOR_INIT_API_ID, DET_E_PARAM_POINTER);
        #endif
        return;
    }
    FeedbackProcessor_Initialized = TRUE;
}

FUNC(Std_ReturnType, FEEDBACK_PROCESSOR_CODE) FeedbackProcessor_Update(P2VAR(FeedbackProcessor_Type, AUTOMATIC, RTE_APPL_DATA) inst, uint16 adc_val) {
    if (inst == NULL_PTR) {
        #if (FEEDBACK_PROCESSOR_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(FEEDBACK_PROCESSOR_MODULE_ID, FEEDBACK_PROCESSOR_INSTANCE_ID, FEEDBACK_PROCESSOR_UPDATE_API_ID, DET_E_PARAM_POINTER);
        #endif
        return E_NOT_OK;
    }
    if (!FeedbackProcessor_Initialized) {
        #if (FEEDBACK_PROCESSOR_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(FEEDBACK_PROCESSOR_MODULE_ID, FEEDBACK_PROCESSOR_INSTANCE_ID, FEEDBACK_PROCESSOR_UPDATE_API_ID, DET_E_UNINIT);
        #endif
        return E_NOT_OK;
    }
    // Update logic
    return E_OK;
}

FUNC(Std_ReturnType, FEEDBACK_PROCESSOR_CODE) FeedbackProcessor_Get(P2CONST(FeedbackProcessor_Type, AUTOMATIC, RTE_APPL_DATA) inst, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos) {
    if (inst == NULL_PTR || pos == NULL_PTR) {
        #if (FEEDBACK_PROCESSOR_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(FEEDBACK_PROCESSOR_MODULE_ID, FEEDBACK_PROCESSOR_INSTANCE_ID, FEEDBACK_PROCESSOR_GET_API_ID, DET_E_PARAM_POINTER);
        #endif
        return E_NOT_OK;
    }
    if (!FeedbackProcessor_Initialized) {
        #if (FEEDBACK_PROCESSOR_DEV_ERROR_DETECT == STD_ON)
        Det_ReportError(FEEDBACK_PROCESSOR_MODULE_ID, FEEDBACK_PROCESSOR_INSTANCE_ID, FEEDBACK_PROCESSOR_GET_API_ID, DET_E_UNINIT);
        #endif
        return E_NOT_OK;
    }
    // Get logic
    return E_OK;
}
