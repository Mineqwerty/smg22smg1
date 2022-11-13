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
#include "levels/castle_grounds/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_castle_grounds_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _castle_grounds_segment_7SegmentRomStart, _castle_grounds_segment_7SegmentRomEnd), 
	LOAD_YAY0(0x0A, _water_skybox_yay0SegmentRomStart, _water_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _outside_yay0SegmentRomStart, _outside_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group10_yay0SegmentRomStart, _group10_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group10_geoSegmentRomStart, _group10_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group15_yay0SegmentRomStart, _group15_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group15_geoSegmentRomStart, _group15_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_11), 
	JUMP_LINK(script_func_global_16), 
	LOAD_MODEL_FROM_GEO(MODEL_WISE_MYSTICAL_TREE, wise_mystical_tree_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, castle_grounds_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, 0x00000000, bhvIntroScene),
		OBJECT(MODEL_WOODEN_SIGNPOST, -2788, -494, -1738, 0, 90, 0, (1 << 24) | (1 << 16), bhvMessagePanel),
		OBJECT(MODEL_WISE_MYSTICAL_TREE, -3338, -421, -2278, 0, 90, 0, 0x00000000, bhvTreePill),
		OBJECT(MODEL_CHUCKYA, 3499, -494, 2988, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, 3759, -384, 3452, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, 3338, -434, 3359, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, 3514, -393, 3668, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, 3798, -326, 3033, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, 3253, -398, 3677, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, 3310, -450, 2912, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, 3816, -500, 3796, 0, 0, 0, 0x00000000, bhvChuckya),
		OBJECT(MODEL_CHUCKYA, 3998, -494, 1430, 0, 0, 0, (4 << 16), bhvChuckya),
		OBJECT(MODEL_WOODEN_SIGNPOST, 2861, -494, 2877, 0, -90, 0, (2 << 24) | (2 << 16), bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, 3424, -494, 1445, 0, -90, 0, (3 << 24) | (3 << 16), bhvMessagePanel),
		OBJECT(MODEL_WOODEN_SIGNPOST, -19, 141, -3496, 0, 0, 0, (8 << 24) | (8 << 16), bhvMessagePanel),
		OBJECT(MODEL_PEACH, -3159, 54, -200, 0, 0, 0, 0x00000000, bhvHiddenRedCoinStar),
		OBJECT(MODEL_BREAKABLE_BOX, -3330, -494, 3333, 0, 0, 0, 0x00000000, bhvBreakableBox),
		OBJECT(MODEL_DL_MONTY_MOLE_HOLE, -3644, -494, -3732, 0, 0, 0, 0x00000000, bhvMontyMoleHole),
		MARIO_POS(0x01, 0, -437, -294, 0),
		OBJECT(MODEL_MONTY_MOLE, -3644, -703, -3732, 0, 0, 0, 0x00000000, bhvMontyMole),
		OBJECT(MODEL_MONTY_MOLE, -3644, -740, -3732, 0, 0, 0, 0x00000000, bhvMontyMole),
		OBJECT(MODEL_MONTY_MOLE, -3644, -800, -3732, 0, 0, 0, 0x00000000, bhvMontyMole),
		OBJECT(MODEL_MONTY_MOLE, -3644, -876, -3732, 0, 0, 0, 0x00000000, bhvMontyMole),
		OBJECT(MODEL_MONTY_MOLE, -3644, -962, -3732, 0, 0, 0, 0x00000000, bhvMontyMole),
		OBJECT(MODEL_RED_COIN, 3598, -434, 3359, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3529, 487, -723, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 520, 1147, -3885, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -3840, -380, -1694, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, -3332, -494, 3332, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_RED_COIN, 3006, -983, -4177, 0, 0, 0, 0x00000000, bhvRedCoin),
		OBJECT(MODEL_NONE, -437, -294, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		TERRAIN(castle_grounds_area_1_collision),
		MACRO_OBJECTS(castle_grounds_area_1_macro_objs),
		STOP_MUSIC(0),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, -437, -294, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
