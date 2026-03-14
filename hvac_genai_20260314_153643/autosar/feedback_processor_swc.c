#include "Rte_FeedbackProcessorSWC.h"

#define FEEDBACK_PROCESSOR_SWC_START_SEC_CODE
#include "FeedbackProcessorSWC_MemMap.h"

FUNC(Std_ReturnType, FEEDBACK_PROCESSOR_SWC_CODE) FeedbackProcessorSWC_Init(void)
{
    /* Local static instance for state management */
    static feedback_processor_t feedbackProcessorInstance;
    feedback_processor_init(&feedbackProcessorInstance);
    return E_OK;
}

FUNC(Std_ReturnType, FEEDBACK_PROCESSOR_SWC_CODE) FeedbackProcessorSWC_Update(void)
{
    Std_ReturnType ret;
    uint16 adcValue;
    static feedback_processor_t feedbackProcessorInstance;

    ret = Rte_Read_FeedbackProcessorSWC_ADCValue(&adcValue);
    if (ret != E_OK) {
        return E_NOT_OK;
    }

    if (feedback_processor_update(&feedbackProcessorInstance, adcValue)) {
        return E_OK;
    }
    return E_NOT_OK;
}

FUNC(Std_ReturnType, FEEDBACK_PROCESSOR_SWC_CODE) FeedbackProcessorSWC_GetPosition(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos)
{
    static feedback_processor_t feedbackProcessorInstance;
    if (feedback_processor_get(&feedbackProcessorInstance, pos)) {
        return E_OK;
    }
    return E_NOT_OK;
}

#define FEEDBACK_PROCESSOR_SWC_STOP_SEC_CODE
#include "FeedbackProcessorSWC_MemMap.h"
