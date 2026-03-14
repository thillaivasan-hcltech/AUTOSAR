#include "Rte_FeedbackProcessorSWC.h"

void FeedbackProcessor_Init(void) {
    Rte_IWrite_FeedbackProcessorSWC_FeedbackProcessor_Init_adcSample(0U);
    Rte_IWrite_FeedbackProcessorSWC_FeedbackProcessor_Init_position(0U);
    Rte_IWrite_FeedbackProcessorSWC_FeedbackProcessor_Init_valid(FALSE);
    Rte_IWrite_FeedbackProcessorSWC_FeedbackProcessor_Init_state(FB_STATE_INIT);
}

boolean FeedbackProcessor_Update(uint16 adc_val) {
    boolean found = FALSE;
    uint8 position = 0U;
    const uint16 feedback_map_adc[FB_MAP_SIZE] = {0, 500, 1000, 1500, 2000, 2500, 3000, 3500};
    const uint8 feedback_map_pos[FB_MAP_SIZE] = {0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0};

    for (unsigned int i = 0U; i < FB_MAP_SIZE; ++i) {
        if (adc_val < feedback_map_adc[i]) {
            position = feedback_map_pos[i];
            found = TRUE;
            break;
        }
    }
    if (!found) {
        position = feedback_map_pos[FB_MAP_SIZE - 1];
    }

    Rte_IWrite_FeedbackProcessorSWC_FeedbackProcessor_Update_adcSample(adc_val);
    Rte_IWrite_FeedbackProcessorSWC_FeedbackProcessor_Update_position(position);
    boolean valid = (adc_val < 4096);
    Rte_IWrite_FeedbackProcessorSWC_FeedbackProcessor_Update_valid(valid);
    Rte_IWrite_FeedbackProcessorSWC_FeedbackProcessor_Update_state(valid ? FB_STATE_READY : FB_STATE_INVALID);
    return valid;
}

boolean FeedbackProcessor_Get(uint8 *pos) {
    boolean valid = FALSE;
    Rte_IRead_FeedbackProcessorSWC_FeedbackProcessor_Get_valid(&valid);
    if (valid) {
        Rte_IRead_FeedbackProcessorSWC_FeedbackProcessor_Get_position(pos);
        return TRUE;
    }
    return FALSE;
}
