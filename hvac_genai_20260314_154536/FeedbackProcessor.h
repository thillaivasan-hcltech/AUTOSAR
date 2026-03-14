#ifndef FEEDBACKPROCESSOR_H
#define FEEDBACKPROCESSOR_H

#include "Std_Types.h"

#define FB_MAP_SIZE 8

typedef enum {
    FB_STATE_INIT = 0,
    FB_STATE_READY,
    FB_STATE_INVALID
} fb_state_t;

extern const uint16 feedback_map_adc[FB_MAP_SIZE];
extern const uint8 feedback_map_pos[FB_MAP_SIZE];

FUNC(void, FEEDBACKPROCESSOR_CODE) FeedbackProcessor_Init(void);
FUNC(Std_ReturnType, FEEDBACKPROCESSOR_CODE) FeedbackProcessor_Update(void);
FUNC(Std_ReturnType, FEEDBACKPROCESSOR_CODE) FeedbackProcessor_Get(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos);

#endif /* FEEDBACKPROCESSOR_H */
