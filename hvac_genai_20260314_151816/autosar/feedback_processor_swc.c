#include "Rte_FeedbackProcessorSWC.h"

void FeedbackProcessorSWC_Init(void)
{
    Rte_IWrite_FeedbackProcessorSWC_AdcSample(0U);
    Rte_IWrite_FeedbackProcessorSWC_Position(0U);
    Rte_IWrite_FeedbackProcessorSWC_Valid(FALSE);
    Rte_IWrite_FeedbackProcessorSWC_State_FB_STATE_INIT();
}

boolean FeedbackProcessorSWC_Update(uint16 adc_val)
{
    boolean found = FALSE;
    uint8 position = 0U;
    uint16 feedbackMapAdc[FB_MAP_SIZE] = {0, 500, 1000, 1500, 2000, 2500, 3000, 3500};
    uint8 feedbackMapPos[FB_MAP_SIZE] = {0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0};
    for (uint8 i = 0; i < FB_MAP_SIZE; ++i) {
        if (adc_val < feedbackMapAdc[i]) {
            position = feedbackMapPos[i];
            found = TRUE;
            break;
        }
    }
    if (!found) {
        position = feedbackMapPos[FB_MAP_SIZE - 1];
    }
    Rte_IWrite_FeedbackProcessorSWC_AdcSample(adc_val);
    Rte_IWrite_FeedbackProcessorSWC_Position(position);
    Rte_IWrite_FeedbackProcessorSWC_Valid(adc_val < 4096);
    Rte_IWrite_FeedbackProcessorSWC_State(adc_val < 4096 ? FB_STATE_READY : FB_STATE_INVALID);
    return adc_val < 4096;
}

boolean FeedbackProcessorSWC_Get(uint8 *pos)
{
    boolean valid;
    Rte_IRead_FeedbackProcessorSWC_Valid(&valid);
    if (valid) {
        Rte_IRead_FeedbackProcessorSWC_Position(pos);
        return TRUE;
    }
    return FALSE;
}
