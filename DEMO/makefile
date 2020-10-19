#DEMO MAKE FILE
PA_AMB_TOMAQUET_FOLDER=..
PAT_OBJECT_DIRECTORY=$(PA_AMB_TOMAQUET_FOLDER)/FileObjects
PAT_OBJECTS=$(PAT_OBJECT_DIRECTORY)/Screen.o $(PAT_OBJECT_DIRECTORY)/AnimatedStaticObject.o $(PAT_OBJECT_DIRECTORY)/AnimationManager.o $(PAT_OBJECT_DIRECTORY)/Controller.o

OBJECTS=$(PAT_OBJECTS) $(DEMO_OBJECTS)

#PA AMB TOMÀTEQT FOLDERS
PTA_GRAPHICS=$(PA_AMB_TOMAQUET_FOLDER)/Graphics
PTA_INPUT=$(PA_AMB_TOMAQUET_FOLDER)/Input
PTA_MATH=$(PA_AMB_TOMAQUET_FOLDER)/Math
PTA_UTILS=$(PA_AMB_TOMAQUET_FOLDER)/Utils
PTA_GAME=$(PA_AMB_TOMAQUET_FOLDER)/Game
PTA_GAME_OBJECTS=$(PA_AMB_TOMAQUET_FOLDER)/GameObjects

#DEMO FOLDERS
MAIN=./Main
OBJECT_FILES=./FileObjects
GAME=./Game
GAME_OBJECTS=./GameObjects
TEST1=$(GAME_OBJECTS)/Test1

#DEMO OBJECTS
DEMO_OBJECTS=$(OBJECT_FILES)/Main.o $(OBJECT_FILES)/Game.o $(OBJECT_FILES)/Test1.o $(OBJECT_FILES)/Test1AnimationManager.o
 


#INCLUDE FOR OBJECTS
I_MAIN=-I$(PTA_GRAPHICS) -I$(PTA_INPUT) -I$(PTA_MATH) -I$(PTA_UTILS) -I$(PTA_GAME) -I$(PTA_GAME_OBJECTS)
I_GAME=-I$(PTA_GAME) -I$(PTA_GRAPHICS) -I$(PTA_INPUT) -I$(PTA_UTILS) -I$(PTA_GAME_OBJECTS) -I$(TEST1)
I_TEST1=-I$(TEST1) -I$(PTA_GAME_OBJECTS) -I$(PTA_GRAPHICS) -I$(PTA_UTILS) 

TARGET=PA_AMB_TOMAQUET_DEMO.out

CC=g++
COMPILER_FLAGS=-Wall -c -g
LINKER_FLAGS=-lSDL2 -lSDL2_image



#$@ is a macro that refers to the target
#$^ is a macro that name of all dependencies separated by space
$(TARGET): $(DEMO_OBJECTS) 
	cd $(PA_AMB_TOMAQUET_FOLDER) && $(MAKE)
	$(CC) -g $(OBJECTS) $(LINKER_FLAGS) -o $@ 


$(OBJECT_FILES)/Main.o: $(MAIN)/Main.cpp
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(I_MAIN) $< -o $@

$(OBJECT_FILES)/Game.o: $(GAME)/Demo.cpp
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(I_GAME) $< -o $@

$(OBJECT_FILES)/Test1.o: $(TEST1)/Test1.cpp $(TEST1)/Test1.h
	 $(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(I_TEST1) $< -o $@

$(OBJECT_FILES)/Test1AnimationManager.o: $(TEST1)/Test1AnimationManager.cpp $(TEST1)/Test1AnimationManager.h
	 $(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(I_TEST1) $< -o $@





.PHONY: clean c_all c_pa_amb_tomaquet pa_amb_tomaquet

clean:
	rm $(TARGET) $(OBJECT_FILES)/*.o


c_pa_amb_tomaquet:
	cd $(PA_AMB_TOMAQUET_FOLDER) && $(MAKE) clean
c_all:
	cd $(PA_AMB_TOMAQUET_FOLDER) && $(MAKE) clean
	rm $(TARGET)


#build pa amb tomaquet objects
pa_amb_tomaquet:
	cd $(PA_AMB_TOMAQUET_FOLDER) && $(MAKE)
