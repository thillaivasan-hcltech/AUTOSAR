#include "feedback_processor.h"
#include "Rte_FeedbackProcessor.h"
#include "Std_Types.h"

#define FEEDBACK_PROCESSOR_START_SEC_CODE
#include "FeedbackProcessor_MemMap.h"

static VAR(uint16, FEEDBACK_PROCESSOR_VAR) FeedbackProcessor_AdcSample = 0U;
static VAR(uint8, FEEDBACK_PROCESSOR_VAR) FeedbackProcessor_Position = 0U;
static VAR(boolean, FEEDBACK_PROCESSOR_VAR) FeedbackProcessor_Valid = FALSE;
static VAR(fb_state_t, FEEDBACK_PROCESSOR_VAR) FeedbackProcessor_State = FB_STATE_INIT;

#define FEEDBACK_PROCESSOR_START_SEC_CONST_16
#include "FeedbackProcessor_MemMap.h"

static CONST(uint16, FEEDBACK_PROCESSOR_CONST) FeedbackMapAdc[FB_MAP_SIZE] = {0, 500, 1000, 1500, 2000, 2500, 3000, 3500};

#define FEEDBACK_PROCESSOR_STOP_SEC_CONST_16
#include "FeedbackProcessor_MemMap.h"

#define FEEDBACK_PROCESSOR_START_SEC_CONST_8
#include "FeedbackProcessor_MemMap.h"

static CONST(uint8, FEEDBACK_PROCESSOR_CONST) FeedbackMapPos[FB_MAP_SIZE] = {0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0};

#define FEEDBACK_PROCESSOR_STOP_SEC_CONST_8
#include "FeedbackProcessor_MemMap.h"

FUNC(Std_ReturnType, FEEDBACK_PROCESSOR_CODE) FeedbackProcessor_Init(void)
{
    FeedbackProcessor_AdcSample = 0U;
    FeedbackProcessor_Position = 0U;
    FeedbackProcessor_Valid = FALSE;
    FeedbackProcessor_State = FB_STATE_INIT;
    return E_OK;
}

FUNC(Std_ReturnType, FEEDBACK_PROCESSOR_CODE) FeedbackProcessor_Update(uint16 adc_val)
{
    boolean found = FALSE;
    for (uint8 i = 0U; i < FB_MAP_SIZE; ++i)
    {
        if (adc_val < FeedbackMapAdc[i])
        {
            FeedbackProcessor_Position = FeedbackMapPos[i];
            found = TRUE;
            break;
        }
    }
    if (!found)
    {
        FeedbackProcessor_Position = FeedbackMapPos[FB_MAP_SIZE - 1U];
    }
    FeedbackProcessor_AdcSample = adc_val;
    FeedbackProcessor_Valid = (adc_val < 4096U) ? TRUE : FALSE;
    FeedbackProcessor_State = FeedbackProcessor_Valid ? FB_STATE_READY : FB_STATE_INVALID;
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
