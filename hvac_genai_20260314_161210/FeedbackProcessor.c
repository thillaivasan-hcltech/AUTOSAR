#include "FeedbackProcessor.h"
#include "Std_Types.h"
#include "Platform_Types.h"

#define FEEDBACKPROCESSOR_START_SEC_CONST_16
#include "FeedbackProcessor_MemMap.h"

static const uint16 FeedbackMapAdc[FB_MAP_SIZE] = {0, 500, 1000, 1500, 2000, 2500, 3000, 3500};

#define FEEDBACKPROCESSOR_STOP_SEC_CONST_16
#include "FeedbackProcessor_MemMap.h"

#define FEEDBACKPROCESSOR_START_SEC_CONST_8
#include "FeedbackProcessor_MemMap.h"

static const uint8 FeedbackMapPos[FB_MAP_SIZE] = {0x00, 0x20, 0x40, 0x60, 0x80, 0xA0, 0xC0, 0xE0};

#define FEEDBACKPROCESSOR_STOP_SEC_CONST_8
#include "FeedbackProcessor_MemMap.h"

#define FEEDBACKPROCESSOR_START_SEC_CODE
#include "FeedbackProcessor_MemMap.h"

static uint16 FeedbackProcessor_AdcSample = 0U;
static uint8 FeedbackProcessor_Position = 0U;
static boolean FeedbackProcessor_Valid = FALSE;
static fb_state_t FeedbackProcessor_State = FB_STATE_INIT;

FUNC(Std_ReturnType, FEEDBACKPROCESSOR_CODE) FeedbackProcessor_Init(void)
{
    FeedbackProcessor_AdcSample = 0U;
    FeedbackProcessor_Position = 0U;
    FeedbackProcessor_Valid = FALSE;
    FeedbackProcessor_State = FB_STATE_INIT;
    return E_OK;
}

FUNC(Std_ReturnType, FEEDBACKPROCESSOR_CODE) FeedbackProcessor_Update(uint16 adcVal)
{
    boolean found = FALSE;
    for (uint8 i = 0U; i < FB_MAP_SIZE; ++i) {
        if (adcVal < FeedbackMapAdc[i]) {
            FeedbackProcessor_Position = FeedbackMapPos[i];
            found = TRUE;
            break;
        }
    }
    if (!found) {
        FeedbackProcessor_Position = FeedbackMapPos[FB_MAP_SIZE - 1];
    }
    FeedbackProcessor_AdcSample = adcVal;
    FeedbackProcessor_Valid = (adcVal < 4096);
    FeedbackProcessor_State = FeedbackProcessor_Valid ? FB_STATE_READY : FB_STATE_INVALID;
    return FeedbackProcessor_Valid ? E_OK : E_NOT_OK;
}

FUNC(Std_ReturnType, FEEDBACKPROCESSOR_CODE) FeedbackProcessor_Get(P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) pos)
{
    if (pos == NULL_PTR) {
        return E_NOT_OK;
    }
    if (FeedbackProcessor_Valid) {
        *pos = FeedbackProcessor_Position;
        return E_OK;
    }
    return E_NOT_OK;
}

#define FEEDBACKPROCESSOR_STOP_SEC_CODE
#include "FeedbackProcessor_MemMap.h"
