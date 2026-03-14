#include "flap_control.h"
#include "Rte_FlapControl.h"
#include "Std_Types.h"
#include "Platform_Types.h"

#define FLAP_CONTROL_START_SEC_CODE
#include "FlapControl_MemMap.h"

FUNC(Std_ReturnType, FLAP_CONTROL_CODE) FlapControl_Init(uint8 curPos)
{
    Std_ReturnType ret = E_OK;
    /* Initialize internal state */
    static uint8 currentPosition = curPos;
    static uint8 targetPosition = curPos;
    static boolean inMotion = FALSE;
    static flap_state_t state = FLAP_IDLE;
    return ret;
}

FUNC(Std_ReturnType, FLAP_CONTROL_CODE) FlapControl_Update(uint8 cmdPos, boolean cmdValid, uint8 fbPos, boolean fbValid)
{
    Std_ReturnType ret = E_OK;
    boolean startMove = FALSE;

    if (!cmdValid || !fbValid) {
        inMotion = FALSE;
        state = FLAP_FAULT;
        ret = E_NOT_OK;
    } else if (cmdPos != fbPos) {
        targetPosition = cmdPos;
        inMotion = TRUE;
        state = FLAP_MOVING;
        startMove = TRUE;
    } else {
        inMotion = FALSE;
        state = FLAP_TARGET_REACHED;
    }
    currentPosition = fbPos;
    return ret;
}

#define FLAP_CONTROL_STOP_SEC_CODE
#include "FlapControl_MemMap.h"
