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
#include "levels/ttc/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ttc_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ttc_segment_7SegmentRomStart, _ttc_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _machine_yay0SegmentRomStart, _machine_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group1_yay0SegmentRomStart, _group1_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group1_geoSegmentRomStart, _group1_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _ttc_segment_7SegmentRomStart, _ttc_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _bits_skybox_mio0SegmentRomStart, _bits_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_2), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_ROTATING_CUBE, ttc_geo_000240), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_ROTATING_PRISM, ttc_geo_000258), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_PENDULUM, ttc_geo_000270), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_LARGE_TREADMILL, ttc_geo_000288), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_SMALL_TREADMILL, ttc_geo_0002A8), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_PUSH_BLOCK, ttc_geo_0002C8), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_ROTATING_HEXAGON, ttc_geo_0002E0), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_ROTATING_TRIANGLE, ttc_geo_0002F8), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_PIT_BLOCK, ttc_geo_000310), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_PIT_BLOCK_UNUSED, ttc_geo_000328), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_ELEVATOR_PLATFORM, ttc_geo_000340), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_CLOCK_HAND, ttc_geo_000358), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_SPINNER, ttc_geo_000370), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_SMALL_GEAR, ttc_geo_000388), 
	LOAD_MODEL_FROM_GEO(MODEL_TTC_LARGE_GEAR, ttc_geo_0003A0), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ttc_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_CCM, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 0, 100, 0, 0, 0, 0, (11 << 16), bhvFadingWarp),
		OBJECT(MODEL_NONE, 0, 200, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 200, 0),
		TERRAIN(ttc_area_1_collision),
		MACRO_OBJECTS(ttc_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_STREAMED_HAMSTER),
		SHOW_DIALOG(0x00, DIALOG_035),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
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
