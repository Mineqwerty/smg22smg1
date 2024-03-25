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
#include "levels/lll/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_lll_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _lll_segment_7SegmentRomStart, _lll_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _lll_segment_7SegmentRomStart, _lll_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, lll_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_JRB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x0B, LEVEL_WF, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_WOODEN_SIGNPOST, 2837, 284, -1199, 0, 0, 0, (18 << 24) | (18 << 16), bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, 7027, 916, -551, 0, -120, 0, (19 << 24) | (19 << 16), bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, 9775, 1042, -3875, 0, 50, 0, (23 << 24) | (23 << 16), bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, 14677, 777, -14522, 0, -52, 0, (30 << 24) | (30 << 16), bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, 14957, 902, -9386, 0, 140, 0, (24 << 24) | (24 << 16), bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, 644, 636, -23156, 0, 72, 0, (32 << 24) | (32 << 16), bhvMessagePanel),
		OBJECT(MODEL_NONE, 82, 792, -23312, 0, 72, 0, (11 << 16), bhvWarp),
		OBJECT(MODEL_NONE, 0, 200, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 200, 0),
		TERRAIN(lll_area_1_collision),
		MACRO_OBJECTS(lll_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_SNOW),
		SHOW_DIALOG(0x00, DIALOG_016),
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
