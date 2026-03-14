/* FeedbackProcessor.h - AUTOSAR Compliant Header */

#ifndef FEEDBACKPROCESSOR_H
#define FEEDBACKPROCESSOR_H

#include "Std_Types.h"
#include "Platform_Types.h"

#define FEEDBACKPROCESSOR_SW_MAJOR_VERSION 1
#define FEEDBACKPROCESSOR_SW_MINOR_VERSION 0
#define FEEDBACKPROCESSOR_SW_PATCH_VERSION 0

#define FB_MAP_SIZE 8

typedef enum {
    FB_STATE_INIT = 0,
    FB_STATE_READY,
    FB_STATE_INVALID
} FeedbackProcessor_StateType;

typedef struct {
    uint16 adcSample;
    uint8 position;
    boolean valid;
    FeedbackProcessor_StateType state;
} FeedbackProcessor_Type;

FUNC(Std_ReturnType, FEEDBACKPROCESSOR_CODE) FeedbackProcessor_Init(P2VAR(FeedbackProcessor_Type, AUTOMATIC, RTE_APPL_DATA) inst);
FUNC(Std_ReturnType, FEEDBACKPROCESSOR_CODE) FeedbackProcessor_Update(P2VAR(FeedbackProcessor_Type, AUTOMATIC, RTE_APPL_DATA) inst, uint16 adcVal);
FUNC(Std_ReturnType, FEEDBACKPROCESSOR_CODE) FeedbackProcessor_Get(P2CONST(FeedbackProcessor_Type, AUTOMATIC, RTE_APPL_DATA) inst, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos);

#endif /* FEEDBACKPROCESSOR_H */
