#
#        ~_
#     ~_ )_)~_
#     )_))_))_)
#     _!__!__!_
#   ~~\t  Gemu/~~
#
#  File Name: makefile
#  Purpose:
#  Creation Date: 24-01-21
#  Created By: Andrea Andreu Salvagnin
#

COMPILER_FLAGS=-Wall -c -g
#CC defines wich compiler will be used
CC = g++
LINKER_FLAGS = -lSDL2 -lSDL2_image `sdl2-config --cflags` -lSDL2_ttf

# path to PA_AMB_TOMAQUET folder
PAT_FOLDER=..
# path to target file objects folder
FILE_OBJECTS_FOLDER=./FileObjects

include $(PAT_FOLDER)/makefile.dictionary

MAIN_CPP=Main/Main.cpp
MAIN=$(FILE_OBJECTS_FOLDER)/Main.o

DEMO_H=Game/Demo.h
DEMO_CPP=Game/Demo.cpp
DEMO=$(FILE_OBJECTS_FOLDER)/Demo.o


D_SCENE_M_CPP=./Scene/DemoSceneManager.cpp
D_SCENE_M_H=./Scene/DemoSceneManager.h
D_SCENE_M=$(FILE_OBJECTS_FOLDER)/DemoSceneManger.o

D_SCENE_CPP=./Scene/DemoScene.cpp
D_SCENE_H=./Scene/DemoScene.h
D_SCENE=$(FILE_OBJECTS_FOLDER)/DemoScene.o




PAT_OBJECTS=$(PAT_GAME_O) $(PAT_SCREEN_O) $(PAT_SCENE_M_O) $(PAT_SCENE_O)
DEMO_OBJECTS=$(MAIN) $(DEMO) $(D_SCENE_M) $(D_SCENE)
#OBJECTS= $(PAT_OBJECTS) $(DEMO_OBJECTS)

TARGET=PA_AMB_TOMAQUET_DEMO.out
#$@ is a macro that refers to the target
#$^ is a macro that name of all dependencies separated by space
$(TARGET): $(DEMO_OBJECTS) $(PAT_OBJECTS)
	$(CC) -g \
	$(DEMO_OBJECTS) \
	$(PAT_OBJECTS) \
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
	$(LINKER_FLAGS) $< -o $@

$(D_SCENE): $(D_SCENE_CPP) $(D_SCENE_H)
	$(CC) $(COMPILER_FLAGS) \
	-I$(PAT_SCENE) -I$(PAT_UTILS) -I$(PAT_GAME_OBJ) -I./Input \
	-I$(PAT_INPUT) -I./GameObjects/Player/ -I$(PAT_MATH) \
	-I$(PAT_GRAPHICS) \
	$(LINKER_FLAGS) $< -o $@

include $(PAT_FOLDER)/makefile.pa_amb_tomaquet_rules

.PHONY: clean
clean:
	-rm $(FILE_OBJECTS_FOLDER)/*.o
	-rm $(OBJECT_DIRECTORY)/*.gch

