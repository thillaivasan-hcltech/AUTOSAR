#include "FeedbackProcessor.h"
#include "Rte_FeedbackProcessor.h"
#include "Std_Types.h"
#include "Platform_Types.h"

#define FEEDBACKPROCESSOR_START_SEC_CODE
#include "FeedbackProcessor_MemMap.h"

static VAR(uint16, FEEDBACKPROCESSOR_VAR) FeedbackProcessor_AdcSample = 0U;
static VAR(uint8, FEEDBACKPROCESSOR_VAR) FeedbackProcessor_Position = 0U;
static VAR(boolean, FEEDBACKPROCESSOR_VAR) FeedbackProcessor_Valid = FALSE;

static CONST(uint16, FEEDBACKPROCESSOR_CONST) FeedbackMapAdc[FB_MAP_SIZE] = {0, 500, 1000, 1500, 2000, 2500, 3000, 3500};
static CONST(uint8, FEEDBACKPROCESSOR_CONST) FeedbackMapPos[FB_MAP_SIZE] = {0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0};

FUNC(Std_ReturnType, FEEDBACKPROCESSOR_CODE) FeedbackProcessor_Init(void)
{
    FeedbackProcessor_AdcSample = 0U;
    FeedbackProcessor_Position = 0U;
    FeedbackProcessor_Valid = FALSE;
    return E_OK;
}

FUNC(Std_ReturnType, FEEDBACKPROCESSOR_CODE) FeedbackProcessor_Update(uint16 adcVal)
{
    boolean found = FALSE;
    for (uint8 i = 0U; i < FB_MAP_SIZE; ++i)
    {
        if (adcVal < FeedbackMapAdc[i])
        {
            FeedbackProcessor_Position = FeedbackMapPos[i];
            found = TRUE;
            break;
        }
    }
    if (!found)
    {
        FeedbackProcessor_Position = FeedbackMapPos[FB_MAP_SIZE - 1];
    }
    FeedbackProcessor_AdcSample = adcVal;
    FeedbackProcessor_Valid = (adcVal < 4096U) ? TRUE : FALSE;
    return FeedbackProcessor_Valid ? E_OK : E_NOT_OK;
}

FUNC(Std_ReturnType, FEEDBACKPROCESSOR_CODE) FeedbackProcessor_Get(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos)
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

#define FEEDBACKPROCESSOR_STOP_SEC_CODE
#include "FeedbackProcessor_MemMap.h"
