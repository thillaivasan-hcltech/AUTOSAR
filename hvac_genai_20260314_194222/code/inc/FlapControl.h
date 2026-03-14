/* FlapControl.h - AUTOSAR Compliant Header */

#ifndef FLAPCONTROL_H
#define FLAPCONTROL_H

#include "Std_Types.h"
#include "Platform_Types.h"

#define FLAPCONTROL_SW_MAJOR_VERSION 1
#define FLAPCONTROL_SW_MINOR_VERSION 0
#define FLAPCONTROL_SW_PATCH_VERSION 0

#define FLAP_POS_MIN 0x00U
#define FLAP_POS_MAX 0xE0U

typedef enum {
    FLAP_IDLE = 0,
    FLAP_MOVING,
    FLAP_TARGET_REACHED,
    FLAP_FAULT
} FlapControl_StateType;

typedef struct {
    uint8 currentPosition;
    uint8 targetPosition;
    boolean inMotion;
    FlapControl_StateType state;
} FlapControl_Type;

FUNC(Std_ReturnType, FLAPCONTROL_CODE) FlapControl_Init(P2VAR(FlapControl_Type, AUTOMATIC, RTE_APPL_DATA) inst, uint8 curPos);
FUNC(Std_ReturnType, FLAPCONTROL_CODE) FlapControl_Update(P2VAR(FlapControl_Type, AUTOMATIC, RTE_APPL_DATA) inst, uint8 cmdPos, boolean cmdValid, uint8 fbPos, boolean fbValid);

#endif /* FLAPCONTROL_H */
