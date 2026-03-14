#include "feedback_processor.h"

#define FEEDBACK_PROCESSOR_START_SEC_CODE
#include "feedback_processor_MemMap.h"

const uint16 feedback_map_adc[FB_MAP_SIZE] = {0, 500, 1000, 1500, 2000, 2500, 3000, 3500};
const uint8 feedback_map_pos[FB_MAP_SIZE] = {0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0};

FUNC(Std_ReturnType, FEEDBACK_PROCESSOR_CODE) feedback_processor_init(P2VAR(feedback_processor_t, AUTOMATIC, RTE_APPL_DATA) inst) {
    if (inst == NULL) { return E_NOT_OK; }
    inst->adc_sample = 0U;
    inst->position = 0U;
    inst->valid = FALSE;
    inst->state = FB_STATE_INIT;
    return E_OK;
}

FUNC(Std_ReturnType, FEEDBACK_PROCESSOR_CODE) feedback_processor_update(P2VAR(feedback_processor_t, AUTOMATIC, RTE_APPL_DATA) inst, uint16 adc_val) {
    if (inst == NULL) { return E_NOT_OK; }
    boolean found = FALSE;
    for (uint8 i = 0U; i < FB_MAP_SIZE; ++i) {
        if (adc_val < feedback_map_adc[i]) {
            inst->position = feedback_map_pos[i];
            found = TRUE;
            break;
        }
    }
    if (!found) {
        inst->position = feedback_map_pos[FB_MAP_SIZE - 1];
    }
    inst->adc_sample = adc_val;
    inst->valid = (adc_val < 4096U) ? TRUE : FALSE;
    inst->state = inst->valid ? FB_STATE_READY : FB_STATE_INVALID;
    return inst->valid ? E_OK : E_NOT_OK;
}

FUNC(Std_ReturnType, FEEDBACK_PROCESSOR_CODE) feedback_processor_get(P2CONST(feedback_processor_t, AUTOMATIC, RTE_APPL_DATA) inst, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos) {
    if (inst == NULL || pos == NULL) { return E_NOT_OK; }
    if (inst->valid) {
        *pos = inst->position;
        return E_OK;
    }
    return E_NOT_OK;
}

#define FEEDBACK_PROCESSOR_STOP_SEC_CODE
#include "feedback_processor_MemMap.h"
