#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/jrb/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_jrb_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _jrb_segment_7SegmentRomStart, _jrb_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group4_yay0SegmentRomStart, _group4_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group4_geoSegmentRomStart, _group4_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group13_yay0SegmentRomStart, _group13_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group13_geoSegmentRomStart, _group13_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_5), 
	JUMP_LINK(script_func_global_14), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_LEFT_HALF_PART, jrb_geo_000978), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_BACK_LEFT_PART, jrb_geo_0009B0), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_RIGHT_HALF_PART, jrb_geo_0009E8), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SHIP_BACK_RIGHT_PART, jrb_geo_000A00), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SUNKEN_SHIP, jrb_geo_000990), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SUNKEN_SHIP_BACK, jrb_geo_0009C8), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_ROCK, jrb_geo_000930), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_SLIDING_BOX, jrb_geo_000960), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_FALLING_PILLAR, jrb_geo_000900), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_FALLING_PILLAR_BASE, jrb_geo_000918), 
	LOAD_MODEL_FROM_GEO(MODEL_JRB_FLOATING_PLATFORM, jrb_geo_000948), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, jrb_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_LLL, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 200, -184, 693, 0, 0, 0, 0x00000000, bhvMemoryLeak),
		OBJECT(MODEL_NONE, 789, -184, 4596, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, -467, -184, 4959, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_NONE, 144, -184, 3337, 0, 0, 0, 0x00000000, bhvGoombaTripletSpawner),
		OBJECT(MODEL_BOWSER, 11721, -274, 12078, 0, 0, 0, 0x00000000, bhvBowser),
		OBJECT(MODEL_SKEETER, 1395, -184, 6572, 0, 0, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, 182, -184, 7100, 0, 0, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, 352, -184, 5485, 0, 0, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, -160, -184, 996, 0, 0, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_SKEETER, 2032, -184, 9226, 0, 0, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_FLYGUY, 3671, 10, 10733, 0, 0, 0, 0x00000000, bhvFlyGuy),
		OBJECT(MODEL_FLYGUY, 4200, 69, 12517, 0, 0, 0, 0x00000000, bhvFlyGuy),
		OBJECT(MODEL_FLYGUY, 4843, -184, 11529, 0, 0, 0, 0x00000000, bhvFlyGuy),
		OBJECT(MODEL_FLYGUY, 6111, -218, 13093, 0, 0, 0, 0x00000000, bhvFlyGuy),
		OBJECT(MODEL_SKEETER, 6407, -207, 12083, 0, 0, 0, 0x00000000, bhvSkeeter),
		OBJECT(MODEL_NONE, 14320, -175, 10678, 0, 0, 0, (11 << 16), bhvWarp),
		OBJECT(MODEL_NONE, 0, 200, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 200, 0),
		TERRAIN(jrb_area_1_collision),
		MACRO_OBJECTS(jrb_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_STREAMED_SORTING),
		SHOW_DIALOG(0x00, DIALOG_015),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		LOAD_YAY0(0xa, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 200, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
