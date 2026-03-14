#ifndef RTE_FEEDBACKPROCESSORSWC_H
#define RTE_FEEDBACKPROCESSORSWC_H

#include "Rte_Type.h"

#define FB_MAP_SIZE 8

typedef enum {
    FB_STATE_INIT = 0,
    FB_STATE_READY,
    FB_STATE_INVALID
} fb_state_t;

void FeedbackProcessor_Init(void);
boolean FeedbackProcessor_Update(uint16 adc_val);
boolean FeedbackProcessor_Get(uint8 *pos);

#endif /* RTE_FEEDBACKPROCESSORSWC_H */
