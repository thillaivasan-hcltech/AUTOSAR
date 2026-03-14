/* FeedbackProcessor.c - AUTOSAR Compliant Source */

#include "FeedbackProcessor.h"

#define FEEDBACKPROCESSOR_START_SEC_CONST_16
#include "FeedbackProcessor_MemMap.h"

CONST(uint16, FEEDBACKPROCESSOR_CONST) FeedbackMap_Adc[FB_MAP_SIZE] = {0, 500, 1000, 1500, 2000, 2500, 3000, 3500};

#define FEEDBACKPROCESSOR_STOP_SEC_CONST_16
#include "FeedbackProcessor_MemMap.h"

#define FEEDBACKPROCESSOR_START_SEC_CONST_8
#include "FeedbackProcessor_MemMap.h"

CONST(uint8, FEEDBACKPROCESSOR_CONST) FeedbackMap_Pos[FB_MAP_SIZE] = {0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0};

#define FEEDBACKPROCESSOR_STOP_SEC_CONST_8
#include "FeedbackProcessor_MemMap.h"

#define FEEDBACKPROCESSOR_START_SEC_CODE
#include "FeedbackProcessor_MemMap.h"

FUNC(Std_ReturnType, FEEDBACKPROCESSOR_CODE) FeedbackProcessor_Init(P2VAR(FeedbackProcessor_Type, AUTOMATIC, RTE_APPL_DATA) inst) {
    if (inst == NULL_PTR) {
        return E_NOT_OK;
    }
    inst->adcSample = 0U;
    inst->position = 0U;
    inst->valid = FALSE;
    inst->state = FB_STATE_INIT;
    return E_OK;
}

FUNC(Std_ReturnType, FEEDBACKPROCESSOR_CODE) FeedbackProcessor_Update(P2VAR(FeedbackProcessor_Type, AUTOMATIC, RTE_APPL_DATA) inst, uint16 adcVal) {
    if (inst == NULL_PTR) {
        return E_NOT_OK;
    }
    boolean found = FALSE;
    for (uint8 i = 0U; i < FB_MAP_SIZE; ++i) {
        if (adcVal < FeedbackMap_Adc[i]) {
            inst->position = FeedbackMap_Pos[i];
            found = TRUE;
            break;
        }
    }
    if (!found) {
        inst->position = FeedbackMap_Pos[FB_MAP_SIZE - 1];
    }
    inst->adcSample = adcVal;
    inst->valid = (adcVal < 4096U) ? TRUE : FALSE;
    inst->state = inst->valid ? FB_STATE_READY : FB_STATE_INVALID;
    return inst->valid ? E_OK : E_NOT_OK;
}

FUNC(Std_ReturnType, FEEDBACKPROCESSOR_CODE) FeedbackProcessor_Get(P2CONST(FeedbackProcessor_Type, AUTOMATIC, RTE_APPL_DATA) inst, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos) {
    if (inst == NULL_PTR || pos == NULL_PTR) {
        return E_NOT_OK;
    }
    if (inst->valid) {
        *pos = inst->position;
        return E_OK;
    }
    return E_NOT_OK;
}

#define FEEDBACKPROCESSOR_STOP_SEC_CODE
#include "FeedbackProcessor_MemMap.h"
