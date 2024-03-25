#include "src/game/game_init.h"
#include "levels/jrb/header.h"

void bhv_tree_pill_loop(void) {
    if (o->oDistanceToMario < 200.0f) {
        gPenis = 1;
        obj_mark_for_deletion(o);
    }

    o->oFaceAngleYaw += 0x400;
    o->oMoveAngleYaw += 0x400;
}

void bhv_bart_controller_loop(void){
    u8 bartdist = 0;

    if (o->oTimer > 30 && o->oAction == 0) {
        o->oAction = 1;
    }

    if (o->oAction == 1) {
    if (o->oDistanceToMario >= 4095) {
        bartdist = 0;
        play_secondary_music(SEQ_STREAMED_BART, 127, 0, 0);
    } else {
        bartdist = 127 - o->oDistanceToMario / 32;
        play_secondary_music(SEQ_STREAMED_BART, 127 - bartdist, bartdist, 0);
    }
    
    
    


     if (o->oTimer > 1536) {
        o->oTimer = 0;
        o->oAction = 1;
    }

    extern const u8 bart_tl_textures_dma[];
    extern u8 inside_castle_seg7_texture_0700A800[];
    u8 *tlTextures = segmented_to_virtual(&inside_castle_seg7_texture_0700A800);

    

    extern const u8 bart_tr_textures_dma[];
    extern u8 inside_castle_seg7_texture_0700E800[];
    u8 *trTextures = segmented_to_virtual(&inside_castle_seg7_texture_0700E800);

    extern const u8 bart_bl_textures_dma[];
    extern u8 inside_castle_seg7_texture_0700B800[];
    u8 *blTextures = segmented_to_virtual(&inside_castle_seg7_texture_0700B800);
    

    extern const u8 bart_br_textures_dma[];
    extern u8 inside_castle_seg7_texture_0700F800[];
    u8 *brTextures = segmented_to_virtual(&inside_castle_seg7_texture_0700F800);

    if (o->oTimer < 1314) {
    dma_read(tlTextures, ((o->oTimer / 6)*4096) + bart_tl_textures_dma, ((o->oTimer / 6)*4096) + bart_tl_textures_dma + 4096);
    dma_read(trTextures, ((o->oTimer / 6)*4096) + bart_tr_textures_dma, ((o->oTimer / 6)*4096) + bart_tr_textures_dma + 4096);
    dma_read(blTextures, ((o->oTimer / 6)*4096) + bart_bl_textures_dma, ((o->oTimer / 6)*4096) + bart_bl_textures_dma + 4096);
    dma_read(brTextures, ((o->oTimer / 6)*4096) + bart_br_textures_dma, ((o->oTimer / 6)*4096) + bart_br_textures_dma + 4096);
    }
    else {
        dma_read(tlTextures, bart_tl_textures_dma - ((o->oTimer / 6)*4096)  - 4096, bart_tl_textures_dma - ((o->oTimer / 6)*4096));
    dma_read(trTextures, 16 + bart_tl_textures_dma - ((o->oTimer / 6)*4096)  - 4096, 16 + bart_tl_textures_dma - ((o->oTimer / 6)*4096));
    dma_read(blTextures, 64 + bart_tl_textures_dma - ((o->oTimer / 6)*4096)  - 4096, 64 + bart_tl_textures_dma - ((o->oTimer / 6)*4096));
    dma_read(brTextures, 128 + bart_tl_textures_dma - ((o->oTimer / 6)*4096)  - 4096, 128 + bart_tl_textures_dma - ((o->oTimer / 6)*4096));
    }

    }

    extern u8 castle_inside_dl_smile_rgba16[];
    u8 *scary = segmented_to_virtual(&castle_inside_dl_smile_rgba16);
    dma_read(scary, gGlobalTimer * 4096, gGlobalTimer * 4096 + 4096);
}


void bhv_memory_leak_loop(void) {

    if (gCorruptionTimer > 200) {
    extern u8 jrb_dl_coldbrick_rgba16[];
    u8 *floor = segmented_to_virtual(&jrb_dl_coldbrick_rgba16);
    dma_read(floor, jrb_dl_coldbrick_rgba16 + gCorruptionTimer, jrb_dl_coldbrick_rgba16 + gCorruptionTimer + 4096);
    }

    if (gCorruptionTimer == 40) {

        //load_segment_decompress(0x0A, _ssl_skybox_yay0SegmentRomStart + 20, _ssl_skybox_yay0SegmentRomEnd + 20);
    }
    
}

void bhv_cloudcap_cloud_loop(void) {
    o->oPosX = gMarioState->pos[0];
    o->oPosY = gMarioState->pos[1];
    o->oPosZ = gMarioState->pos[2];
}

void bhv_etrian_warp_loop(void) {
    if (o->oDistanceToMario < 200.0f) {
        initiate_warp(LEVEL_TTC, 1, 0x0A, 0);
    }
}

void bhv_fallguy_loop(void) {

    

    if (o->oTimer == 20 && o->oF4 == 0) {
        play_sound(SOUND_SQUIRREL, gGlobalSoundSource);
    }

     if (o->oAction == 0 && gMarioState->pos[0] > 1600) {
        play_sound(SOUND_PLEASE, gGlobalSoundSource);
        o->oAction = 1;
    }

    if (o->oAction == 1 && gMarioState->pos[0] > 1800) {
        o->oAction = 2;
        o->oF4++;
        spawn_object_relative(0, 0, 1000, 0, o, MODEL_BOWLING_BALL, bhvFreeBowlingBall);
    }

    if (o->oAction == 2) {
if (o->oF4 >= 3) {
    print_text(20, 40, "KEEP TRYING A BIT MORE");
}
else {
        print_text(20, 40, "ENABLE FRAMEBUFFER");
    print_text(20, 20, "THEN U CAN GET STAR :)");
}

        if (o->oTimer == 5) {
            gMarioState->action = ACT_BACKWARD_AIR_KB;
            gMarioState->faceAngle[1] = 0x4000;
            play_sound(SOUND_FART, gGlobalSoundSource);
        }
        if (o->oTimer == 6) {
            gMarioState->forwardVel = -40.0f;
            gMarioState->vel[1] = 10.0f;

            if (o->oF4 == 6) {
        *(volatile int*)0 = 0;
    }
        }

        if (o->oTimer == 50) {
            o->oAction = 0;
        }
    }
}