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
    u8 bartdist;
    if (o->oDistanceToMario >= 4095) {
        bartdist = 0;
        play_secondary_music(SEQ_STREAMED_BART, 127, 0, 0);
    } else {
        bartdist = 127 - o->oDistanceToMario / 32;
        play_secondary_music(SEQ_STREAMED_BART, 127 - bartdist, bartdist, 0);
    }
    
    


     if (o->oTimer > 1536) {
        o->oTimer = 0;
    }

    extern const u8 bart_tl_textures_dma[];
    extern u8 bob_dl_tlbase_rgba16[];
    u8 *tlTextures = segmented_to_virtual(&bob_dl_tlbase_rgba16);

    

    extern const u8 bart_tr_textures_dma[];
    extern u8 bob_dl_trbase_rgba16[];
    u8 *trTextures = segmented_to_virtual(&bob_dl_trbase_rgba16);

    extern const u8 bart_bl_textures_dma[];
    extern u8 bob_dl_blbase_rgba16[];
    u8 *blTextures = segmented_to_virtual(&bob_dl_blbase_rgba16);
    

    extern const u8 bart_br_textures_dma[];
    extern u8 bob_dl_brbase_rgba16[];
    u8 *brTextures = segmented_to_virtual(&bob_dl_brbase_rgba16);

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

    extern u8 bob_dl_smile_rgba16[];
    u8 *scary = segmented_to_virtual(&bob_dl_smile_rgba16);
    dma_read(scary, gGlobalTimer * 4096, gGlobalTimer * 4096 + 4096);
}


void bhv_memory_leak_loop(void) {
    const f32 (*coords)[2][3] = segmented_to_virtual(&scene1);
    
    //gLakituState.goalPos[0] = coords[o->oTimer][0][0];
    //gLakituState.goalPos[1] = coords[o->oTimer][0][1];
    //gLakituState.goalPos[2] = coords[o->oTimer][0][2];

    //gLakituState.goalFocus[0] = coords[o->oTimer][1][0];
    //gLakituState.goalFocus[1] = coords[o->oTimer][1][1];
    //gLakituState.goalFocus[2] = coords[o->oTimer][1][2];

    
}