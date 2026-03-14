#include "Rte_FlapControlSWC.h"

void FlapControl_Init(uint8 cur_pos) {
    Rte_IWrite_FlapControlSWC_FlapControl_Init_currentPosition(cur_pos);
    Rte_IWrite_FlapControlSWC_FlapControl_Init_targetPosition(cur_pos);
    Rte_IWrite_FlapControlSWC_FlapControl_Init_inMotion(FALSE);
    Rte_IWrite_FlapControlSWC_FlapControl_Init_state(FLAP_IDLE);
}

boolean FlapControl_Update(uint8 cmd_pos, boolean cmd_valid, uint8 fb_pos, boolean fb_valid) {
    boolean start_move = FALSE;
    flap_state_t state = FLAP_IDLE;

    if (!cmd_valid || !fb_valid) {
        Rte_IWrite_FlapControlSWC_FlapControl_Update_inMotion(FALSE);
        state = FLAP_FAULT;
        Rte_IWrite_FlapControlSWC_FlapControl_Update_state(state);
        return FALSE;
    }

    if (cmd_pos != fb_pos) {
        Rte_IWrite_FlapControlSWC_FlapControl_Update_targetPosition(cmd_pos);
        Rte_IWrite_FlapControlSWC_FlapControl_Update_inMotion(TRUE);
        state = FLAP_MOVING;
        start_move = TRUE;
    } else {
        Rte_IWrite_FlapControlSWC_FlapControl_Update_inMotion(FALSE);
        state = FLAP_TARGET_REACHED;
    }
    Rte_IWrite_FlapControlSWC_FlapControl_Update_currentPosition(fb_pos);
    Rte_IWrite_FlapControlSWC_FlapControl_Update_state(state);
    return start_move;
}
