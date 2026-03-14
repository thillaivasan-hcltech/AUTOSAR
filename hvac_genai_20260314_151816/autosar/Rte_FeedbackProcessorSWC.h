#ifndef RTE_FEEDBACKPROCESSORSWC_H
#define RTE_FEEDBACKPROCESSORSWC_H

#include "Rte_Type.h"

#define FB_MAP_SIZE 8

typedef enum {
    FB_STATE_INIT = 0,
    FB_STATE_READY,
    FB_STATE_INVALID
} FeedbackStateType;

void FeedbackProcessorSWC_Init(void);
boolean FeedbackProcessorSWC_Update(uint16 adc_val);
boolean FeedbackProcessorSWC_Get(uint8 *pos);

#endif /* RTE_FEEDBACKPROCESSORSWC_H */
