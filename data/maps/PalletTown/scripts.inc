# 1 "data/maps/PalletTown/scripts.pory"

# 2 "data/maps/PalletTown/scripts.pory"
.equ LOCALID_SIGN_LADY, 1
# 3 "data/maps/PalletTown/scripts.pory"
.equ LOCALID_PROF_OAK,  3
# 4 "data/maps/PalletTown/scripts.pory"

# 5 "data/maps/PalletTown/scripts.pory"
.equ SIGN_LADY_READY, VAR_TEMP_2
# 6 "data/maps/PalletTown/scripts.pory"

# 7 "data/maps/PalletTown/scripts.pory"
PalletTown_MapScripts::
# 8 "data/maps/PalletTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_OnTransition
# 9 "data/maps/PalletTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_OnFrame
# 10 "data/maps/PalletTown/scripts.pory"
	.byte 0
# 11 "data/maps/PalletTown/scripts.pory"

# 12 "data/maps/PalletTown/scripts.pory"
PalletTown_OnTransition::
# 13 "data/maps/PalletTown/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_PALLET_TOWN
# 14 "data/maps/PalletTown/scripts.pory"
	end
# 15 "data/maps/PalletTown/scripts.pory"

# 16 "data/maps/PalletTown/scripts.pory"
PalletTown_OnFrame::
# 17 "data/maps/PalletTown/scripts.pory"
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_OAK, 2, PalletTown_EventScript_OakRatingScene
# 18 "data/maps/PalletTown/scripts.pory"
	.2byte 0
# 19 "data/maps/PalletTown/scripts.pory"

# 20 "data/maps/PalletTown/scripts.pory"
@ Oak approaches player after exiting their house post Elite Four to check if they should receieve the National Dex
# 21 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakRatingScene::
# 22 "data/maps/PalletTown/scripts.pory"
	lockall
# 23 "data/maps/PalletTown/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 24 "data/maps/PalletTown/scripts.pory"
	setobjectxyperm LOCALID_PROF_OAK, 14, 14
# 25 "data/maps/PalletTown/scripts.pory"
	setobjectmovementtype LOCALID_PROF_OAK, MOVEMENT_TYPE_FACE_LEFT
# 26 "data/maps/PalletTown/scripts.pory"
	addobject LOCALID_PROF_OAK
# 27 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToPlayersDoor
# 28 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 29 "data/maps/PalletTown/scripts.pory"
	goto_if_unset FLAG_WORLD_MAP_ONE_ISLAND, PalletTown_EventScript_NotBeenToOneIslandYet
# 30 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OakLetMeSeePokedex
# 31 "data/maps/PalletTown/scripts.pory"
	setvar VAR_0x8004, 0
# 32 "data/maps/PalletTown/scripts.pory"
	specialvar VAR_RESULT, GetPokedexCount
# 33 "data/maps/PalletTown/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 34 "data/maps/PalletTown/scripts.pory"
	copyvar VAR_0x8009, VAR_0x8006
# 35 "data/maps/PalletTown/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8008
# 36 "data/maps/PalletTown/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_0x8009
# 37 "data/maps/PalletTown/scripts.pory"
	goto_if_lt VAR_0x8009, 60, PalletTown_EventScript_NotEnoughMonsForNationalDex
# 38 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_CaughtXImpressiveFollowMe
# 39 "data/maps/PalletTown/scripts.pory"
	closemessage
# 40 "data/maps/PalletTown/scripts.pory"
	playbgm MUS_FOLLOW_ME, 0
# 41 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerWalkToLabFromHouse
# 42 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToLabFromHouse
# 43 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 44 "data/maps/PalletTown/scripts.pory"
	opendoor 16, 13
# 45 "data/maps/PalletTown/scripts.pory"
	waitdooranim
# 46 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterLab
# 47 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerEnterLab
# 48 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 49 "data/maps/PalletTown/scripts.pory"
	closedoor 16, 13
# 50 "data/maps/PalletTown/scripts.pory"
	waitdooranim
# 51 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 7
# 52 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 3
# 53 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
# 54 "data/maps/PalletTown/scripts.pory"
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 12
# 55 "data/maps/PalletTown/scripts.pory"
	waitstate
# 56 "data/maps/PalletTown/scripts.pory"
	releaseall
# 57 "data/maps/PalletTown/scripts.pory"
	end
# 58 "data/maps/PalletTown/scripts.pory"

# 59 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_EndOakRatingScene::
# 60 "data/maps/PalletTown/scripts.pory"
	closemessage
# 61 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakExit
# 62 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 63 "data/maps/PalletTown/scripts.pory"
	removeobject LOCALID_PROF_OAK
# 64 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 3
# 65 "data/maps/PalletTown/scripts.pory"
	releaseall
# 66 "data/maps/PalletTown/scripts.pory"
	end
# 67 "data/maps/PalletTown/scripts.pory"

# 68 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_NotEnoughMonsForNationalDex::
# 69 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_CaughtXPuttingInHonestEffort
# 70 "data/maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_EndOakRatingScene
# 71 "data/maps/PalletTown/scripts.pory"
	end
# 72 "data/maps/PalletTown/scripts.pory"

# 73 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_NotBeenToOneIslandYet::
# 74 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OakYouEnjoyingTraveling
# 75 "data/maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_EndOakRatingScene
# 76 "data/maps/PalletTown/scripts.pory"
	end
# 77 "data/maps/PalletTown/scripts.pory"

# 78 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakWalkToPlayersDoor::
# 79 "data/maps/PalletTown/scripts.pory"
	walk_left
# 80 "data/maps/PalletTown/scripts.pory"
	walk_left
# 81 "data/maps/PalletTown/scripts.pory"
	walk_left
# 82 "data/maps/PalletTown/scripts.pory"
	walk_up
# 83 "data/maps/PalletTown/scripts.pory"
	walk_up
# 84 "data/maps/PalletTown/scripts.pory"
	walk_up
# 85 "data/maps/PalletTown/scripts.pory"
	walk_up
# 86 "data/maps/PalletTown/scripts.pory"
	walk_up
# 87 "data/maps/PalletTown/scripts.pory"
	walk_left
# 88 "data/maps/PalletTown/scripts.pory"
	walk_left
# 89 "data/maps/PalletTown/scripts.pory"
	walk_left
# 90 "data/maps/PalletTown/scripts.pory"
	walk_left
# 91 "data/maps/PalletTown/scripts.pory"
	walk_left
# 92 "data/maps/PalletTown/scripts.pory"
	walk_in_place_faster_up
# 93 "data/maps/PalletTown/scripts.pory"
	step_end
# 94 "data/maps/PalletTown/scripts.pory"

# 95 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakExit::
# 96 "data/maps/PalletTown/scripts.pory"
	walk_right
# 97 "data/maps/PalletTown/scripts.pory"
	walk_right
# 98 "data/maps/PalletTown/scripts.pory"
	walk_right
# 99 "data/maps/PalletTown/scripts.pory"
	walk_right
# 100 "data/maps/PalletTown/scripts.pory"
	walk_right
# 101 "data/maps/PalletTown/scripts.pory"
	walk_down
# 102 "data/maps/PalletTown/scripts.pory"
	walk_down
# 103 "data/maps/PalletTown/scripts.pory"
	walk_down
# 104 "data/maps/PalletTown/scripts.pory"
	walk_down
# 105 "data/maps/PalletTown/scripts.pory"
	walk_down
# 106 "data/maps/PalletTown/scripts.pory"
	walk_right
# 107 "data/maps/PalletTown/scripts.pory"
	walk_right
# 108 "data/maps/PalletTown/scripts.pory"
	walk_right
# 109 "data/maps/PalletTown/scripts.pory"
	step_end
# 110 "data/maps/PalletTown/scripts.pory"

# 111 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakWalkToLabFromHouse::
# 112 "data/maps/PalletTown/scripts.pory"
	walk_right
# 113 "data/maps/PalletTown/scripts.pory"
	walk_right
# 114 "data/maps/PalletTown/scripts.pory"
	walk_right
# 115 "data/maps/PalletTown/scripts.pory"
	walk_right
# 116 "data/maps/PalletTown/scripts.pory"
	walk_right
# 117 "data/maps/PalletTown/scripts.pory"
	walk_down
# 118 "data/maps/PalletTown/scripts.pory"
	walk_down
# 119 "data/maps/PalletTown/scripts.pory"
	walk_down
# 120 "data/maps/PalletTown/scripts.pory"
	walk_down
# 121 "data/maps/PalletTown/scripts.pory"
	walk_down
# 122 "data/maps/PalletTown/scripts.pory"
	walk_right
# 123 "data/maps/PalletTown/scripts.pory"
	walk_right
# 124 "data/maps/PalletTown/scripts.pory"
	walk_right
# 125 "data/maps/PalletTown/scripts.pory"
	walk_right
# 126 "data/maps/PalletTown/scripts.pory"
	walk_right
# 127 "data/maps/PalletTown/scripts.pory"
	walk_in_place_faster_up
# 128 "data/maps/PalletTown/scripts.pory"
	step_end
# 129 "data/maps/PalletTown/scripts.pory"

# 130 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerWalkToLabFromHouse::
# 131 "data/maps/PalletTown/scripts.pory"
	walk_down
# 132 "data/maps/PalletTown/scripts.pory"
	walk_right
# 133 "data/maps/PalletTown/scripts.pory"
	walk_right
# 134 "data/maps/PalletTown/scripts.pory"
	walk_right
# 135 "data/maps/PalletTown/scripts.pory"
	walk_right
# 136 "data/maps/PalletTown/scripts.pory"
	walk_right
# 137 "data/maps/PalletTown/scripts.pory"
	walk_down
# 138 "data/maps/PalletTown/scripts.pory"
	walk_down
# 139 "data/maps/PalletTown/scripts.pory"
	walk_down
# 140 "data/maps/PalletTown/scripts.pory"
	walk_down
# 141 "data/maps/PalletTown/scripts.pory"
	walk_down
# 142 "data/maps/PalletTown/scripts.pory"
	walk_right
# 143 "data/maps/PalletTown/scripts.pory"
	walk_right
# 144 "data/maps/PalletTown/scripts.pory"
	walk_right
# 145 "data/maps/PalletTown/scripts.pory"
	walk_right
# 146 "data/maps/PalletTown/scripts.pory"
	step_end
# 147 "data/maps/PalletTown/scripts.pory"

# 148 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakTriggerLeft::
# 149 "data/maps/PalletTown/scripts.pory"
	lockall
# 150 "data/maps/PalletTown/scripts.pory"
	setvar VAR_TEMP_1, 0
# 151 "data/maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_OakTrigger
# 152 "data/maps/PalletTown/scripts.pory"
	end
# 153 "data/maps/PalletTown/scripts.pory"

# 154 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakTriggerRight::
# 155 "data/maps/PalletTown/scripts.pory"
	lockall
# 156 "data/maps/PalletTown/scripts.pory"
	setvar VAR_TEMP_1, 1
# 157 "data/maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_OakTrigger
# 158 "data/maps/PalletTown/scripts.pory"
	end
# 159 "data/maps/PalletTown/scripts.pory"

# 160 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakTrigger::
# 161 "data/maps/PalletTown/scripts.pory"
	famechecker FAMECHECKER_OAK, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
# 162 "data/maps/PalletTown/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 163 "data/maps/PalletTown/scripts.pory"
	delay 30
# 164 "data/maps/PalletTown/scripts.pory"
	playbgm MUS_OAK, 0
# 165 "data/maps/PalletTown/scripts.pory"
	message PalletTown_Text_OakDontGoOut
# 166 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_HIDE_RIVAL_IN_LAB
# 167 "data/maps/PalletTown/scripts.pory"
	waitmessage
# 168 "data/maps/PalletTown/scripts.pory"
	delay 85
# 169 "data/maps/PalletTown/scripts.pory"
	closemessage
# 170 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 171 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 172 "data/maps/PalletTown/scripts.pory"
	playse SE_PIN
# 173 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
# 174 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 175 "data/maps/PalletTown/scripts.pory"
	delay 30
# 176 "data/maps/PalletTown/scripts.pory"
	addobject LOCALID_PROF_OAK
# 177 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, PalletTown_EventScript_OakEnterLeft
# 178 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_OakEnterRight
# 179 "data/maps/PalletTown/scripts.pory"
	delay 30
# 180 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OakGrassUnsafeNeedMon
# 181 "data/maps/PalletTown/scripts.pory"
	closemessage
# 182 "data/maps/PalletTown/scripts.pory"
	delay 30
# 183 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, PalletTown_EventScript_OakLeadPlayerToLabLeft
# 184 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_OakLeadPlayerToLabRight
# 185 "data/maps/PalletTown/scripts.pory"
	opendoor 16, 13
# 186 "data/maps/PalletTown/scripts.pory"
	waitdooranim
# 187 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterLab
# 188 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerEnterLab
# 189 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 190 "data/maps/PalletTown/scripts.pory"
	closedoor 16, 13
# 191 "data/maps/PalletTown/scripts.pory"
	waitdooranim
# 192 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1
# 193 "data/maps/PalletTown/scripts.pory"
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
# 194 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 1
# 195 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
# 196 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_DONT_TRANSITION_MUSIC
# 197 "data/maps/PalletTown/scripts.pory"
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 12
# 198 "data/maps/PalletTown/scripts.pory"
	waitstate
# 199 "data/maps/PalletTown/scripts.pory"
	releaseall
# 200 "data/maps/PalletTown/scripts.pory"
	end
# 201 "data/maps/PalletTown/scripts.pory"

# 202 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakEnterLeft::
# 203 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterLeft
# 204 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 205 "data/maps/PalletTown/scripts.pory"
	return
# 206 "data/maps/PalletTown/scripts.pory"

# 207 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakEnterRight::
# 208 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakEnterRight
# 209 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 210 "data/maps/PalletTown/scripts.pory"
	return
# 211 "data/maps/PalletTown/scripts.pory"

# 212 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakLeadPlayerToLabLeft::
# 213 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToLabLeft
# 214 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerWalkToLabLeft
# 215 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 216 "data/maps/PalletTown/scripts.pory"
	return
# 217 "data/maps/PalletTown/scripts.pory"

# 218 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakLeadPlayerToLabRight::
# 219 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_Movement_OakWalkToLabRight
# 220 "data/maps/PalletTown/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_Movement_PlayerWalkToLabRight
# 221 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 222 "data/maps/PalletTown/scripts.pory"
	return
# 223 "data/maps/PalletTown/scripts.pory"

# 224 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakEnterLeft::
# 225 "data/maps/PalletTown/scripts.pory"
	walk_right
# 226 "data/maps/PalletTown/scripts.pory"
	walk_right
# 227 "data/maps/PalletTown/scripts.pory"
	walk_right	
# 228 "data/maps/PalletTown/scripts.pory"
	walk_up
# 229 "data/maps/PalletTown/scripts.pory"
	walk_up
# 230 "data/maps/PalletTown/scripts.pory"
	walk_up
# 231 "data/maps/PalletTown/scripts.pory"
	walk_up
# 232 "data/maps/PalletTown/scripts.pory"
	walk_up
# 233 "data/maps/PalletTown/scripts.pory"
	walk_up
# 234 "data/maps/PalletTown/scripts.pory"
	walk_left
# 235 "data/maps/PalletTown/scripts.pory"
	walk_left
# 236 "data/maps/PalletTown/scripts.pory"
	walk_left
# 237 "data/maps/PalletTown/scripts.pory"
	walk_left
# 238 "data/maps/PalletTown/scripts.pory"
	walk_left
# 239 "data/maps/PalletTown/scripts.pory"
	walk_left
# 240 "data/maps/PalletTown/scripts.pory"
	step_end
# 241 "data/maps/PalletTown/scripts.pory"

# 242 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakEnterRight::
# 243 "data/maps/PalletTown/scripts.pory"
	walk_right
# 244 "data/maps/PalletTown/scripts.pory"
	walk_right
# 245 "data/maps/PalletTown/scripts.pory"
	walk_right
# 246 "data/maps/PalletTown/scripts.pory"
	walk_up
# 247 "data/maps/PalletTown/scripts.pory"
	walk_up
# 248 "data/maps/PalletTown/scripts.pory"
	walk_up
# 249 "data/maps/PalletTown/scripts.pory"
	walk_up
# 250 "data/maps/PalletTown/scripts.pory"
	walk_up
# 251 "data/maps/PalletTown/scripts.pory"
	walk_up
# 252 "data/maps/PalletTown/scripts.pory"
	walk_up
# 253 "data/maps/PalletTown/scripts.pory"
	walk_left
# 254 "data/maps/PalletTown/scripts.pory"
	walk_left
# 255 "data/maps/PalletTown/scripts.pory"
	walk_left
# 256 "data/maps/PalletTown/scripts.pory"
	walk_left
# 257 "data/maps/PalletTown/scripts.pory"
	walk_left
# 258 "data/maps/PalletTown/scripts.pory"
	walk_left
# 259 "data/maps/PalletTown/scripts.pory"
	step_end
# 260 "data/maps/PalletTown/scripts.pory"

# 261 "data/maps/PalletTown/scripts.pory"
	.macro walk_to_lab
# 262 "data/maps/PalletTown/scripts.pory"
	walk_right
# 263 "data/maps/PalletTown/scripts.pory"
    walk_right
# 264 "data/maps/PalletTown/scripts.pory"
    walk_right
# 265 "data/maps/PalletTown/scripts.pory"
    walk_right
# 266 "data/maps/PalletTown/scripts.pory"
    walk_right
# 267 "data/maps/PalletTown/scripts.pory"
    walk_right
# 268 "data/maps/PalletTown/scripts.pory"
    walk_right
# 269 "data/maps/PalletTown/scripts.pory"
    walk_down
# 270 "data/maps/PalletTown/scripts.pory"
    walk_down
# 271 "data/maps/PalletTown/scripts.pory"
    walk_down
# 272 "data/maps/PalletTown/scripts.pory"
    walk_down
# 273 "data/maps/PalletTown/scripts.pory"
    walk_right
# 274 "data/maps/PalletTown/scripts.pory"
    walk_right
# 275 "data/maps/PalletTown/scripts.pory"
    walk_right
# 276 "data/maps/PalletTown/scripts.pory"
    walk_right
# 277 "data/maps/PalletTown/scripts.pory"
    walk_right
# 278 "data/maps/PalletTown/scripts.pory"
    walk_right
# 279 "data/maps/PalletTown/scripts.pory"
    walk_right
# 280 "data/maps/PalletTown/scripts.pory"
    walk_right
# 281 "data/maps/PalletTown/scripts.pory"
    walk_right
# 282 "data/maps/PalletTown/scripts.pory"
    walk_right
# 283 "data/maps/PalletTown/scripts.pory"
	.endm
# 284 "data/maps/PalletTown/scripts.pory"

# 285 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakWalkToLabLeft::
# 286 "data/maps/PalletTown/scripts.pory"
	walk_right
# 287 "data/maps/PalletTown/scripts.pory"
    walk_right
# 288 "data/maps/PalletTown/scripts.pory"
    walk_right
# 289 "data/maps/PalletTown/scripts.pory"
    walk_right
# 290 "data/maps/PalletTown/scripts.pory"
    walk_right
# 291 "data/maps/PalletTown/scripts.pory"
    walk_right
# 292 "data/maps/PalletTown/scripts.pory"
    walk_right
# 293 "data/maps/PalletTown/scripts.pory"
    walk_down
# 294 "data/maps/PalletTown/scripts.pory"
    walk_down
# 295 "data/maps/PalletTown/scripts.pory"
    walk_down
# 296 "data/maps/PalletTown/scripts.pory"
    walk_down
# 297 "data/maps/PalletTown/scripts.pory"
    walk_right
# 298 "data/maps/PalletTown/scripts.pory"
    walk_right
# 299 "data/maps/PalletTown/scripts.pory"
    walk_right
# 300 "data/maps/PalletTown/scripts.pory"
    walk_right
# 301 "data/maps/PalletTown/scripts.pory"
    walk_right
# 302 "data/maps/PalletTown/scripts.pory"
    walk_right
# 303 "data/maps/PalletTown/scripts.pory"
    walk_right
# 304 "data/maps/PalletTown/scripts.pory"
    walk_right
# 305 "data/maps/PalletTown/scripts.pory"
    walk_right
# 306 "data/maps/PalletTown/scripts.pory"
    walk_right
# 307 "data/maps/PalletTown/scripts.pory"
	step_end
# 308 "data/maps/PalletTown/scripts.pory"

# 309 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakWalkToLabRight::
# 310 "data/maps/PalletTown/scripts.pory"
	walk_right
# 311 "data/maps/PalletTown/scripts.pory"
    walk_right
# 312 "data/maps/PalletTown/scripts.pory"
    walk_right
# 313 "data/maps/PalletTown/scripts.pory"
    walk_right
# 314 "data/maps/PalletTown/scripts.pory"
    walk_right
# 315 "data/maps/PalletTown/scripts.pory"
    walk_right
# 316 "data/maps/PalletTown/scripts.pory"
    walk_right
# 317 "data/maps/PalletTown/scripts.pory"
    walk_down
# 318 "data/maps/PalletTown/scripts.pory"
    walk_down
# 319 "data/maps/PalletTown/scripts.pory"
    walk_down
# 320 "data/maps/PalletTown/scripts.pory"
    walk_down
# 321 "data/maps/PalletTown/scripts.pory"
	walk_down
# 322 "data/maps/PalletTown/scripts.pory"
    walk_right
# 323 "data/maps/PalletTown/scripts.pory"
    walk_right
# 324 "data/maps/PalletTown/scripts.pory"
    walk_right
# 325 "data/maps/PalletTown/scripts.pory"
    walk_right
# 326 "data/maps/PalletTown/scripts.pory"
    walk_right
# 327 "data/maps/PalletTown/scripts.pory"
    walk_right
# 328 "data/maps/PalletTown/scripts.pory"
    walk_right
# 329 "data/maps/PalletTown/scripts.pory"
    walk_right
# 330 "data/maps/PalletTown/scripts.pory"
    walk_right
# 331 "data/maps/PalletTown/scripts.pory"
    walk_right
# 332 "data/maps/PalletTown/scripts.pory"
	step_end
# 333 "data/maps/PalletTown/scripts.pory"

# 334 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakEnterLab::
# 335 "data/maps/PalletTown/scripts.pory"
	walk_up
# 336 "data/maps/PalletTown/scripts.pory"
	set_invisible
# 337 "data/maps/PalletTown/scripts.pory"
	step_end
# 338 "data/maps/PalletTown/scripts.pory"

# 339 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerWalkToLabLeft::
# 340 "data/maps/PalletTown/scripts.pory"
walk_right
# 341 "data/maps/PalletTown/scripts.pory"
    walk_right
# 342 "data/maps/PalletTown/scripts.pory"
    walk_right
# 343 "data/maps/PalletTown/scripts.pory"
    walk_right
# 344 "data/maps/PalletTown/scripts.pory"
    walk_right
# 345 "data/maps/PalletTown/scripts.pory"
    walk_right
# 346 "data/maps/PalletTown/scripts.pory"
    walk_right
# 347 "data/maps/PalletTown/scripts.pory"
	walk_right
# 348 "data/maps/PalletTown/scripts.pory"
    walk_down
# 349 "data/maps/PalletTown/scripts.pory"
    walk_down
# 350 "data/maps/PalletTown/scripts.pory"
    walk_down
# 351 "data/maps/PalletTown/scripts.pory"
    walk_down
# 352 "data/maps/PalletTown/scripts.pory"
    walk_right
# 353 "data/maps/PalletTown/scripts.pory"
    walk_right
# 354 "data/maps/PalletTown/scripts.pory"
    walk_right
# 355 "data/maps/PalletTown/scripts.pory"
    walk_right
# 356 "data/maps/PalletTown/scripts.pory"
    walk_right
# 357 "data/maps/PalletTown/scripts.pory"
    walk_right
# 358 "data/maps/PalletTown/scripts.pory"
    walk_right
# 359 "data/maps/PalletTown/scripts.pory"
    walk_right
# 360 "data/maps/PalletTown/scripts.pory"
    walk_right
# 361 "data/maps/PalletTown/scripts.pory"
	step_end
# 362 "data/maps/PalletTown/scripts.pory"

# 363 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerWalkToLabRight::
# 364 "data/maps/PalletTown/scripts.pory"
    walk_right
# 365 "data/maps/PalletTown/scripts.pory"
    walk_right
# 366 "data/maps/PalletTown/scripts.pory"
    walk_right
# 367 "data/maps/PalletTown/scripts.pory"
    walk_right
# 368 "data/maps/PalletTown/scripts.pory"
    walk_right
# 369 "data/maps/PalletTown/scripts.pory"
    walk_right
# 370 "data/maps/PalletTown/scripts.pory"
	walk_right
# 371 "data/maps/PalletTown/scripts.pory"
	walk_right
# 372 "data/maps/PalletTown/scripts.pory"
    walk_down
# 373 "data/maps/PalletTown/scripts.pory"
    walk_down
# 374 "data/maps/PalletTown/scripts.pory"
    walk_down
# 375 "data/maps/PalletTown/scripts.pory"
    walk_down
# 376 "data/maps/PalletTown/scripts.pory"
	walk_down
# 377 "data/maps/PalletTown/scripts.pory"
    walk_right
# 378 "data/maps/PalletTown/scripts.pory"
    walk_right
# 379 "data/maps/PalletTown/scripts.pory"
    walk_right
# 380 "data/maps/PalletTown/scripts.pory"
    walk_right
# 381 "data/maps/PalletTown/scripts.pory"
    walk_right
# 382 "data/maps/PalletTown/scripts.pory"
    walk_right
# 383 "data/maps/PalletTown/scripts.pory"
    walk_right
# 384 "data/maps/PalletTown/scripts.pory"
    walk_right
# 385 "data/maps/PalletTown/scripts.pory"
    walk_right
# 386 "data/maps/PalletTown/scripts.pory"
	step_end
# 387 "data/maps/PalletTown/scripts.pory"

# 388 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerEnterLab::
# 389 "data/maps/PalletTown/scripts.pory"
	walk_right
# 390 "data/maps/PalletTown/scripts.pory"
	walk_up
# 391 "data/maps/PalletTown/scripts.pory"
	set_invisible
# 392 "data/maps/PalletTown/scripts.pory"
	step_end
# 393 "data/maps/PalletTown/scripts.pory"

# 394 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_FatMan::
# 395 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_CanStoreItemsAndMonsInPC, MSGBOX_NPC
# 396 "data/maps/PalletTown/scripts.pory"
	end
# 397 "data/maps/PalletTown/scripts.pory"

# 398 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OaksLabSign::
# 399 "data/maps/PalletTown/scripts.pory"
	lockall
# 400 "data/maps/PalletTown/scripts.pory"
	famechecker FAMECHECKER_OAK, 0
# 401 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OakPokemonResearchLab
# 402 "data/maps/PalletTown/scripts.pory"
	releaseall
# 403 "data/maps/PalletTown/scripts.pory"
	end
# 404 "data/maps/PalletTown/scripts.pory"

# 405 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_PlayersHouseSign::
# 406 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_PlayersHouse, MSGBOX_SIGN
# 407 "data/maps/PalletTown/scripts.pory"
	end
# 408 "data/maps/PalletTown/scripts.pory"

# 409 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_RivalsHouseSign::
# 410 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_RivalsHouse, MSGBOX_SIGN
# 411 "data/maps/PalletTown/scripts.pory"
	end
# 412 "data/maps/PalletTown/scripts.pory"

# 413 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_TownSign::
# 414 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_TownSign, MSGBOX_SIGN
# 415 "data/maps/PalletTown/scripts.pory"
	end
# 416 "data/maps/PalletTown/scripts.pory"

# 417 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_BagGirl::
# 418 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_BagGirl, MSGBOX_NPC
# 419 "data/maps/PalletTown/scripts.pory"
	end
