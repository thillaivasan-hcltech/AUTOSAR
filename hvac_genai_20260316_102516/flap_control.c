#include "Rte_FlapControl.h"
#include "FlapControl_MemMap.h"

#define FLAPCONTROL_START_SEC_CODE
#include "FlapControl_MemMap.h"

static uint8 currentPosition = 0U;
static uint8 targetPosition = 0U;
static boolean inMotion = FALSE;
static flap_state_t state = FLAP_IDLE;

FUNC(Std_ReturnType, FLAPCONTROL_CODE) FlapControl_Init(uint8 curPos) {
    currentPosition = curPos;
    targetPosition = curPos;
    inMotion = FALSE;
    state = FLAP_IDLE;
    return E_OK;
}

FUNC(Std_ReturnType, FLAPCONTROL_CODE) FlapControl_Update(uint8 cmdPos, boolean cmdValid, uint8 fbPos, boolean fbValid) {
    boolean startMove = FALSE;

    if (!cmdValid || !fbValid) {
        inMotion = FALSE;
        state = FLAP_FAULT;
        return E_NOT_OK;
    }

    if (cmdPos != fbPos) {
        targetPosition = cmdPos;
        inMotion = TRUE;
        state = FLAP_MOVING;
        startMove = TRUE;
    } else {
        inMotion = FALSE;
        state = FLAP_TARGET_REACHED;
    }
    currentPosition = fbPos;
    return startMove ? E_OK : E_NOT_OK;
}

#define FLAPCONTROL_STOP_SEC_CODE
#include "FlapControl_MemMap.h"
