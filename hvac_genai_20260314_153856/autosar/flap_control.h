#ifndef FLAP_CONTROL_H
#define FLAP_CONTROL_H

#include "Std_Types.h"
#include "Platform_Types.h"

#define FLAP_POS_MIN 0x00U
#define FLAP_POS_MAX 0xE0U

typedef enum {
    FLAP_IDLE = 0,
    FLAP_MOVING,
    FLAP_TARGET_REACHED,
    FLAP_FAULT
} flap_state_t;

FUNC(Std_ReturnType, FLAP_CONTROL_CODE) FlapControl_Init(uint8 curPos);
FUNC(Std_ReturnType, FLAP_CONTROL_CODE) FlapControl_Update(uint8 cmdPos, boolean cmdValid, uint8 fbPos, boolean fbValid);

#endif /* FLAP_CONTROL_H */
