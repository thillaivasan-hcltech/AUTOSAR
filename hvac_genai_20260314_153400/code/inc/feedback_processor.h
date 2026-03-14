#ifndef FEEDBACK_PROCESSOR_H
#define FEEDBACK_PROCESSOR_H

#include "Std_Types.h"

#define FEEDBACK_PROCESSOR_START_SEC_CODE
#include "feedback_processor_MemMap.h"

#define FB_MAP_SIZE 8

typedef enum {
    FB_STATE_INIT = 0,
    FB_STATE_READY,
    FB_STATE_INVALID
} fb_state_t;

typedef struct {
    uint16 adc_sample;
    uint8 position;
    boolean valid;
    fb_state_t state;
} feedback_processor_t;

extern const uint16 feedback_map_adc[FB_MAP_SIZE];
extern const uint8 feedback_map_pos[FB_MAP_SIZE];

FUNC(Std_ReturnType, FEEDBACK_PROCESSOR_CODE) feedback_processor_init(P2VAR(feedback_processor_t, AUTOMATIC, RTE_APPL_DATA) inst);
FUNC(Std_ReturnType, FEEDBACK_PROCESSOR_CODE) feedback_processor_update(P2VAR(feedback_processor_t, AUTOMATIC, RTE_APPL_DATA) inst, uint16 adc_val);
FUNC(Std_ReturnType, FEEDBACK_PROCESSOR_CODE) feedback_processor_get(P2CONST(feedback_processor_t, AUTOMATIC, RTE_APPL_DATA) inst, P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos);

#define FEEDBACK_PROCESSOR_STOP_SEC_CODE
#include "feedback_processor_MemMap.h"

#endif /* FEEDBACK_PROCESSOR_H */
