/* AUTOSAR compliant feedback_processor.c */
#include "feedback_processor.h"
#include "Rte_FeedbackProcessor.h"
#include "Platform_Types.h"
#include "Std_Types.h"

#define FEEDBACK_PROCESSOR_START_SEC_CODE
#include "FeedbackProcessor_MemMap.h"

static VAR(uint16, FEEDBACK_PROCESSOR_VAR) adcSample = 0U;
static VAR(uint8, FEEDBACK_PROCESSOR_VAR) position = 0U;
static VAR(boolean, FEEDBACK_PROCESSOR_VAR) valid = FALSE;
static VAR(fb_state_t, FEEDBACK_PROCESSOR_VAR) state = FB_STATE_INIT;

FUNC(Std_ReturnType, FEEDBACK_PROCESSOR_CODE) FeedbackProcessor_Init(void) {
    adcSample = 0U;
    position = 0U;
    valid = FALSE;
    state = FB_STATE_INIT;
    return E_OK;
}

FUNC(Std_ReturnType, FEEDBACK_PROCESSOR_CODE) FeedbackProcessor_Update(uint16 adcVal) {
    static const uint16 feedbackMapAdc[FB_MAP_SIZE] = {0, 500, 1000, 1500, 2000, 2500, 3000, 3500};
    static const uint8 feedbackMapPos[FB_MAP_SIZE] = {0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0};
    boolean found = FALSE;
    for (uint8 i = 0U; i < FB_MAP_SIZE; ++i) {
        if (adcVal < feedbackMapAdc[i]) {
            position = feedbackMapPos[i];
            found = TRUE;
            break;
        }
    }
    if (!found) {
        position = feedbackMapPos[FB_MAP_SIZE - 1];
    }
    adcSample = adcVal;
    valid = (adcVal < 4096);
    state = valid ? FB_STATE_READY : FB_STATE_INVALID;
    return valid ? E_OK : E_NOT_OK;
}

FUNC(Std_ReturnType, FEEDBACK_PROCESSOR_CODE) FeedbackProcessor_Get(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos) {
    if (pos == NULL_PTR) {
        return E_NOT_OK;
    }
    if (valid) {
        *pos = position;
        return E_OK;
    }
    return E_NOT_OK;
}

#define FEEDBACK_PROCESSOR_STOP_SEC_CODE
#include "FeedbackProcessor_MemMap.h"
