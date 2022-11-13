
/**
 * This file contains the initialization and behavior for red coins.
 * Behavior controls audio and the orange number spawned, as well as interacting with
 * the course's red coin star.
 */

/**
 * Red coin's hitbox details.
 */
static struct ObjectHitbox sRedCoinHitbox = {
    /* interactType:      */ INTERACT_COIN,
    /* downOffset:        */ 0,
    /* damageOrCoinValue: */ 2,
    /* health:            */ 0,
    /* numLootCoins:      */ 0,
    /* radius:            */ 100,
    /* height:            */ 64,
    /* hurtboxRadius:     */ 0,
    /* hurtboxHeight:     */ 0,
};

/**
 * Red coin initialization function. Sets the coin's hitbox and parent object.
 */
void bhv_red_coin_init(void) {
    // Set the red coins to have a parent of the closest red coin star.
    struct Object *hiddenRedCoinStar = cur_obj_nearest_object_with_behavior(bhvHiddenRedCoinStar);
    if (hiddenRedCoinStar != NULL) {
        o->parentObj = hiddenRedCoinStar;
    } else if ((hiddenRedCoinStar = cur_obj_nearest_object_with_behavior(bhvBowserCourseRedCoinStar)) != NULL) {
        o->parentObj = hiddenRedCoinStar;
    } else {
        o->parentObj = NULL;
    }

    obj_set_hitbox(o, &sRedCoinHitbox);
}

void bhv_moving_red_coin_init(void) {
    // Set the red coins to have a parent of the closest red coin star.
    struct Object *hiddenRedCoinStar = cur_obj_nearest_object_with_behavior(bhvHiddenRedCoinStar);
    if (hiddenRedCoinStar != NULL) {
        o->parentObj = hiddenRedCoinStar;
    } else if ((hiddenRedCoinStar = cur_obj_nearest_object_with_behavior(bhvBowserCourseRedCoinStar)) != NULL) {
        o->parentObj = hiddenRedCoinStar;
    } else {
        o->parentObj = NULL;
    }

    o->oVelY = random_float() * 10.0f + 30 + o->oCoinBaseYVel;
    o->oForwardVel = random_float() * 10.0f;
    o->oMoveAngleYaw = random_u16();

    obj_set_hitbox(o, &sRedCoinHitbox);
}

/**
 * Main behavior for red coins. Primarily controls coin collection noise and spawning
 * the orange number counter.
 */
void bhv_red_coin_loop(void) {
    // If Mario interacted with the object...
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        // ...and there is a red coin star in the level...
        if (o->parentObj != NULL) {
            // ...increment the star's counter.
            o->parentObj->oHiddenStarTriggerCounter++;

            // Spawn the orange number counter, as long as it isn't the last coin.
            if (o->parentObj->oHiddenStarTriggerCounter != 8) {
                spawn_orange_number(o->parentObj->oHiddenStarTriggerCounter, 0, 0, 0);
            }

#ifdef JP_RED_COIN_SOUND
            // For JP version, play an identical sound for all coins.
            create_sound_spawner(SOUND_GENERAL_RED_COIN);
#else
            // On all versions but the JP version, each coin collected plays a higher noise.
            play_sound(SOUND_MENU_COLLECT_RED_COIN
                       + (((u8) o->parentObj->oHiddenStarTriggerCounter - 1) << 16),
                       gGlobalSoundSource);
#endif
        }

        coin_collected();
        // Despawn the coin.
        o->oInteractStatus = INT_STATUS_NONE;
    }
}

void bhv_moving_red_coin_loop(void) {
    // If Mario interacted with the object...
    if (o->oInteractStatus & INT_STATUS_INTERACTED) {
        // ...and there is a red coin star in the level...
        if (o->parentObj != NULL) {
            // ...increment the star's counter.
            o->parentObj->oHiddenStarTriggerCounter++;

            // Spawn the orange number counter, as long as it isn't the last coin.
            if (o->parentObj->oHiddenStarTriggerCounter != 8) {
                spawn_orange_number(o->parentObj->oHiddenStarTriggerCounter, 0, 0, 0);
            }

            // On all versions but the JP version, each coin collected plays a higher noise.
            play_sound(SOUND_MENU_COLLECT_RED_COIN
                       + (((u8) o->parentObj->oHiddenStarTriggerCounter - 1) << 16),
                       gGlobalSoundSource);
        }

        coin_collected();
        // Despawn the coin.
        o->oInteractStatus = INT_STATUS_NONE;
    }

    cur_obj_update_floor_and_walls();
    cur_obj_if_hit_wall_bounce_away();
    cur_obj_move_standard(-62);

    struct Surface *floor = o->oFloor;

    if (floor != NULL) {
        if (o->oMoveFlags & OBJ_MOVE_ON_GROUND) {
            o->oAction = BOUNCING_COIN_ACT_BOUNCING;
        }
        if (o->oAction == BOUNCING_COIN_ACT_BOUNCING) {
            o->oBounciness = 0;
            if (floor->normal.y < 0.9f) {
                s16 targetYaw = SURFACE_YAW(floor);
                cur_obj_rotate_yaw_toward(targetYaw, 0x400);
            }
        }
    }

    if (o->oTimer == 0) {
        cur_obj_play_sound_2(SOUND_GENERAL_COIN_SPURT);
    }

    if (o->oVelY < 0) {
        cur_obj_become_tangible();
    }

    if (o->oMoveFlags & OBJ_MOVE_LANDED) {
#ifdef COIN_LAVA_FLICKER
        if ((o->oMoveFlags & OBJ_MOVE_ABOVE_DEATH_BARRIER)
        || ((o->oMoveFlags & OBJ_MOVE_ABOVE_LAVA) && cur_obj_wait_then_blink(0, 20))) {
            obj_mark_for_deletion(o);
        }
#else
        if (o->oMoveFlags & (OBJ_MOVE_ABOVE_DEATH_BARRIER | OBJ_MOVE_ABOVE_LAVA)) {
            obj_mark_for_deletion(o);
        }
#endif
    }

    if (o->oMoveFlags & OBJ_MOVE_BOUNCE) {
        if (o->oCoinBounceTimer < 5) {
            cur_obj_play_sound_2(SOUND_GENERAL_COIN_DROP);
        }
        o->oCoinBounceTimer++;
    }

    if (cur_obj_wait_then_blink(400, 20)) {
        //obj_mark_for_deletion(o);
    }

    bhv_coin_sparkles_init();
}