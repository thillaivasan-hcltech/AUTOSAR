#include "feedback_processor.h"
#include "Rte_FeedbackProcessor.h"
#include "Std_Types.h"
#include "Platform_Types.h"

#define FEEDBACK_PROCESSOR_START_SEC_CODE
#include "FeedbackProcessor_MemMap.h"

FUNC(Std_ReturnType, FEEDBACK_PROCESSOR_CODE) FeedbackProcessor_Init(void)
{
    Std_ReturnType ret = E_OK;
    /* Initialize internal state */
    static uint16 adcSample = 0U;
    static uint8 position = 0U;
    static boolean valid = FALSE;
    static fb_state_t state = FB_STATE_INIT;
    return ret;
}

FUNC(Std_ReturnType, FEEDBACK_PROCESSOR_CODE) FeedbackProcessor_Update(uint16 adcVal)
{
    Std_ReturnType ret = E_OK;
    boolean found = FALSE;
    for (uint8 i = 0U; i < FB_MAP_SIZE; ++i) {
        if (adcVal < feedback_map_adc[i]) {
            position = feedback_map_pos[i];
            found = TRUE;
            break;
        }
    }
    if (!found) {
        position = feedback_map_pos[FB_MAP_SIZE - 1];
    }
    adcSample = adcVal;
    valid = (adcVal < 4096U);
    state = valid ? FB_STATE_READY : FB_STATE_INVALID;
    return ret;
}

FUNC(Std_ReturnType, FEEDBACK_PROCESSOR_CODE) FeedbackProcessor_Get(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos)
{
    Std_ReturnType ret = E_NOT_OK;
    if (valid) {
        *pos = position;
        ret = E_OK;
    }
    return ret;
}

#define FEEDBACK_PROCESSOR_STOP_SEC_CODE
#include "FeedbackProcessor_MemMap.h"
