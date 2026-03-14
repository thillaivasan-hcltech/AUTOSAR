#ifndef FEEDBACKPROCESSOR_H
#define FEEDBACKPROCESSOR_H

#include "Std_Types.h"
#include "Platform_Types.h"

#define FEEDBACKPROCESSOR_SW_MAJOR_VERSION 1
#define FEEDBACKPROCESSOR_SW_MINOR_VERSION 0
#define FEEDBACKPROCESSOR_SW_PATCH_VERSION 0

#define FB_MAP_SIZE 8U

typedef enum {
    FB_STATE_INIT = 0,
    FB_STATE_READY,
    FB_STATE_INVALID
} fb_state_t;

#define FEEDBACKPROCESSOR_START_SEC_CONST_16
#include "FeedbackProcessor_MemMap.h"
extern const uint16 feedback_map_adc[FB_MAP_SIZE];
#define FEEDBACKPROCESSOR_STOP_SEC_CONST_16
#include "FeedbackProcessor_MemMap.h"

#define FEEDBACKPROCESSOR_START_SEC_CONST_8
#include "FeedbackProcessor_MemMap.h"
extern const uint8 feedback_map_pos[FB_MAP_SIZE];
#define FEEDBACKPROCESSOR_STOP_SEC_CONST_8
#include "FeedbackProcessor_MemMap.h"

#define FEEDBACKPROCESSOR_START_SEC_CODE
#include "FeedbackProcessor_MemMap.h"
FUNC(Std_ReturnType, FEEDBACKPROCESSOR_CODE) FeedbackProcessor_Init(void);
FUNC(Std_ReturnType, FEEDBACKPROCESSOR_CODE) FeedbackProcessor_Update(uint16 adcVal);
FUNC(Std_ReturnType, FEEDBACKPROCESSOR_CODE) FeedbackProcessor_Get(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos);
#define FEEDBACKPROCESSOR_STOP_SEC_CODE
#include "FeedbackProcessor_MemMap.h"

#endif /* FEEDBACKPROCESSOR_H */
