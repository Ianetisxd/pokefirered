PalletTown_Oak_Office_MapScripts::
map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_Oak_Office_OnFrame

PalletTown_Oak_Office_OnFrame:
map_script_2 VAR_STARTER_SCENE, 0, ScriptSilentTown_Starter
.2byte 0

ScriptSilentTown_Starter::
lockall
applymovement OBJ_EVENT_ID_PLAYER, moveplayer
waitmovement OBJ_EVENT_ID_PLAYER
applymovement 6, mov_oak
msgbox text0, MSGBOX_DEFAULT
applymovement 7, mov_riv0
msgbox text1, MSGBOX_DEFAULT
closemessage
applymovement 4, mov_blue0
waitmovement 4
playfanfare MUS_OBTAIN_BADGE
msgbox obtain, MSGBOX_SIGN
waitfanfare
closemessage
applymovement 4, mov_blue1
waitmovement 4
msgbox choosestarter, MSGBOX_DEFAULT
applymovement 7, mov_riv1
msgbox first, MSGBOX_DEFAULT
setflag FLAG_SYS_POKEDEX_GET
setflag FLAG_SYS_NATIONAL_DEX
setvar VAR_STARTER_SCENE, 1
releaseall
end

moveplayer:
walk_up
walk_up
step_end

mov_oak:
emote_exclamation_mark
step_end

text0:
.string "{COLOR GREEN}OAK: {PLAYER}!\nThere you are!\p"
.string "{COLOR RED}{RIVAL}: I can't believe this old\n"
.string "geezer is PROF OAK...\p"
.string "{COLOR GREEN}OAK: Haha!\p"
.string "Indeed young man, but I'm not that\n"
.string "old yet!\p"
.string "I have called you both here for an\n"
.string "important task...\p"
.string "Since I was a young boy, I have\n"
.string "dreamed of having a complete guide\l"
.string "on every species of POKéMON.\p"
.string "However...\p"
.string "More and more are being discovered\n"
.string "every day!\p"
.string "But my age is catching on me...\p"
.string "So!\p"
.string "I would like you two to carry out\n"
.string "my research.$"

mov_riv0:
emote_exclamation_mark
jump_in_place_up
step_end

text1:
.string "{COLOR RED}{RIVAL}: Wow!\p"
.string "You want us to find and catch a\n"
.string "bunch of POKéMON for you!?\p"
.string "As many as we want?\p"
.string "{COLOR BLUE}BLUE: That's right!\n"
.string "It won't be easy however.\p"
.string "I tried to complete the POKéDEX\n"
.string "once...\p"
.string "But I got too arrogant...\n"
.string "I focused too much being the best\l"
.string "trainer, I lost sight of my goal.\p"
.string "So I help Gramps with his research\n"
.string "now.\p"
.string "Here! Take this POKéDEX!\p"
.string "It automatically records data on\n"
.string "POKéMON you've seen or caught!$"

mov_blue0:
walk_down
walk_down
walk_right
walk_right
walk_right
walk_right
face_down
delay_16
face_down
walk_left
face_down
step_end

obtain:
.string "{PLAYER} received the POKéDEX!$"

mov_blue1:
walk_left
walk_left
walk_left
walk_up
walk_up
face_down
step_end

choosestarter:
.string "{COLOR GREEN}OAK: Now all you need is a partner\n"
.string "POKéMON for your journey.\p"
.string "There are three POKéBALLS on the\n"
.string "table\p"
.string "Both of you can choose one to be\n"
.string "your companion!$"

mov_riv1:
face_left
step_end

first:
.string "{COLOR RED}{RIVAL}: You can choose first\n"
.string "{PLAYER}...\p"
.string "I want some time to decide.$"

locked::
lockall 
msgbox doorlocked, MSGBOX_DEFAULT
closemessage
applymovement OBJ_EVENT_ID_PLAYER, Movement_Example
waitmovement OBJ_EVENT_ID_PLAYER
releaseall
end 

doorlocked:
.string "The door seems to be locked...$"

Movement_Example:
walk_down
step_end

DaisyApproachLeft::
lockall
applymovement 1, moveleft
waitmovement 1
goto Daisy

DaisyApproachMid::
lockall
applymovement 1, movemid
waitmovement 1
goto Daisy

DaisyApproachRight::
lockall
applymovement 1, moveright
waitmovement 1
goto Daisy

Daisy::
lockall
msgbox journey, MSGBOX_DEFAULT
additem ITEM_TOWN_MAP 1
playfanfare MUS_OBTAIN_ITEM
msgbox tmap, MSGBOX_SIGN
waitmessage
msgbox postmap, MSGBOX_DEFAULT
playfanfare MUS_OBTAIN_ITEM
msgbox pokeball, MSGBOX_SIGN
waitmessage
additem ITEM_POTION 1
additem ITEM_POKE_BALL 5
msgbox postitems, MSGBOX_DEFAULT
closemessage
setvar VAR_DAISY, 2
applymovement 1, moveend
waitmovement 1
release
end

journey:
.string "{COLOR RED}Oh, are you leaving on a journey?\p"
.string "BLUE is my little brother.\p"
.string "If Grampa gave you a task,\n"
.string "I would like to help you.\p"
.string "He was also suppoused to give\n"
.string "you this!$"

postmap:
.string "{COLOR RED}The TOWN MAP lets you view\n"
.string "a map right in your POKéGEAR!\p"
.string "Now...\n"
.string "How can I help?\p"
.string "...\p"
.string "Oh, I know!$"

postitems:
.string "{COLOR RED}A POTION can heal yor POKéMON if\n"
.string "they are hurt, and POKéBALLS allow\l"
.string "you to catch wild POKéMON\p"
.string "If you run out of POKéBALLS you can\n"
.string "buy more at any town MART.\p"
.string "Good luck, {PLAYER}!\n"
.string "I'll be rooting for you!$"

tmap:
.string "{PLAYER} obtained the TOWN MAP.$"

pokeball:
.string "{PLAYER} has got 5 POKéBALLS and one\n"
.string "POTION!$"

moveleft:
walk_right
walk_right
face_up
step_end

movemid:
walk_right
walk_right
walk_right
face_up
step_end

moveright:
walk_right
walk_right
walk_right
walk_right
face_up
step_end

moveend:
walk_left
walk_left
walk_left
face_up
step_end
