#include "Rte_FeedbackProcessorSWC.h"

void FeedbackProcessor_Init(void)
{
    Rte_Write_FeedbackProcessorSWC_AdcSample(0U);
    Rte_Write_FeedbackProcessorSWC_Position(0U);
    Rte_Write_FeedbackProcessorSWC_Valid(false);
    Rte_Write_FeedbackProcessorSWC_State(FB_STATE_INIT);
}

void FeedbackProcessor_Update(void)
{
    uint16_t adc_val;
    Rte_Read_FeedbackProcessorSWC_AdcValue(&adc_val);

    const uint16_t feedback_map_adc[FB_MAP_SIZE] = {0, 500, 1000, 1500, 2000, 2500, 3000, 3500};
    const uint8_t feedback_map_pos[FB_MAP_SIZE] = {0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0};

    bool found = false;
    uint8_t position = 0U;
    for (unsigned int i = 0U; i < FB_MAP_SIZE; ++i) {
        if (adc_val < feedback_map_adc[i]) {
            position = feedback_map_pos[i];
            found = true;
            break;
        }
    }
    if (!found) {
        position = feedback_map_pos[FB_MAP_SIZE - 1];
    }

    Rte_Write_FeedbackProcessorSWC_AdcSample(adc_val);
    Rte_Write_FeedbackProcessorSWC_Position(position);
    Rte_Write_FeedbackProcessorSWC_Valid(adc_val < 4096);
    Rte_Write_FeedbackProcessorSWC_State(adc_val < 4096 ? FB_STATE_READY : FB_STATE_INVALID);
}

void FeedbackProcessor_Get(uint8_t *pos)
{
    bool valid;
    Rte_Read_FeedbackProcessorSWC_Valid(&valid);
    if (valid) {
        Rte_Read_FeedbackProcessorSWC_Position(pos);
    }
}
