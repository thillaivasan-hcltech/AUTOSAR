#ifndef FLAP_CONTROL_H
#define FLAP_CONTROL_H

#include "Std_Types.h"

#define FLAP_POS_MIN 0x00U
#define FLAP_POS_MAX 0xE0U

typedef struct {
    uint8 current_position;
    uint8 target_position;
    boolean in_motion;
} FlapControl_Type;

typedef struct {
    uint8 min_position;
    uint8 max_position;
} FlapControl_ConfigType;

FUNC(void, FLAP_CONTROL_CODE) FlapControl_Init(P2CONST(FlapControl_ConfigType, AUTOMATIC, RTE_APPL_CONST) ConfigPtr);
FUNC(Std_ReturnType, FLAP_CONTROL_CODE) FlapControl_Update(P2VAR(FlapControl_Type, AUTOMATIC, RTE_APPL_DATA) inst, uint8 cmd_pos, boolean cmd_valid, uint8 fb_pos, boolean fb_valid);

#endif /* FLAP_CONTROL_H */
