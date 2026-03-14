#include "Rte_FeedbackProcessor.h"

void FeedbackProcessor_Init(void)
{
    Rte_Write_FeedbackProcessor_AdcSample(0U);
    Rte_Write_FeedbackProcessor_Position(0U);
    Rte_Write_FeedbackProcessor_Valid(false);
    Rte_Write_FeedbackProcessor_State(FB_STATE_INIT);
}

void FeedbackProcessor_Update(void)
{
    uint16_t adc_val;
    Rte_Read_FeedbackProcessor_AdcValue(&adc_val);
    bool found = false;
    const uint16_t feedback_map_adc[FB_MAP_SIZE] = {0, 500, 1000, 1500, 2000, 2500, 3000, 3500};
    const uint8_t feedback_map_pos[FB_MAP_SIZE] = {0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0};
    for (unsigned int i = 0U; i < FB_MAP_SIZE; ++i) {
        if (adc_val < feedback_map_adc[i]) {
            Rte_Write_FeedbackProcessor_Position(feedback_map_pos[i]);
            found = true;
            break;
        }
    }
    if (!found) {
        Rte_Write_FeedbackProcessor_Position(feedback_map_pos[FB_MAP_SIZE - 1]);
    }
    Rte_Write_FeedbackProcessor_AdcSample(adc_val);
    bool valid = (adc_val < 4096);
    Rte_Write_FeedbackProcessor_Valid(valid);
    Rte_Write_FeedbackProcessor_State(valid ? FB_STATE_READY : FB_STATE_INVALID);
}
