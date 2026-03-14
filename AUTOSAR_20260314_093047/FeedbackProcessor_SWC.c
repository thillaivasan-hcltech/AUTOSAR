/* AUTOSAR Feedback Processor SWC */
#include "Rte_FeedbackProcessor.h"

void FeedbackProcessor_Update(uint16_t adc_val)
{
    feedback_processor_update(&feedback_processor_instance, adc_val);
}
