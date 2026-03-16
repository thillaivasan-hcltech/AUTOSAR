#ifndef FEEDBACK_PROCESSOR_H
#define FEEDBACK_PROCESSOR_H

#include "Std_Types.h"

#define FEEDBACKPROCESSOR_SW_MAJOR_VERSION 1
#define FEEDBACKPROCESSOR_SW_MINOR_VERSION 0
#define FEEDBACKPROCESSOR_SW_PATCH_VERSION 0

#define FB_MAP_SIZE 8U

typedef enum {
    FB_STATE_INIT = 0,
    FB_STATE_READY,
    FB_STATE_INVALID
} fb_state_t;

extern const uint16 feedback_map_adc[FB_MAP_SIZE];
extern const uint8 feedback_map_pos[FB_MAP_SIZE];

FUNC(Std_ReturnType, FEEDBACKPROCESSOR_CODE) FeedbackProcessor_Init(void);
FUNC(Std_ReturnType, FEEDBACKPROCESSOR_CODE) FeedbackProcessor_Update(uint16 adcVal);
FUNC(Std_ReturnType, FEEDBACKPROCESSOR_CODE) FeedbackProcessor_Get(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos);

#endif /* FEEDBACK_PROCESSOR_H */
