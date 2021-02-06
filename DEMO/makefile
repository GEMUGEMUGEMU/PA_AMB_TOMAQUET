#
#        ~_
#     ~_ )_)~_
#     )_))_))_)
#     _!__!__!_
#   ~~\t  Gemu/~~
#
#  File Name: makefile
#  Purpose: Organize demo makefile
#  Creation Date: 24-01-21
#  Created By: Andrea Andreu Salvagnin
#

COMPILER_FLAGS=-Wall -c -g
#CC defines wich compiler will be used
CC = g++
LINKER_FLAGS = -lSDL2 -lSDL2_image `sdl2-config --cflags` -lSDL2_ttf
# Y or N
DEBUG=Y

ifeq ($(DEBUG),Y)
	COMPILER_FLAGS+= -DDEBUG_MODE
endif

# path to PA_AMB_TOMAQUET folder
PAT_FOLDER=..
# path to target file objects folder
FILE_OBJECTS_FOLDER=./FileObjects

include $(PAT_FOLDER)/makefile.pa_amb_tomaquet_dictionary

MAIN_CPP=Main/Main.cpp
MAIN=$(FILE_OBJECTS_FOLDER)/Main.o

DEMO_H=Game/Demo.h
DEMO_CPP=Game/Demo.cpp
DEMO=$(FILE_OBJECTS_FOLDER)/Demo.o

D_SCENE_M_CPP=./Scene/DemoSceneManager.cpp
D_SCENE_M_H=./Scene/DemoSceneManager.h
D_SCENE_M=$(FILE_OBJECTS_FOLDER)/DemoSceneManger.o

D_SCENE_CPP=./Scene/Demo/DemoScene.cpp
D_SCENE_H=./Scene/Demo/DemoScene.h
D_SCENE=$(FILE_OBJECTS_FOLDER)/DemoScene.o

D_TITLE_CPP=./Scene/Demo/DemoTitle.cpp
D_TITLE_H=./Scene/Demo/DemoTitle.h
D_TITLE=$(FILE_OBJECTS_FOLDER)/DemoTitle.o

D_SCENE_P_CPP=./Scene/Pause/PauseScene.cpp
D_SCENE_P_H=./Scene/Pause/PauseScene.h
D_SCENE_P=$(FILE_OBJECTS_FOLDER)/PauseScene.o

D_PAUSE_TEXT_CPP=./Scene/Pause/PauseText.cpp
D_PAUSE_TEXT_H=./Scene/Pause/PauseText.h
D_PAUSE_TEXT=$(FILE_OBJECTS_FOLDER)/PauseText.o

#D_PAUSE_C_CPP=./Scene/Pause/PauseController.cpp
#D_PAUSE_C_H=./Scene/Pause/PauseController.h
#D_PAUSE_C=$(FILE_OBJECTS_FOLDER)/PauseController.o

#D_SCENE_C_CPP=./Input/DemoSceneController.cpp
#D_SCENE_C_H=./Input/DemoSceneController.h
#D_SCENE_C=$(FILE_OBJECTS_FOLDER)/DemoSceneController.o

include ./GameObjects/Player/makefile.player_dictionary

PAT_OBJECTS=$(PAT_GAME_O) $(PAT_SCREEN_O) $(PAT_SCENE_M_O) $(PAT_SCENE_O) \
	$(PAT_VECTOR2D_O) $(PAT_A_OBJ_STATE_O) $(PAT_GRAPHIC_S_OBJ_O) \
	$(PAT_GRAPHIC_S_O) $(PAT_MATH_UTILS_O) $(PAT_ANIMATION_O) \
	$(PAT_STATE_OBJ_O)
DEMO_OBJECTS=$(MAIN) $(DEMO) $(D_SCENE_M) $(D_SCENE) $(D_PLAYER) \
	$(D_SCENE_P) $(D_PAUSE_TEXT) $(D_TITLE) $(D_PLAYER_S) \
	$(D_PLAYER_S_MOVE) $(D_PLAYER_S_IDLE) $(D_PLAYER_A_IDLE) \
	$(D_PLAYER_A_M) $(D_PLAYER_A_MOVE) \

TARGET=NISHIKIGOI_DEMO.out
#$@ is a macro that refers to the target
#$^ is a macro that name of all dependencies separated by space
$(TARGET): $(PAT_OBJECTS) $(DEMO_OBJECTS)
	$(CC) -g \
	$(PAT_OBJECTS) \
	$(DEMO_OBJECTS) \
	$(LINKER_FLAGS) -o $@

$(MAIN): $(MAIN_CPP)
	$(CC) $(COMPILER_FLAGS) \
	-I./Game -I$(PAT_GAME) -I$(PAT_SCENE) -I$(PAT_UTILS) -I$(PAT_INPUT) \
	-I$(PAT_GRAPHICS) \
	$(LINKER_FLAGS) $< -o $@

$(DEMO): $(DEMO_CPP) $(DEMO_H)
	$(CC) $(COMPILER_FLAGS) \
	-I$(PAT_GAME) -I$(PAT_SCENE) -I$(PAT_UTILS) -I$(PAT_INPUT) \
	-I$(PAT_GRAPHICS) -I./Scene \
	$(LINKER_FLAGS) $< -o $@

$(D_SCENE_M): $(D_SCENE_M_CPP) $(D_SCENE_M_H)
	$(CC) $(COMPILER_FLAGS) \
	-I$(PAT_INPUT) -I$(PAT_SCENE) -I$(PAT_UTILS) -I$(PAT_GAME_OBJ) \
	-I./Scene/Demo -I./Scene/Pause \
	$(LINKER_FLAGS) $< -o $@

$(D_SCENE): $(D_SCENE_CPP) $(D_SCENE_H)
	$(CC) $(COMPILER_FLAGS) \
	-I$(PAT_SCENE) -I$(PAT_UTILS) -I$(PAT_GAME_OBJ) \
	-I$(PAT_ANIM_KIN_OBJ) -I$(PAT_ANIM_OBJ) -I$(PAT_INPUT) \
	-I$(PAT_GRAPHICS) -I$(PAT_MATH) \
	-I./Input -I./GameObjects/Player/ \
	-I./GameObjects/Player/States/ -I./GameObjects/Player/Animations/ \
	-I./Scene/Pause/ \
	$(LINKER_FLAGS) $< -o $@

#$(D_SCENE_C): $(D_SCENE_C_CPP) $(D_SCENE_C_H)
#	$(CC) $(COMPILER_FLAGS) \
#	-I$(PAT_ANIM_KIN_OBJ) -I$(PAT_INPUT) -I$(PAT_GAME_OBJ) -I$(PAT_MATH) \
#	-I$(PAT_GRAPHICS) -I$(PAT_UTILS) -I$(PAT_SCENE) -I$(PAT_ANIM_OBJ) \
#	-I./GameObjects/Player/ -I./Scene/Pause/ \
#	-I./GameObjects/Player/States/ -I./GameObjects/Player/Animations/ \
#	$(LINKER_FLAGS) $< -o $@

$(D_SCENE_P): $(D_SCENE_P_CPP) $(D_SCENE_P_H)
	$(CC) $(COMPILER_FLAGS) \
	-I$(PAT_SCENE) -I$(PAT_UTILS) -I$(PAT_GAME_OBJ) -I$(PAT_INPUT) \
	-I./Input/ \
	$(LINKER_FLAGS) $< -o $@

$(D_PAUSE_TEXT): $(D_PAUSE_TEXT_CPP) $(D_PAUSE_TEXT_CPP)
	$(CC) $(COMPILER_FLAGS) \
	-I$(PAT_INPUT) -I$(PAT_GAME_OBJ) \
	$(LINKER_FLAGS) $< -o $@

#$(D_PAUSE_C): $(D_PAUSE_C_CPP) $(D_PAUSE_C_CPP)
#	$(CC) $(COMPILER_FLAGS) \
#	-I$(PAT_GAME_OBJ) -I$(PAT_INPUT) \
#	$(LINKER_FLAGS) $< -o $@

$(D_TITLE): $(D_TITLE_CPP) $(D_TITLE_H)
	$(CC) $(COMPILER_FLAGS) \
	-I$(PAT_GAME_OBJ) \
	$(LINKER_FLAGS) $< -o $@


include ./GameObjects/Player/makefile.player_rules

include $(PAT_FOLDER)/makefile.pa_amb_tomaquet_rules

.PHONY: clean
clean:
	-rm $(FILE_OBJECTS_FOLDER)/*.o
	-rm $(FILE_OBJECTS_FOLDER)/*.gch
	-rm $(TARGET)
