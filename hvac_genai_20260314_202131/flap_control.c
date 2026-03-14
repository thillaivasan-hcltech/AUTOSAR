#include "flap_control.h"
#include "Rte_FlapControl.h"
#include "Std_Types.h"

#define FLAP_CONTROL_START_SEC_CODE
#include "FlapControl_MemMap.h"

static VAR(uint8, FLAP_CONTROL_VAR) FlapControl_CurrentPosition = 0U;
static VAR(uint8, FLAP_CONTROL_VAR) FlapControl_TargetPosition = 0U;
static VAR(boolean, FLAP_CONTROL_VAR) FlapControl_InMotion = FALSE;
static VAR(flap_state_t, FLAP_CONTROL_VAR) FlapControl_State = FLAP_IDLE;

FUNC(Std_ReturnType, FLAP_CONTROL_CODE) FlapControl_Init(uint8 cur_pos)
{
    FlapControl_CurrentPosition = cur_pos;
    FlapControl_TargetPosition = cur_pos;
    FlapControl_InMotion = FALSE;
    FlapControl_State = FLAP_IDLE;
    return E_OK;
}

FUNC(Std_ReturnType, FLAP_CONTROL_CODE) FlapControl_Update(uint8 cmd_pos, boolean cmd_valid, uint8 fb_pos, boolean fb_valid)
{
    boolean start_move = FALSE;

    if (!cmd_valid || !fb_valid)
    {
        FlapControl_InMotion = FALSE;
        FlapControl_State = FLAP_FAULT;
        return E_NOT_OK;
    }

    if (cmd_pos != fb_pos)
    {
        FlapControl_TargetPosition = cmd_pos;
        FlapControl_InMotion = TRUE;
        FlapControl_State = FLAP_MOVING;
        start_move = TRUE;
    }
    else
    {
        FlapControl_InMotion = FALSE;
        FlapControl_State = FLAP_TARGET_REACHED;
    }
    FlapControl_CurrentPosition = fb_pos;
    return start_move ? E_OK : E_NOT_OK;
}

#define FLAP_CONTROL_STOP_SEC_CODE
#include "FlapControl_MemMap.h"
