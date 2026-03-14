#include "feedback_processor.h"
#include "Rte_FeedbackProcessor.h"
#include "Platform_Types.h"
#include "Std_Types.h"

#define FEEDBACK_PROCESSOR_START_SEC_CODE
#include "FeedbackProcessor_MemMap.h"

static VAR(uint16, FEEDBACK_PROCESSOR_VAR) FeedbackProcessor_AdcSample = 0U;
static VAR(uint8, FEEDBACK_PROCESSOR_VAR) FeedbackProcessor_Position = 0U;
static VAR(boolean, FEEDBACK_PROCESSOR_VAR) FeedbackProcessor_Valid = FALSE;

FUNC(Std_ReturnType, FEEDBACK_PROCESSOR_CODE) FeedbackProcessor_Init(void)
{
    FeedbackProcessor_AdcSample = 0U;
    FeedbackProcessor_Position = 0U;
    FeedbackProcessor_Valid = FALSE;
    return E_OK;
}

FUNC(Std_ReturnType, FEEDBACK_PROCESSOR_CODE) FeedbackProcessor_Update(uint16 adc_val)
{
    static const uint16 feedback_map_adc[FB_MAP_SIZE] = {0, 500, 1000, 1500, 2000, 2500, 3000, 3500};
    static const uint8 feedback_map_pos[FB_MAP_SIZE] = {0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0};
    boolean found = FALSE;
    for (uint8 i = 0U; i < FB_MAP_SIZE; ++i)
    {
        if (adc_val < feedback_map_adc[i])
        {
            FeedbackProcessor_Position = feedback_map_pos[i];
            found = TRUE;
            break;
        }
    }
    if (!found)
    {
        FeedbackProcessor_Position = feedback_map_pos[FB_MAP_SIZE - 1];
    }
    FeedbackProcessor_AdcSample = adc_val;
    FeedbackProcessor_Valid = (adc_val < 4096U) ? TRUE : FALSE;
    return FeedbackProcessor_Valid ? E_OK : E_NOT_OK;
}

FUNC(Std_ReturnType, FEEDBACK_PROCESSOR_CODE) FeedbackProcessor_Get(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos)
{
    if (pos == NULL_PTR)
    {
        return E_NOT_OK;
    }
    if (FeedbackProcessor_Valid)
    {
        *pos = FeedbackProcessor_Position;
        return E_OK;
    }
    return E_NOT_OK;
}

#define FEEDBACK_PROCESSOR_STOP_SEC_CODE
#include "FeedbackProcessor_MemMap.h"
