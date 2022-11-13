

void bhv_bart_init(void) {
    gMarioState->action = ACT_WAITING_FOR_DIALOG;
    gMarioObject->header.gfx.sharedChild = gLoadedGraphNodes[MODEL_NONE];
    gMarioState->pos[0] = o->oPosX;
    gMarioState->pos[1] = o->oPosY;
    gMarioState->pos[2] = o->oPosZ;

    o->oGravity = -3.0f;
}

void bhv_bart_loop(void) {
        cur_obj_update_floor_and_walls();
    cur_obj_move_standard(-30);

    switch (o->oAction) {
        case 0:
            bart_act_idle();
        break;
        case 1:
            bart_act_walk();
        break;
        case 2:
            bart_act_bonk();
        break;
    }

    gMarioState->pos[0] = o->oPosX;
    gMarioState->pos[1] = o->oPosY;
    gMarioState->pos[2] = o->oPosZ;

    
}

void bart_act_idle(void) {
    cur_obj_init_animation(0);
    if (gPlayer1Controller->stickX != 0 || gPlayer1Controller->stickY != 0) {
            o->oAction = 1;
        }
}

void bart_act_walk(void) {

    struct Controller *controller = gMarioState->controller;
    f32 mag = ((controller->stickMag / 64.0f) * (controller->stickMag / 64.0f)) * 8.0f;


//rotation if there is a mag
    if (mag > 1) {
        cur_obj_rotate_yaw_toward((atan2s(-gPlayer1Controller->stickY, gPlayer1Controller->stickX) + gMarioState->area->camera->yaw), 0x800);
    }
    else if (o->oForwardVel > 0) {
        //decelerate if no mag
        o->oForwardVel *= 0.6f;
        mag = 0;
    }
    

//accelerate if under mag
    if (o->oForwardVel < mag * 3.0f) {
        if (o->oForwardVel < 1.0f) {
            o->oForwardVel = 1.0f;
        }
        o->oForwardVel *= 1.4f;
    }

//set fvel to 0 if its under 1
    if (o->oForwardVel < 1.0f) {
        o->oForwardVel = 0;
    }

    if (o->oForwardVel > 30.0f) {
        o->oForwardVel = 30.0f;
    }

    f32 cappedMag = mag;
    if (cappedMag < o->oForwardVel) {
        cappedMag = o->oForwardVel;
    }
        
        cur_obj_init_animation_with_accel_and_sound(1, 1.4f * (o->oForwardVel/(cappedMag+1)));
        
    

    //print_text_fmt_int(100, 100, "%d", o->header.gfx.animInfo.animFrame);

//set idle action if not moving and not intended to move
    if (o->oForwardVel == 0 && mag == 0) {
        o->oAction = 0;
    }



    struct Surface *surf;
        Vec3f originPos;
        Vec3f hitpos;
        Vec3f raydir;

        raydir[0] = sins(o->oMoveAngleYaw) * 20.0f;
        raydir[2] = coss(o->oMoveAngleYaw) * 20.0f;

        vec3f_set(originPos, o->oPosX, o->oPosY, o->oPosZ);

        find_surface_on_ray(&originPos, raydir, &surf, &hitpos, 2U);
        if (surf != NULL) {
            o->oForwardVel = -5.0f;
            if (gGlobalTimer % 3 == 0) {
                play_sound(SOUND_HORN, gGlobalSoundSource);
                gMarioState->areaIntro = 3;
            }
            else {
            play_sound(SOUND_BONK, gGlobalSoundSource);
            }
            return o->oAction = 2;
        }
}

void bart_act_bonk(void) {
    if (cur_obj_init_animation_and_check_if_near_end(2)) {
        o->oAction = 0;
        o->oForwardVel = 0;
    }
}