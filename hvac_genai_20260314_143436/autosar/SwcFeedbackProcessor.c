/* AUTOSAR SWC for Feedback Processor */
#include "Rte_SwcFeedbackProcessor.h"

const uint16_t feedbackMapAdc[FB_MAP_SIZE] = {0, 500, 1000, 1500, 2000, 2500, 3000, 3500};
const uint8_t feedbackMapPos[FB_MAP_SIZE] = {0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0};

void SwcFeedbackProcessor_Init(void)
{
    Rte_Write_AdcSample(0U);
    Rte_Write_Position(0U);
    Rte_Write_FeedbackValid(FALSE);
    Rte_Write_FeedbackState(FB_STATE_INIT);
}

void SwcFeedbackProcessor_Update(void)
{
    uint16_t adcVal;
    uint8_t position = 0U;
    boolean found = FALSE;
    Rte_Read_AdcValue(&adcVal);
    for (unsigned int i = 0U; i < FB_MAP_SIZE; ++i) {
        if (adcVal < feedbackMapAdc[i]) {
            position = feedbackMapPos[i];
            found = TRUE;
            break;
        }
    }
    if (!found) {
        position = feedbackMapPos[FB_MAP_SIZE - 1];
    }
    Rte_Write_AdcSample(adcVal);
    Rte_Write_Position(position);
    Rte_Write_FeedbackValid(adcVal < 4096);
    Rte_Write_FeedbackState(adcVal < 4096 ? FB_STATE_READY : FB_STATE_INVALID);
}

void SwcFeedbackProcessor_GetPosition(void)
{
    uint8_t position;
    boolean isValid;
    Rte_Read_FeedbackValid(&isValid);
    if (isValid) {
        Rte_Read_Position(&position);
        Rte_Write_OutputPosition(position);
    }
}