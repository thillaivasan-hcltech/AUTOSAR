/* AUTOSAR compliant feedback_processor.h */
#ifndef FEEDBACK_PROCESSOR_H
#define FEEDBACK_PROCESSOR_H

#include "Std_Types.h"

#define FEEDBACK_PROCESSOR_SW_MAJOR_VERSION 1
#define FEEDBACK_PROCESSOR_SW_MINOR_VERSION 0
#define FEEDBACK_PROCESSOR_SW_PATCH_VERSION 0

#define FB_MAP_SIZE 8

typedef enum {
    FB_STATE_INIT = 0,
    FB_STATE_READY,
    FB_STATE_INVALID
} fb_state_t;

FUNC(Std_ReturnType, FEEDBACK_PROCESSOR_CODE) FeedbackProcessor_Init(void);
FUNC(Std_ReturnType, FEEDBACK_PROCESSOR_CODE) FeedbackProcessor_Update(uint16 adcVal);
FUNC(Std_ReturnType, FEEDBACK_PROCESSOR_CODE) FeedbackProcessor_Get(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos);

#endif /* FEEDBACK_PROCESSOR_H */
