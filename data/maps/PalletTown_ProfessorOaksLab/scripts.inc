# 1 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 2 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ LOCALID_PROF_OAK,        3
# 3 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ LOCALID_BULBASAUR_BALL,  1
# 4 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ LOCALID_SQUIRTLE_BALL,   2
# 5 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ LOCALID_CHARMANDER_BALL, 3
# 6 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ LOCALID_RIVAL,           4
# 7 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ LOCALID_POKEDEX_1,       9
# 8 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ LOCALID_POKEDEX_2,       10
# 9 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 10 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ PLAYER_STARTER_NUM,      VAR_TEMP_1
# 11 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ PLAYER_STARTER_SPECIES,  VAR_TEMP_2
# 12 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ RIVAL_STARTER_SPECIES,   VAR_TEMP_3
# 13 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ RIVAL_STARTER_ID,        VAR_TEMP_4
# 14 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 15 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
.equ SHOWED_OAK_COMPLETE_DEX, FLAG_TEMP_2
# 16 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 17 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_MapScripts::
# 18 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_ProfessorOaksLab_OnTransition
# 19 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PalletTown_ProfessorOaksLab_OnWarp
# 20 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_ProfessorOaksLab_OnFrame
# 21 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	.byte 0
# 22 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 23 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_OnTransition::
# 24 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_VISITED_OAKS_LAB
# 25 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PalletTown_ProfessorOaksLab_EventScript_ReadyOakForStarterScene
# 26 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 7, PalletTown_ProfessorOaksLab_EventScript_ReadyOakForNationalDexScene
# 27 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 8, PalletTown_ProfessorOaksLab_EventScript_SetNationalDexSceneFinished
# 28 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_set FLAG_GOT_POKEBALLS_FROM_OAK_AFTER_22_RIVAL, PalletTown_ProfessorOaksLab_EventScript_SetSkipPokeBallCheck
# 29 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 30 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 31 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_SetSkipPokeBallCheck::
# 32 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_OAK_SKIP_22_RIVAL_CHECK
# 33 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 34 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 35 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_SetNationalDexSceneFinished::
# 36 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 9
# 37 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 38 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 39 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ReadyOakForStarterScene::
# 40 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_PROF_OAK, 6, 11
# 41 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectmovementtype LOCALID_PROF_OAK, MOVEMENT_TYPE_FACE_UP
# 42 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	savebgm MUS_OAK
# 43 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 44 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 45 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ReadyOakForNationalDexScene::
# 46 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_PROF_OAK, 6, 11
# 47 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectmovementtype LOCALID_PROF_OAK, MOVEMENT_TYPE_FACE_UP
# 48 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 49 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 50 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_OnWarp::
# 51 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PalletTown_ProfessorOaksLab_EventScript_ReadyPlayerForStarterScene
# 52 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	.2byte 0
# 53 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 54 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ReadyPlayerForStarterScene::
# 55 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
# 56 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 57 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 58 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_OnFrame::
# 59 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1, PalletTown_ProfessorOaksLab_ChooseStarterScene
# 60 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 7, PalletTown_ProfessorOaksLab_EventScript_EnterForNationalDexScene
# 61 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	.2byte 0
# 62 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 63 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_EnterForNationalDexScene:: @ 8169002 
# 64 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 65 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_FACING, DIR_NORTH
# 66 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 67 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakEnter
# 68 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 69 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_PROF_OAK
# 70 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_PROF_OAK, 6, 3
# 71 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectmovementtype LOCALID_PROF_OAK, MOVEMENT_TYPE_FACE_DOWN
# 72 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
# 73 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerEnter
# 74 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 75 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_NationalDexScene
# 76 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 77 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 78 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_NationalDexScene::
# 79 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakSightingsOfRareMons
# 80 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 81 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterNorth
# 82 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterSouth
# 83 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterEastWest
# 84 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterEastWest
# 85 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalJustLetMeHandleEverything
# 86 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	fadedefaultbgm
# 87 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakNeedYourHelpTooNeedToSeePokedexes
# 88 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_PlayerFaceOakNorth
# 89 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_PlayerFaceOakWest
# 90 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 91 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakTookBothPokedexUnits
# 92 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 93 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call EventScript_RestorePrevTextColor
# 94 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskNorth
# 95 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskSouth
# 96 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskEast
# 97 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskWest
# 98 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_POKEDEX_1
# 99 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_POKEDEX_2
# 100 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 30
# 101 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakNowTheseUnitsCanRecordMoreData
# 102 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 103 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_POKEDEX_1
# 104 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_POKEDEX_2
# 105 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 30
# 106 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverNorth
# 107 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverSouth
# 108 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverEast
# 109 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverWest
# 110 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 111 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 112 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	message PalletTown_ProfessorOaksLab_Text_PlayersPokedexWasUpgraded
# 113 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmessage
# 114 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitfanfare
# 115 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call EventScript_RestorePrevTextColor
# 116 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	special EnableNationalPokedex
# 117 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakMustReallyWorkToFillPokedex
# 118 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalIllCompleteThePokedex
# 119 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 120 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_RIVAL_EXIT, 0
# 121 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_RivalExitNorth
# 122 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_RivalExit
# 123 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_RivalExit
# 124 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_RivalExit
# 125 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_RIVAL
# 126 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	fadedefaultbgm
# 127 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 8
# 128 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	releaseall
# 129 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 130 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 131 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterNorth::
# 132 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 5, 10
# 133 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_RIVAL
# 134 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 135 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterNorth
# 136 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalEnter
# 137 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 138 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 139 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 140 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterEastWest::
# 141 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 6, 10
# 142 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_RIVAL
# 143 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 144 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 145 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterEastWest
# 146 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalEnter
# 147 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 148 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 149 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 150 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_NationalDexSceneRivalEnterSouth::
# 151 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 6, 10
# 152 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_RIVAL
# 153 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 154 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 155 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalEnter
# 156 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 157 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 158 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 159 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_PlayerFaceOakNorth::
# 160 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 161 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 162 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 163 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 164 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_PlayerFaceOakWest::
# 165 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 166 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 167 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 168 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 169 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskNorth::
# 170 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesToDesk
# 171 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 172 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 173 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 174 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskSouth::
# 175 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesToDeskSouth
# 176 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDesk
# 177 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDesk
# 178 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement LOCALID_PROF_OAK
# 179 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 180 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 181 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskEast::
# 182 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesToDesk
# 183 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDeskEast
# 184 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement LOCALID_PROF_OAK
# 185 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 186 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 187 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesToDeskWest::
# 188 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesToDesk
# 189 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 190 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 191 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 192 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakBringDexesToDesk::
# 193 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 194 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 195 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_up
# 196 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 197 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_4
# 198 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 199 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 200 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakBringDexesToDeskSouth::
# 201 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 202 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 203 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 204 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 205 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_4
# 206 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 207 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 208 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_ChooseStarterScene::
# 209 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 210 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2
# 211 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakEnter
# 212 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 213 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_PROF_OAK
# 214 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_HIDE_OAK_IN_HIS_LAB
# 215 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_PROF_OAK, 6, 3
# 216 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectmovementtype LOCALID_PROF_OAK, MOVEMENT_TYPE_FACE_DOWN
# 217 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	clearflag FLAG_DONT_TRANSITION_MUSIC
# 218 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	savebgm MUS_DUMMY
# 219 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	fadedefaultbgm
# 220 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerEnter
# 221 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement OBJ_EVENT_ID_PLAYER
# 222 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	warp MAP_PALLET_TOWN_OAK_OFFICE, 0, 5, 10
# 223 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitstate
# 224 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	releaseall
# 225 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 226 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 227 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakEnter::
# 228 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 229 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 230 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 231 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 232 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 233 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 234 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 235 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 236 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 237 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 238 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 239 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_PlayerEnter::
# 240 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 241 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 242 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 243 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 244 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 245 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 246 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 247 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 248 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 249 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 250 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 251 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 252 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 253 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalReact::
# 254 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_up
# 255 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_up
# 256 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 257 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 258 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_LeaveStarterSceneTrigger::
# 259 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 260 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 261 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_FaceDown
# 262 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 263 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakHeyDontGoAwayYet
# 264 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 265 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerWalkUp
# 266 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 267 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	releaseall
# 268 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 269 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 270 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_PlayerWalkUp::
# 271 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 272 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 273 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 274 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattleTriggerLeft::
# 275 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 276 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_TEMP_2, 1
# 277 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattle
# 278 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 279 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 280 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattleTriggerMid::
# 281 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 282 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_TEMP_2, 2
# 283 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattle
# 284 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 285 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 286 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattleTriggerRight::
# 287 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 288 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_TEMP_2, 3
# 289 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattle
# 290 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 291 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 292 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattle::
# 293 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 294 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 295 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm 4, 6, 1
# 296 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_DOWN
# 297 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject 4
# 298 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement 4, Common_Movement_WalkInPlaceFasterDown
# 299 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 300 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 301 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 302 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 303 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_STARTER_MON, 0, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmander
# 304 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_STARTER_MON, 1, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaur
# 305 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_STARTER_MON, 2, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtle
# 306 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 307 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 308 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
@ The scripts for the rival approaching the player for battle are a bit bloated because
# 309 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
@ both the player and rival can be in 3 different positions, so theres 9 different approaches
# 310 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
@ NOTE: Names below refer to the Rival's mon (e.g. for RivalBattleSquirtle, player has Charmander)
# 311 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 312 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtle::
# 313 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 1, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtleLeft
# 314 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 2, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtleMid
# 315 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 3, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtleRight
# 316 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 317 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 318 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtleLeft::
# 319 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement 4, PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleSquirtleLeft
# 320 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 321 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalLetsCheckOutMons
# 322 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleSquirtle
# 323 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 324 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 325 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtleMid::
# 326 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement 4, PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleSquirtleMid
# 327 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 328 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalLetsCheckOutMons	
# 329 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleSquirtle
# 330 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 331 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 332 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleSquirtleRight::
# 333 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement 4, PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleSquirtleRight
# 334 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 335 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalLetsCheckOutMons
# 336 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleSquirtle
# 337 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 338 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 339 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattleSquirtle::
# 340 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	trainerbattle_earlyrival TRAINER_RIVAL_OAKS_LAB_SQUIRTLE, RIVAL_BATTLE_TUTORIAL, PalletTown_ProfessorOaksLab_Text_RivalDefeat, Text_RivalVictory
# 341 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_EndRivalBattle
# 342 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 343 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 344 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleSquirtleLeft::
# 345 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 346 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 347 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 348 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 349 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 350 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 351 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 352 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	face_down
# 353 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 354 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 355 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleSquirtleMid::
# 356 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 357 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 358 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 359 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 360 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 361 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 362 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 363 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 364 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleSquirtleRight::
# 365 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 366 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 367 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 368 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 369 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 370 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 371 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 372 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	face_down
# 373 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 374 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 375 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmander::
# 376 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 1, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmanderLeft
# 377 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 2, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmanderMid
# 378 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 3, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmanderRight
# 379 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 380 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 381 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmanderLeft::
# 382 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement 4, PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleCharmanderLeft
# 383 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 384 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalLetsCheckOutMons
# 385 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleCharmander
# 386 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 387 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 388 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmanderMid::
# 389 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement 4, PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleCharmanderMid
# 390 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 391 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalLetsCheckOutMons
# 392 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleCharmander
# 393 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 394 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 395 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleCharmanderRight::
# 396 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement 4, PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleCharmanderRight
# 397 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 398 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalLetsCheckOutMons
# 399 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleCharmander
# 400 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 401 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 402 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattleCharmander::
# 403 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	trainerbattle_earlyrival TRAINER_RIVAL_OAKS_LAB_CHARMANDER, RIVAL_BATTLE_TUTORIAL, PalletTown_ProfessorOaksLab_Text_RivalDefeat, Text_RivalVictory
# 404 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_EndRivalBattle
# 405 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 406 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 407 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleCharmanderLeft::
# 408 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 409 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 410 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 411 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 412 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 413 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 414 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 415 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	face_down
# 416 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 417 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 418 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleCharmanderMid::
# 419 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 420 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 421 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 422 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 423 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 424 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 425 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 426 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 427 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleCharmanderRight::
# 428 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 429 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 430 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 431 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 432 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 433 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 434 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 435 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	face_down
# 436 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 437 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 438 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaur::
# 439 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 1, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaurLeft
# 440 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 2, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaurMid
# 441 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_TEMP_2, 3, PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaurRight
# 442 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 443 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 444 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaurLeft::
# 445 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement 4, PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleBulbasaurLeft
# 446 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 447 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalLetsCheckOutMons
# 448 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleBulbasaur
# 449 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 450 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 451 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaurMid::
# 452 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement 4, PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleBulbasaurMid
# 453 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 454 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalLetsCheckOutMons
# 455 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleBulbasaur
# 456 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 457 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 458 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalApproachForBattleBulbasaurRight::
# 459 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement 4, PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleBulbasaurRight
# 460 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 461 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalLetsCheckOutMons
# 462 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalBattleBulbasaur
# 463 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 464 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 465 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalBattleBulbasaur::
# 466 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	trainerbattle_earlyrival TRAINER_RIVAL_OAKS_LAB_BULBASAUR, RIVAL_BATTLE_TUTORIAL, PalletTown_ProfessorOaksLab_Text_RivalDefeat, Text_RivalVictory
# 467 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_EndRivalBattle
# 468 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 469 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 470 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleBulbasaurLeft::
# 471 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 472 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 473 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 474 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 475 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 476 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 477 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 478 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	face_down
# 479 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 480 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 481 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleBulbasaurMid::
# 482 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 483 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 484 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 485 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 486 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 487 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 488 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 489 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 490 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalApproachForBattleBulbasaurRight::
# 491 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 492 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 493 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 494 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 495 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 496 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 497 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 498 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	face_down
# 499 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 500 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 501 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_EndRivalBattle::
# 502 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	special HealPlayerParty
# 503 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGoToughenMyMon
# 504 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 505 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_RIVAL_EXIT, 0
# 506 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_TEMP_2, 1, PalletTown_ProfessorOaksLab_EventScript_RivalExitAfterBattleLeft
# 507 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_TEMP_2, 2, PalletTown_ProfessorOaksLab_EventScript_RivalExitAfterBattleMid
# 508 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_TEMP_2, 3, PalletTown_ProfessorOaksLab_EventScript_RivalExitAfterBattleRight
# 509 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_RIVAL
# 510 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playse SE_EXIT
# 511 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	fadedefaultbgm
# 512 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 4
# 513 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_DAISY, 1
# 514 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_BEAT_RIVAL_IN_OAKS_LAB
# 515 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	releaseall
# 516 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 517 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 518 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalExitAfterBattleLeft::
# 519 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement 4, PalletTown_ProfessorOaksLab_Movement_RivalExitAfterBattleLeft
# 520 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerWatchRivalExitAfterBattle
# 521 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 4
# 522 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 523 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 524 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalExitAfterBattleMid::
# 525 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement 4, PalletTown_ProfessorOaksLab_Movement_RivalExitAfterBattleMid
# 526 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerWatchRivalExitAfterBattle
# 527 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 4
# 528 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 529 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 530 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalExitAfterBattleRight::
# 531 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement 4, PalletTown_ProfessorOaksLab_Movement_RivalExitAfterBattleRight
# 532 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerWatchRivalExitAfterBattleRight
# 533 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 4
# 534 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 535 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 536 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalExitAfterBattleLeft::
# 537 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 538 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 539 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 540 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 541 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 542 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 543 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 544 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 545 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 546 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalExitAfterBattleRight::
# 547 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 548 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 549 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 550 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 551 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 552 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 553 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 554 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 555 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 556 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalExitAfterBattleMid::
# 557 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 558 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 559 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 560 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 561 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 562 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 563 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 564 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 565 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 566 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 567 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_PlayerWatchRivalExitAfterBattle::
# 568 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 569 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 570 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_right
# 571 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 572 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 573 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 574 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 575 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_PlayerWatchRivalExitAfterBattleRight::
# 576 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 577 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 578 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_left
# 579 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 580 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 581 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 582 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 583 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Rival::
# 584 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 585 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 586 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3, PalletTown_ProfessorOaksLab_EventScript_RivalChoseStarter
# 587 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2, PalletTown_ProfessorOaksLab_EventScript_RivalWaitingForStarter
# 588 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGrampsIsntAround
# 589 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 590 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 591 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 592 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalWaitingForStarter::
# 593 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGoChoosePlayer
# 594 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 595 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 596 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 597 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalChoseStarter::
# 598 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalMyMonLooksTougher
# 599 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 600 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 601 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 602 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ProfOak::
# 603 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 604 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 605 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set SHOWED_OAK_COMPLETE_DEX, PalletTown_ProfessorOaksLab_EventScript_OakJustShownCompleteDex
# 606 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 9, PalletTown_ProfessorOaksLab_EventScript_RatePokedex
# 607 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 8, PalletTown_ProfessorOaksLab_EventScript_MonsAroundWorldWait
# 608 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, PalletTown_ProfessorOaksLab_EventScript_TryStartNationalDexScene
# 609 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_CERULEAN_CITY_RIVAL, 1, PalletTown_ProfessorOaksLab_EventScript_RatePokedex
# 610 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, PalletTown_ProfessorOaksLab_EventScript_RatePokedexOrTryGiveBalls
# 611 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_MART, 1, PalletTown_ProfessorOaksLab_EventScript_ReceiveDexScene
# 612 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 4, PalletTown_ProfessorOaksLab_EventScript_OakBattleMonForItToGrow
# 613 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3, PalletTown_ProfessorOaksLab_EventScript_OakCanReachNextTownWithMon
# 614 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakWhichOneWillYouChoose
# 615 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 616 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 617 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 618 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakJustShownCompleteDex::
# 619 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PokedexRating_Text_ThankYouMadeDreamReality
# 620 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 621 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 622 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 623 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakCanReachNextTownWithMon::
# 624 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakCanReachNextTownWithMon
# 625 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 626 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 627 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 628 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBattleMonForItToGrow::
# 629 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakBattleMonForItToGrow
# 630 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 631 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 632 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 633 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ReceiveDexScene::
# 634 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakHaveSomethingForMe
# 635 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 636 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playfanfare MUS_OBTAIN_TMHM
# 637 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	message PalletTown_ProfessorOaksLab_Text_DeliveredOaksParcel
# 638 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmessage
# 639 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitfanfare
# 640 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call EventScript_RestorePrevTextColor
# 641 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeitem ITEM_OAKS_PARCEL
# 642 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakCustomBallIOrdered
# 643 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 644 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalGramps
# 645 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 646 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterNorth
# 647 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterSouth
# 648 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterEastWest
# 649 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterEastWest
# 650 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	fadedefaultbgm
# 651 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalWhatDidYouCallMeFor
# 652 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 653 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 30
# 654 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playse SE_PIN
# 655 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_ExclamationMark
# 656 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 657 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_Delay48
# 658 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 659 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalSouth
# 660 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalEast
# 661 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalWest
# 662 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalNorth
# 663 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakHaveRequestForYouTwo
# 664 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 665 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskNorth
# 666 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskSouth
# 667 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskEast
# 668 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskWest
# 669 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakPokedexOnDesk
# 670 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 671 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 40
# 672 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakTakeTheseWithYou
# 673 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 674 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterUp
# 675 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 676 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_POKEDEX_1
# 677 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 10
# 678 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_POKEDEX_2
# 679 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 25
# 680 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverNorth
# 681 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverSouth
# 682 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverEast
# 683 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverWest
# 684 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 10
# 685 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 686 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 687 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	message PalletTown_ProfessorOaksLab_Text_ReceivedPokedexFromOak
# 688 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmessage
# 689 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitfanfare
# 690 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call EventScript_RestorePrevTextColor
# 691 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_SYS_POKEDEX_GET
# 692 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	special SetUnlockedPokedexFlags
# 693 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_POKEMON_CENTER_TEALA, 1
# 694 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakCatchMonsForDataTakeThese
# 695 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	giveitem_msg PalletTown_ProfessorOaksLab_Text_ReceivedFivePokeBalls, ITEM_POKE_BALL, 5
# 696 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakExplainCatching
# 697 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	famechecker FAMECHECKER_OAK, 1
# 698 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakCompleteMonGuideWasMyDream
# 699 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalLeaveItToMeGramps
# 700 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerNorth
# 701 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerSouth
# 702 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerEastWest
# 703 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerEastWest
# 704 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalTellSisNotToGiveYouMap
# 705 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 706 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playbgm MUS_RIVAL_EXIT, 0
# 707 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_RivalExitNorth
# 708 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_RivalExit
# 709 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_RivalExit
# 710 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_RivalExit
# 711 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject LOCALID_RIVAL
# 712 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	fadedefaultbgm
# 713 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6
# 714 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_MART, 2
# 715 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1
# 716 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 1
# 717 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_ROUTE22, 1
# 718 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 719 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 720 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 721 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverNorth::
# 722 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesOver
# 723 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 724 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 725 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 726 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverSouth::
# 727 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesOverSouth
# 728 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 729 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 730 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 731 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverEast::
# 732 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesOver
# 733 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_PlayerFaceOakForDexEast
# 734 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 735 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 736 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 737 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakBringDexesOverWest::
# 738 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakBringDexesOver
# 739 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 740 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 741 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 742 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_PlayerFaceOakForDexEast::
# 743 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 744 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 745 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_right
# 746 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 747 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 748 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakBringDexesOver::
# 749 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 750 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 751 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 752 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 753 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakBringDexesOverSouth::
# 754 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 755 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 756 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 757 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 758 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskNorth::
# 759 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakWalkToDesk
# 760 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 761 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 762 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 763 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskSouth::
# 764 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakWalkToDeskSouth
# 765 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDesk
# 766 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDesk
# 767 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement LOCALID_PROF_OAK
# 768 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 769 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 770 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskEast::
# 771 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakWalkToDesk
# 772 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDeskEast
# 773 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement LOCALID_PROF_OAK
# 774 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 775 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 776 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakWalkToDeskWest::
# 777 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakWalkToDesk
# 778 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 779 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 780 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 781 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDeskEast::
# 782 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 783 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 784 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_up
# 785 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 786 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 787 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_WatchOakWalkToDesk::
# 788 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 789 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 790 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_left
# 791 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 792 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 793 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakWalkToDesk::
# 794 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 795 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 796 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 797 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 798 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 799 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 800 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakWalkToDeskSouth::
# 801 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 802 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 803 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 804 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 805 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_right
# 806 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 807 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 808 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RatePokedexOrTryGiveBalls::
# 809 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_0x8004, 0
# 810 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	specialvar VAR_RESULT, GetPokedexCount
# 811 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 812 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	copyvar VAR_0x8009, VAR_0x8006
# 813 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8008
# 814 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_0x8009
# 815 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_0x8009, 1, PalletTown_ProfessorOaksLab_EventScript_CheckIfPlayerNeedsBalls  @ Player only has starter
# 816 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RatePokedex
# 817 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 818 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 819 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RatePokedex::
# 820 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call PokedexRating_EventScript_RateInPerson
# 821 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set FLAG_OAK_SAW_DEX_COMPLETION, PalletTown_ProfessorOaksLab_EventScript_DexCompleted
# 822 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 823 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 824 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 825 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexCompleted::
# 826 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 827 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 40
# 828 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	message PokedexRating_Text_Wroooaaarrr
# 829 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmessage
# 830 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PalletTown_ProfessorOaksLab_EventScript_OakExcitedNorth
# 831 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PalletTown_ProfessorOaksLab_EventScript_OakExcitedSouth
# 832 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_ProfessorOaksLab_EventScript_OakExcitedEast
# 833 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PalletTown_ProfessorOaksLab_EventScript_OakExcitedWest
# 834 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_FacePlayer
# 835 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 836 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 837 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 70
# 838 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PokedexRating_Text_ThankYouMadeDreamReality
# 839 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag SHOWED_OAK_COMPLETE_DEX
# 840 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 841 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 842 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 843 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakExcitedNorth::
# 844 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakExcitedNorth
# 845 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 846 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 847 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 848 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakExcitedSouth::
# 849 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakExcitedSouth
# 850 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 851 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 852 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 853 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakExcitedEast::
# 854 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakExcitedEast
# 855 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 856 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 857 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 858 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_OakExcitedWest::
# 859 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, PalletTown_ProfessorOaksLab_Movement_OakExcitedWest
# 860 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 861 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 862 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 863 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakExcitedNorth::
# 864 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_down
# 865 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_down
# 866 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_down
# 867 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_down
# 868 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_down
# 869 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_down
# 870 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 871 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 872 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakExcitedSouth::
# 873 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_up
# 874 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_up
# 875 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_up
# 876 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_up
# 877 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_up
# 878 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_up
# 879 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 880 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 881 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakExcitedEast::
# 882 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_left
# 883 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_left
# 884 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_left
# 885 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_left
# 886 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_left
# 887 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_left
# 888 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 889 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 890 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_OakExcitedWest::
# 891 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_right
# 892 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_right
# 893 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_right
# 894 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_right
# 895 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_fast_right
# 896 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_right
# 897 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 898 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 899 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
@ Unused
# 900 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_Search:
# 901 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 902 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 903 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 904 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_right
# 905 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 906 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_up
# 907 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 908 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_left
# 909 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 910 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 911 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 912 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 913 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_right
# 914 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_up
# 915 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 916 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_left
# 917 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 918 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 919 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 920 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_right
# 921 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 922 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_up
# 923 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 924 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 925 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 926 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 927 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
@ Unused
# 928 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_VerticalPacing:
# 929 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 930 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 931 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 932 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_down
# 933 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 934 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 935 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 936 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 937 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 938 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 939 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_TryStartNationalDexScene::
# 940 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call PokedexRating_EventScript_RateInPerson
# 941 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 942 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_lt VAR_0x8009, 60, PalletTown_ProfessorOaksLab_EventScript_DontStartNationalDexScene
# 943 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_unset FLAG_WORLD_MAP_ONE_ISLAND, PalletTown_ProfessorOaksLab_EventScript_DontStartNationalDexScene
# 944 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 30
# 945 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakFavorToAskYouPlayer
# 946 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_NationalDexScene
# 947 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 948 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 949 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DontStartNationalDexScene::
# 950 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 951 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 952 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 953 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_CheckIfPlayerNeedsBalls::
# 954 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 955 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	special QuestLog_CutRecording
# 956 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set FLAG_OAK_SKIP_22_RIVAL_CHECK, PalletTown_ProfessorOaksLab_EventScript_MonsAroundWorldWait
# 957 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set FLAG_GOT_POKEBALLS_FROM_OAK_AFTER_22_RIVAL, PalletTown_ProfessorOaksLab_EventScript_PlayerAlreadyGotBalls
# 958 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	checkitem ITEM_POKE_BALL
# 959 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PalletTown_ProfessorOaksLab_EventScript_PlayerOutOfBalls
# 960 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_MonsAroundWorldWait
# 961 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 962 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 963 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_PlayerOutOfBalls::
# 964 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ROUTE22, 2, PalletTown_ProfessorOaksLab_EventScript_GivePlayerMoreBalls
# 965 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_MonsAroundWorldWait
# 966 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 967 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 968 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_GivePlayerMoreBalls::
# 969 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakAddedNothingToPokedex
# 970 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	giveitem_msg PalletTown_ProfessorOaksLab_Text_ReceivedFivePokeBalls, ITEM_POKE_BALL, 5
# 971 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_GOT_POKEBALLS_FROM_OAK_AFTER_22_RIVAL
# 972 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 973 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 974 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 975 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_MonsAroundWorldWait::
# 976 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakMonsAroundWorldWait
# 977 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 978 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 979 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 980 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_PlayerAlreadyGotBalls::
# 981 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakComeSeeMeSometime
# 982 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 983 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 984 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 985 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterNorth::
# 986 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 5, 10
# 987 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_RIVAL
# 988 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterNorth
# 989 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalEnter
# 990 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 991 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 992 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 993 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterEastWest::
# 994 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 6, 10
# 995 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_RIVAL
# 996 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 997 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterEastWest
# 998 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalEnter
# 999 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1000 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1001 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1002 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalEnterSouth::
# 1003 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setobjectxyperm LOCALID_RIVAL, 6, 10
# 1004 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	addobject LOCALID_RIVAL
# 1005 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 1006 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalEnter
# 1007 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1008 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1009 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1010 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalSouth::
# 1011 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_FacePlayer
# 1012 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1013 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 15
# 1014 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 1015 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1016 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1017 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1018 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalWest::
# 1019 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_FacePlayer
# 1020 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1021 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 15
# 1022 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 1023 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 1024 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1025 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1026 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1027 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalEast::
# 1028 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_FacePlayer
# 1029 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1030 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay 15
# 1031 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 1032 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_WalkInPlaceFasterDown
# 1033 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1034 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1035 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1036 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerNorth::
# 1037 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 1038 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 1039 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1040 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1041 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1042 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerSouth::
# 1043 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
# 1044 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 1045 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1046 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1047 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1048 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneRivalFacePlayerEastWest::
# 1049 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
# 1050 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 1051 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1052 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1053 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1054 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalExitNorth::
# 1055 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterEastWest
# 1056 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalExit
# 1057 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1058 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1059 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1060 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalExit::
# 1061 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_RIVAL, PalletTown_ProfessorOaksLab_Movement_RivalExit
# 1062 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1063 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1064 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1065 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DexSceneOakFacePlayerAndRivalNorth::
# 1066 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 1067 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1068 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1069 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1070 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterEastWest::
# 1071 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_4
# 1072 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 1073 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1074 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1075 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_WatchRivalEnterNorth::
# 1076 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_down
# 1077 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 1078 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 1079 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 1080 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 1081 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_16
# 1082 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	delay_8
# 1083 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_in_place_faster_left
# 1084 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1085 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1086 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalEnter::
# 1087 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1088 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1089 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1090 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1091 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1092 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1093 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1094 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1095 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalExit::
# 1096 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1097 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1098 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1099 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1100 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1101 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_down
# 1102 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1103 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1104 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_BulbasaurBall::
# 1105 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 1106 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 1107 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar PLAYER_STARTER_NUM, 0
# 1108 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar PLAYER_STARTER_SPECIES, SPECIES_CHIKORITA
# 1109 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar RIVAL_STARTER_SPECIES, SPECIES_FLAMEBEAR
# 1110 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar RIVAL_STARTER_ID, LOCALID_CHARMANDER_BALL
# 1111 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3, PalletTown_ProfessorOaksLab_EventScript_LastPokeBall
# 1112 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2, PalletTown_ProfessorOaksLab_EventScript_ConfirmStarterChoice
# 1113 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_ThoseArePokeBalls
# 1114 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1115 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1116 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1117 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ConfirmStarterChoice::
# 1118 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement LOCALID_PROF_OAK, Common_Movement_FaceRight
# 1119 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 0
# 1120 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
# 1121 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 1122 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq PLAYER_STARTER_NUM, 0, PalletTown_ProfessorOaksLab_EventScript_ConfirmBulbasaur
# 1123 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq PLAYER_STARTER_NUM, 1, PalletTown_ProfessorOaksLab_EventScript_ConfirmSquirtle
# 1124 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq PLAYER_STARTER_NUM, 2, PalletTown_ProfessorOaksLab_EventScript_ConfirmCharmander
# 1125 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1126 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1127 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ConfirmBulbasaur::
# 1128 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakChoosingBulbasaur, MSGBOX_YESNO
# 1129 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PalletTown_ProfessorOaksLab_EventScript_ChoseStarter
# 1130 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PalletTown_ProfessorOaksLab_EventScript_DeclinedStarter
# 1131 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1132 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1133 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ConfirmSquirtle::
# 1134 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakChoosingSquirtle, MSGBOX_YESNO
# 1135 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PalletTown_ProfessorOaksLab_EventScript_ChoseStarter
# 1136 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PalletTown_ProfessorOaksLab_EventScript_DeclinedStarter
# 1137 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1138 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1139 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ConfirmCharmander::
# 1140 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakChoosingCharmander, MSGBOX_YESNO
# 1141 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PalletTown_ProfessorOaksLab_EventScript_ChoseStarter
# 1142 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PalletTown_ProfessorOaksLab_EventScript_DeclinedStarter
# 1143 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1144 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1145 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_DeclinedStarter::
# 1146 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	hidemonpic
# 1147 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1148 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1149 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1150 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ChoseStarter::
# 1151 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	hidemonpic
# 1152 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject VAR_LAST_TALKED
# 1153 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakThisMonIsEnergetic
# 1154 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call EventScript_RestorePrevTextColor
# 1155 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_SYS_POKEMON_GET
# 1156 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_PALLET_LADY_NOT_BLOCKING_SIGN
# 1157 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	givemon PLAYER_STARTER_SPECIES, 5
# 1158 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	copyvar VAR_STARTER_MON, PLAYER_STARTER_NUM
# 1159 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
# 1160 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	message PalletTown_ProfessorOaksLab_Text_ReceivedMonFromOak
# 1161 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmessage
# 1162 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 1163 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitfanfare
# 1164 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 1165 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, YES, EventScript_GiveNicknameToStarter
# 1166 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_RESULT, NO, PalletTown_ProfessorOaksLab_EventScript_RivalPicksStarter
# 1167 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1168 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1169 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
EventScript_GiveNicknameToStarter::
# 1170 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_0x8004, 0
# 1171 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call EventScript_ChangePokemonNickname
# 1172 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalPicksStarter
# 1173 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1174 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1175 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalPicksStarter::
# 1176 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	closemessage
# 1177 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq PLAYER_STARTER_NUM, 0, PalletTown_ProfessorOaksLab_EventScript_RivalWalksToCharmander
# 1178 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq PLAYER_STARTER_NUM, 1, PalletTown_ProfessorOaksLab_EventScript_RivalWalksToBulbasaur
# 1179 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq PLAYER_STARTER_NUM, 2, PalletTown_ProfessorOaksLab_EventScript_RivalWalksToSquirtle
# 1180 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1181 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1182 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalWalksToCharmander::
# 1183 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement 7, PalletTown_ProfessorOaksLab_Movement_RivalWalksToCharmander
# 1184 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 7
# 1185 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalTakesStarter
# 1186 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1187 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1188 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalWalksToSquirtle::
# 1189 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement 7, PalletTown_ProfessorOaksLab_Movement_RivalWalksToSquirtle
# 1190 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 7
# 1191 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalTakesStarter
# 1192 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1193 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1194 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalWalksToBulbasaur::
# 1195 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	applymovement 7, PalletTown_ProfessorOaksLab_Movement_RivalWalksToBulbasaur
# 1196 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmovement 7
# 1197 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto PalletTown_ProfessorOaksLab_EventScript_RivalTakesStarter
# 1198 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1199 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1200 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RivalTakesStarter::
# 1201 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 1202 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_RivalIllTakeThisOneThen
# 1203 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	removeobject RIVAL_STARTER_ID
# 1204 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 1205 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	bufferspeciesname STR_VAR_1, RIVAL_STARTER_SPECIES
# 1206 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	message PalletTown_ProfessorOaksLab_Text_RivalReceivedMonFromOak
# 1207 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitmessage
# 1208 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	playfanfare MUS_OBTAIN_KEY_ITEM
# 1209 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	waitfanfare
# 1210 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3
# 1211 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	call_if_set FLAG_OPENED_START_MENU, PalletTown_ProfessorOaksLab_EventScript_ReadyEndSignLadyScene
# 1212 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setflag FLAG_SYS_NATIONAL_DEX
# 1213 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1214 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1215 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1216 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_ReadyEndSignLadyScene::
# 1217 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
# 1218 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	return
# 1219 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1220 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalWalksToCharmander::
# 1221 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1222 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1223 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1224 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1225 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalWalksToSquirtle::
# 1226 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1227 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 1228 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1229 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1230 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1231 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_Movement_RivalWalksToBulbasaur::
# 1232 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1233 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 1234 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_left
# 1235 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	walk_up
# 1236 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	step_end
# 1237 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1238 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_SquirtleBall::
# 1239 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 1240 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 1241 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar PLAYER_STARTER_NUM, 1
# 1242 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar PLAYER_STARTER_SPECIES, SPECIES_CRUISE
# 1243 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar RIVAL_STARTER_SPECIES, SPECIES_CHIKORITA
# 1244 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar RIVAL_STARTER_ID, LOCALID_BULBASAUR_BALL
# 1245 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3, PalletTown_ProfessorOaksLab_EventScript_LastPokeBall
# 1246 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2, PalletTown_ProfessorOaksLab_EventScript_ConfirmStarterChoice
# 1247 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_ThoseArePokeBalls
# 1248 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1249 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1250 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1251 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_CharmanderBall::
# 1252 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 1253 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 1254 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar PLAYER_STARTER_NUM, 2
# 1255 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar PLAYER_STARTER_SPECIES, SPECIES_FLAMEBEAR
# 1256 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar RIVAL_STARTER_SPECIES, SPECIES_CRUISE
# 1257 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	setvar RIVAL_STARTER_ID, LOCALID_SQUIRTLE_BALL
# 1258 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 3, PalletTown_ProfessorOaksLab_EventScript_LastPokeBall
# 1259 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 2, PalletTown_ProfessorOaksLab_EventScript_ConfirmStarterChoice
# 1260 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_ThoseArePokeBalls
# 1261 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1262 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1263 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1264 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_LastPokeBall::
# 1265 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OaksLastMon
# 1266 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1267 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1268 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1269 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Aide1::
# 1270 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 1271 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 1272 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, PalletTown_ProfessorOaksLab_EventScript_Aide1GameClear
# 1273 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_StudyAsOaksAide
# 1274 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1275 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1276 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1277 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Aide1GameClear::
# 1278 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	famechecker FAMECHECKER_OAK, 5
# 1279 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakIsGoingToHaveRadioShow
# 1280 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1281 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1282 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1283 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Aide2::
# 1284 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 1285 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 1286 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, PalletTown_ProfessorOaksLab_EventScript_Aide2GameClear
# 1287 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_StudyAsOaksAide
# 1288 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1289 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1290 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1291 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Aide2GameClear::
# 1292 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	famechecker FAMECHECKER_DAISY, 0
# 1293 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_DaisyWillGroomMons
# 1294 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1295 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1296 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1297 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Aide3::
# 1298 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lock
# 1299 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	faceplayer
# 1300 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	famechecker FAMECHECKER_OAK, 2
# 1301 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_OakIsAuthorityOnMons
# 1302 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	release
# 1303 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1304 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1305 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Pokedex::
# 1306 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_BlankEncyclopedia, MSGBOX_NPC
# 1307 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1308 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1309 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_Computer::
# 1310 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_EmailMessage, MSGBOX_SIGN
# 1311 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1312 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1313 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_LeftSign::
# 1314 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_PressStartToOpenMenu, MSGBOX_SIGN
# 1315 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	special StartWallClock
# 1316 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1317 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1318 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RightSign::
# 1319 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	lockall
# 1320 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, PalletTown_ProfessorOaksLab_EventScript_RightSignAlt
# 1321 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_SaveOptionInMenu
# 1322 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	releaseall
# 1323 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end
# 1324 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"

# 1325 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
PalletTown_ProfessorOaksLab_EventScript_RightSignAlt::
# 1326 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	msgbox PalletTown_ProfessorOaksLab_Text_AllMonTypesHaveStrongAndWeakPoints
# 1327 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	releaseall
# 1328 "data/maps/PalletTown_ProfessorOaksLab/scripts.pory"
	end

