

void approach_turn_angle(s8 sign) {
    o->oFaceAngleYaw += 0x800 * sign;

    if (o->oFaceAngleYaw % 0x4000 == 0) {
        o->oAction = 0;
    }
}

void move_forward(s8 sign) {
    o->oPosX += 25 * sign * sins(o->oFaceAngleYaw);
    o->oPosZ += 25 * sign * coss(o->oFaceAngleYaw);

    if (o->oTimer == 15) {
        o->oAction = 0;
    }
}

s8 check_forward_floor(s8 sign) {
    if (find_floor_height(o->oPosX + (sign * 400 * sins(o->oFaceAngleYaw)), o->oPosY + 100,  o->oPosZ + (sign * 400 * coss(o->oFaceAngleYaw))) > -10000) {
        return 1;
    }
    return 0;
}

void bhv_etrian_controller_loop(void) {

    //if (o->oTimer == 60) {
    //    gMarioState->areaIntro = 2;
    //}

    switch (o->oAction) {
        case 0:
    if (gPlayer1Controller->buttonDown & U_JPAD) {
        if (check_forward_floor(1)) {
         o->oAction = 3;
         play_sound(SOUND_ETRIAN_STEP, gGlobalSoundSource);
        }
    }

    if (gPlayer1Controller->buttonDown & D_JPAD) {
        if (check_forward_floor(-1)) {
         o->oAction = 4;
         play_sound(SOUND_ETRIAN_STEP, gGlobalSoundSource);
        }
    }

    if (gPlayer1Controller->buttonPressed & R_JPAD) {
        o->oAction = 2;
    }

    if (gPlayer1Controller->buttonPressed & L_JPAD) {
        o->oAction = 1;
    }
        break;


        case 1:
            approach_turn_angle(1);

        break;
        case 2:
            approach_turn_angle(-1);

        break;
        case 3:
            move_forward(1);
        break;
        case 4:
            move_forward(-1);
        break;
    }

    //input goes before updates


    gCamera->cutscene = 1;

    gLakituState.goalPos[0] = o->oPosX;
    gLakituState.goalPos[1] = o->oPosY + 160;
    gLakituState.goalPos[2] = o->oPosZ;

    gLakituState.goalFocus[0] = o->oPosX + (100 * sins(o->oFaceAngleYaw));
    gLakituState.goalFocus[2] = o->oPosZ + (100 * coss(o->oFaceAngleYaw));
    gLakituState.goalFocus[1] = o->oPosY + 160;

    gMarioState->action = ACT_WAITING_FOR_DIALOG;
    gMarioObject->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_NONE];
    gMarioState->pos[0] = o->oPosX;
    gMarioState->pos[1] = o->oPosY;
    gMarioState->pos[2] = o->oPosZ;
}



void bhv_etrian_intro_loop(void) {
    if (o->oTimer < 180) {
        if (o->oTimer == 0) {
            play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 30, 0, 0, 0);
        }

        if (o->oTimer == 150) {
            play_transition(WARP_TRANSITION_FADE_INTO_COLOR, 30, 0, 0, 0);
        }
    }
    else {
        gMarioState->areaIntro = 0;
        struct Object *controller = spawn_object_relative(0, 0, 0, 0, gMarioObject, MODEL_NONE, bhvEtrianController);
        controller->oFaceAngleYaw -= 0x4000;

        play_transition(WARP_TRANSITION_FADE_FROM_COLOR, 30, 0, 0, 0);
        obj_mark_for_deletion(o);
    }

    gMarioState->action = ACT_WAITING_FOR_DIALOG;
    gMarioObject->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_NONE];
    gMarioState->pos[0] = o->oPosX;
    gMarioState->pos[1] = o->oPosY;
    gMarioState->pos[2] = o->oPosZ;
}

