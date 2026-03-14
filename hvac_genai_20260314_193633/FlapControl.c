#include "FlapControl.h"
#include "Rte_FlapControl.h"
#include "Std_Types.h"
#include "Platform_Types.h"

#define FLAPCONTROL_START_SEC_CODE
#include "FlapControl_MemMap.h"

static VAR(uint8, FLAPCONTROL_VAR) FlapControl_CurrentPosition = 0U;
static VAR(uint8, FLAPCONTROL_VAR) FlapControl_TargetPosition = 0U;
static VAR(boolean, FLAPCONTROL_VAR) FlapControl_InMotion = FALSE;
static VAR(flap_state_t, FLAPCONTROL_VAR) FlapControl_State = FLAP_IDLE;

FUNC(Std_ReturnType, FLAPCONTROL_CODE) FlapControl_Init(uint8 curPos)
{
    FlapControl_CurrentPosition = curPos;
    FlapControl_TargetPosition = curPos;
    FlapControl_InMotion = FALSE;
    FlapControl_State = FLAP_IDLE;
    return E_OK;
}

FUNC(Std_ReturnType, FLAPCONTROL_CODE) FlapControl_Update(uint8 cmdPos, boolean cmdValid, uint8 fbPos, boolean fbValid)
{
    if (!cmdValid || !fbValid)
    {
        FlapControl_InMotion = FALSE;
        FlapControl_State = FLAP_FAULT;
        return E_NOT_OK;
    }

    if (cmdPos != fbPos)
    {
        FlapControl_TargetPosition = cmdPos;
        FlapControl_InMotion = TRUE;
        FlapControl_State = FLAP_MOVING;
    }
    else
    {
        FlapControl_InMotion = FALSE;
        FlapControl_State = FLAP_TARGET_REACHED;
    }
    FlapControl_CurrentPosition = fbPos;
    return E_OK;
}

#define FLAPCONTROL_STOP_SEC_CODE
#include "FlapControl_MemMap.h"
