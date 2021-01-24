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

OBJECTS= $(MAIN) $(DEMO) $(PAT_GAME_O)

TARGET=PA_AMB_TOMAQUET_DEMO.out
#$@ is a macro that refers to the target
#$^ is a macro that name of all dependencies separated by space
$(TARGET): $(OBJECTS)
	$(CC) -g $(OBJECTS) $(LINKER_FLAGS) -o $@


$(MAIN): $(MAIN_CPP)
	$(CC) $(COMPILER_FLAGS) -I./Game -I$(PAT_GAME) -I$(PAT_SCENE) \
	-I$(PAT_UTILS) -I$(PAT_INPUT) -I$(PAT_GRAPHICS) \
	$(LINKER_FLAGS) $< -o $@


$(DEMO): $(DEMO_CPP) $(DEMO_H)
	$(CC) $(COMPILER_FLAGS) \
	-I$(PAT_GAME) -I$(PAT_SCENE) -I$(PAT_UTILS) -I$(PAT_INPUT) \
	-I$(PAT_GRAPHICS) -I./Scene \
	$(LINKER_FLAGS) $< -o $@


include $(PAT_FOLDER)/makefile.pa_amb_tomaquet_rules

.PHONY: clean
clean:
	-rm $(FILE_OBJECTS_FOLDER)/*.o
	-rm $(OBJECT_DIRECTORY)/*.gch

