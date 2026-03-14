/* AUTOSAR compliant flap_control.c */
#include "flap_control.h"
#include "Rte_FlapControl.h"
#include "Platform_Types.h"
#include "Std_Types.h"

#define FLAP_CONTROL_START_SEC_CODE
#include "FlapControl_MemMap.h"

static VAR(uint8, FLAP_CONTROL_VAR) currentPosition = 0U;
static VAR(uint8, FLAP_CONTROL_VAR) targetPosition = 0U;
static VAR(boolean, FLAP_CONTROL_VAR) inMotion = FALSE;
static VAR(flap_state_t, FLAP_CONTROL_VAR) state = FLAP_IDLE;

FUNC(Std_ReturnType, FLAP_CONTROL_CODE) FlapControl_Init(uint8 curPos) {
    currentPosition = curPos;
    targetPosition = curPos;
    inMotion = FALSE;
    state = FLAP_IDLE;
    return E_OK;
}

FUNC(Std_ReturnType, FLAP_CONTROL_CODE) FlapControl_Update(uint8 cmdPos, boolean cmdValid, uint8 fbPos, boolean fbValid) {
    if (!cmdValid || !fbValid) {
        inMotion = FALSE;
        state = FLAP_FAULT;
        return E_NOT_OK;
    }

    if (cmdPos != fbPos) {
        targetPosition = cmdPos;
        inMotion = TRUE;
        state = FLAP_MOVING;
    } else {
        inMotion = FALSE;
        state = FLAP_TARGET_REACHED;
    }
    currentPosition = fbPos;
    return inMotion ? E_OK : E_NOT_OK;
}

#define FLAP_CONTROL_STOP_SEC_CODE
#include "FlapControl_MemMap.h"
