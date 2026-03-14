/* FlapControl.c - AUTOSAR Compliant Source */

#include "FlapControl.h"

#define FLAPCONTROL_START_SEC_CODE
#include "FlapControl_MemMap.h"

FUNC(Std_ReturnType, FLAPCONTROL_CODE) FlapControl_Init(P2VAR(FlapControl_Type, AUTOMATIC, RTE_APPL_DATA) inst, uint8 curPos) {
    if (inst == NULL_PTR) {
        return E_NOT_OK;
    }
    inst->currentPosition = curPos;
    inst->targetPosition = curPos;
    inst->inMotion = FALSE;
    inst->state = FLAP_IDLE;
    return E_OK;
}

FUNC(Std_ReturnType, FLAPCONTROL_CODE) FlapControl_Update(P2VAR(FlapControl_Type, AUTOMATIC, RTE_APPL_DATA) inst, uint8 cmdPos, boolean cmdValid, uint8 fbPos, boolean fbValid) {
    if (inst == NULL_PTR) {
        return E_NOT_OK;
    }
    boolean startMove = FALSE;

    if (!cmdValid || !fbValid) {
        inst->inMotion = FALSE;
        inst->state = FLAP_FAULT;
        return E_NOT_OK;
    }

    if (cmdPos != fbPos) {
        inst->targetPosition = cmdPos;
        inst->inMotion = TRUE;
        inst->state = FLAP_MOVING;
        startMove = TRUE;
    } else {
        inst->inMotion = FALSE;
        inst->state = FLAP_TARGET_REACHED;
    }
    inst->currentPosition = fbPos;
    return startMove ? E_OK : E_NOT_OK;
}

#define FLAPCONTROL_STOP_SEC_CODE
#include "FlapControl_MemMap.h"
