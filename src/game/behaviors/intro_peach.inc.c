// intro_peach.inc.c

/**
 * Set peach's location relative to the camera focus.
 * If nonzero, make peach's opacity approach targetOpacity by increment
 */
void intro_peach_set_pos_and_opacity(struct Object *obj, f32 targetOpacity, f32 increment) {
    Vec3f newPos;
    s16 focusPitch, focusYaw;

    vec3f_get_angle(gLakituState.pos, gLakituState.focus, &focusPitch, &focusYaw);
    vec3f_set_dist_and_angle(gLakituState.pos, newPos, obj->oIntroPeachDistToCamera,
                             obj->oIntroPeachPitchFromFocus + focusPitch,
                             obj->oIntroPeachYawFromFocus + focusYaw);
    vec3f_copy(&obj->oPosVec, newPos);

    f32 newOpacity = obj->oOpacity;
    camera_approach_f32_symmetric_bool(&newOpacity, targetOpacity, increment);
    obj->oOpacity = newOpacity;
}


void bhv_intro_peach_loop(void) {
    
    switch (o->oAction) {
        case PEACH_ACT_INIT:
            o->oAction++;
            o->oFaceAnglePitch = 0x400;
            o->oFaceAngleYaw = 0x7500;
            o->oFaceAngleRoll = -0x3700;
            o->oIntroPeachDistToCamera = 186.0f;
            o->oIntroPeachPitchFromFocus = -9984.0f;
            o->oIntroPeachYawFromFocus = -768.0f;
            o->oOpacity = 255;
            o->header.gfx.animInfo.animFrame = 100;
            break;

        case PEACH_ACT_FADE_1:
            intro_peach_set_pos_and_opacity(o, 0.0f, 0.0f);

            if (o->oTimer > 20) {
                o->oAction++;
            }
            break;

        case PEACH_ACT_UNFADE:
            intro_peach_set_pos_and_opacity(o, 255.0f, 3.0f);

            if ((o->oTimer > 100) && (get_dialog_id() == DIALOG_NONE)) {
                o->oAction++;
            }

            if (o->oTimer > 180) {
                
                extern const u8 texture_roblox_eye[];
                extern const u8 texture_roblox_nose[];
                extern const u8 texture_roblox_mouth[];

                extern const u8 texture_roblox_face_l[];
                extern const u8 texture_roblox_face_r[];

                extern u8 peach_seg5_texture_05001228[];
                extern u8 peach_seg5_texture_05001A28[];
                extern u8 peach_seg5_texture_05002228[];

                extern u8 peach_seg5_texture_05002E28[];

                extern u8 peach_seg5_texture_05003E28[];

                extern u8 castle_grounds_seg7_texture_0700C9E8[];
                extern u8 castle_grounds_seg7_texture_0700D9E8[];
                
                u8 *peachEye1 = segmented_to_virtual(&peach_seg5_texture_05001228);
                u8 *peachEye2 = segmented_to_virtual(&peach_seg5_texture_05001A28);
                u8 *peachEye3 = segmented_to_virtual(&peach_seg5_texture_05002228);

                u8 *peachLips = segmented_to_virtual(&peach_seg5_texture_05002E28);

                u8 *peachNose = segmented_to_virtual(&peach_seg5_texture_05003E28);

                u8 *peachLetterL = segmented_to_virtual(&castle_grounds_seg7_texture_0700C9E8);
                u8 *peachLetterR = segmented_to_virtual(&castle_grounds_seg7_texture_0700D9E8);

                dma_read(peachEye1, texture_roblox_eye, texture_roblox_eye + 2048);
                dma_read(peachEye2, texture_roblox_eye, texture_roblox_eye + 2048);
                dma_read(peachEye3, texture_roblox_eye, texture_roblox_eye + 2048);

                dma_read(peachLips, texture_roblox_mouth, texture_roblox_mouth + 2048);

                dma_read(peachNose, texture_roblox_nose, texture_roblox_nose + 2048);

                dma_read(peachLetterL, texture_roblox_face_l, texture_roblox_face_l + 4096);
                dma_read(peachLetterR, texture_roblox_face_r, texture_roblox_face_r + 4096);
                
            }
            break;

        case PEACH_ACT_FADE_2:
            intro_peach_set_pos_and_opacity(o, 0.0f, 8.0f);

            if (o->oTimer > 60) {
                obj_mark_for_deletion(o);
            }
            break;
    }
}
