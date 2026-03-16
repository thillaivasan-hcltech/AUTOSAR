#ifndef FEEDBACK_PROCESSOR_H
#define FEEDBACK_PROCESSOR_H

#include "Std_Types.h"

#define FB_MAP_SIZE 8

typedef struct {
    uint16 adc_sample;
    uint8 position;
    boolean valid;
} FeedbackProcessor_Type;

typedef struct {
    uint16 feedback_map_adc[FB_MAP_SIZE];
    uint8 feedback_map_pos[FB_MAP_SIZE];
} FeedbackProcessor_ConfigType;

FUNC(void, FEEDBACK_PROCESSOR_CODE) FeedbackProcessor_Init(P2CONST(FeedbackProcessor_ConfigType, AUTOMATIC, RTE_APPL_CONST) ConfigPtr);
FUNC(Std_ReturnType, FEEDBACK_PROCESSOR_CODE) FeedbackProcessor_Update(P2VAR(FeedbackProcessor_Type, AUTOMATIC, RTE_APPL_DATA) inst, uint16 adc_val);
FUNC(Std_ReturnType, FEEDBACK_PROCESSOR_CODE) FeedbackProcessor_Get(P2CONST(FeedbackProcessor_Type, AUTOMATIC, RTE_APPL_DATA) inst, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos);

#endif /* FEEDBACK_PROCESSOR_H */
