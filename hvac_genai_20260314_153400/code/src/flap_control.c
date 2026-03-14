#include "flap_control.h"

#define FLAP_CONTROL_START_SEC_CODE
#include "flap_control_MemMap.h"

FUNC(Std_ReturnType, FLAP_CONTROL_CODE) flap_control_init(P2VAR(flap_control_t, AUTOMATIC, RTE_APPL_DATA) inst, uint8 cur_pos) {
    if (inst == NULL) { return E_NOT_OK; }
    inst->current_position = cur_pos;
    inst->target_position = cur_pos;
    inst->in_motion = FALSE;
    inst->state = FLAP_IDLE;
    return E_OK;
}

FUNC(Std_ReturnType, FLAP_CONTROL_CODE) flap_control_update(P2VAR(flap_control_t, AUTOMATIC, RTE_APPL_DATA) inst, uint8 cmd_pos, boolean cmd_valid, uint8 fb_pos, boolean fb_valid) {
    if (inst == NULL) { return E_NOT_OK; }
    boolean start_move = FALSE;

    if (!cmd_valid || !fb_valid) {
        inst->in_motion = FALSE;
        inst->state = FLAP_FAULT;
        return E_NOT_OK;
    }

    if (cmd_pos != fb_pos) {
        inst->target_position = cmd_pos;
        inst->in_motion = TRUE;
        inst->state = FLAP_MOVING;
        start_move = TRUE;
    } else {
        inst->in_motion = FALSE;
        inst->state = FLAP_TARGET_REACHED;
    }
    inst->current_position = fb_pos;
    return start_move ? E_OK : E_NOT_OK;
}

#define FLAP_CONTROL_STOP_SEC_CODE
#include "flap_control_MemMap.h"
