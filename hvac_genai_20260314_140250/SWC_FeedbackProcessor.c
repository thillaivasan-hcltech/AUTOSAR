/* AUTOSAR SWC for Feedback Processor */
#include "Rte_FeedbackProcessor.h"

void Rte_Runnable_FeedbackProcessor_Init(void) {
    feedback_processor_init();
}

void Rte_Runnable_FeedbackProcessor_Update(void) {
    feedback_processor_update();
}

void Rte_Runnable_FeedbackProcessor_Get(void) {
    feedback_processor_get();
}
