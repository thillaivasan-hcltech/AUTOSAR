#include "FlapControl.h"
#include "Rte_FlapControl.h"
#include "Std_Types.h"
#include "Platform_Types.h"

#define FLAPCONTROL_START_SEC_CODE
#include "FlapControl_MemMap.h"

static uint8 currentPosition = 0U;
static uint8 targetPosition = 0U;
static boolean inMotion = FALSE;
static flap_state_t state = FLAP_IDLE;

FUNC(void, FLAPCONTROL_CODE) FlapControl_Init(void)
{
    currentPosition = 0U;
    targetPosition = 0U;
    inMotion = FALSE;
    state = FLAP_IDLE;
}

FUNC(Std_ReturnType, FLAPCONTROL_CODE) FlapControl_Update(void)
{
    Std_ReturnType ret = E_NOT_OK;
    uint8 cmdPos, fbPos;
    boolean cmdValid, fbValid;

    if (Rte_Read_rpCommandPosition(&cmdPos) == E_OK &&
        Rte_Read_rpFeedbackPosition(&fbPos) == E_OK)
    {
        cmdValid = (cmdPos != 0xFF);
        fbValid = (fbPos != 0xFF);

        if (!cmdValid || !fbValid)
        {
            inMotion = FALSE;
            state = FLAP_FAULT;
            ret = E_NOT_OK;
        }
        else if (cmdPos != fbPos)
        {
            targetPosition = cmdPos;
            inMotion = TRUE;
            state = FLAP_MOVING;
            ret = E_OK;
        }
        else
        {
            inMotion = FALSE;
            state = FLAP_TARGET_REACHED;
            ret = E_OK;
        }

        currentPosition = fbPos;
    }

    return ret;
}

#define FLAPCONTROL_STOP_SEC_CODE
#include "FlapControl_MemMap.h"
