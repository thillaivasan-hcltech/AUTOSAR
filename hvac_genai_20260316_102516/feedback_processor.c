#include "Rte_FeedbackProcessor.h"
#include "FeedbackProcessor_MemMap.h"

#define FEEDBACKPROCESSOR_START_SEC_CODE
#include "FeedbackProcessor_MemMap.h"

static uint16 adcSample = 0U;
static uint8 position = 0U;
static boolean valid = FALSE;
static fb_state_t state = FB_STATE_INIT;

FUNC(Std_ReturnType, FEEDBACKPROCESSOR_CODE) FeedbackProcessor_Init(void) {
    adcSample = 0U;
    position = 0U;
    valid = FALSE;
    state = FB_STATE_INIT;
    return E_OK;
}

FUNC(Std_ReturnType, FEEDBACKPROCESSOR_CODE) FeedbackProcessor_Update(uint16 adcVal) {
    boolean found = FALSE;
    uint8 i;
    for (i = 0U; i < FB_MAP_SIZE; ++i) {
        if (adcVal < feedback_map_adc[i]) {
            position = feedback_map_pos[i];
            found = TRUE;
            break;
        }
    }
    if (!found) {
        position = feedback_map_pos[FB_MAP_SIZE - 1U];
    }
    adcSample = adcVal;
    valid = (adcVal < 4096U) ? TRUE : FALSE;
    state = valid ? FB_STATE_READY : FB_STATE_INVALID;
    return valid ? E_OK : E_NOT_OK;
}

FUNC(Std_ReturnType, FEEDBACKPROCESSOR_CODE) FeedbackProcessor_Get(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos) {
    if (pos == NULL_PTR) {
        return E_NOT_OK;
    }
    if (valid) {
        *pos = position;
        return E_OK;
    }
    return E_NOT_OK;
}

#define FEEDBACKPROCESSOR_STOP_SEC_CODE
#include "FeedbackProcessor_MemMap.h"
