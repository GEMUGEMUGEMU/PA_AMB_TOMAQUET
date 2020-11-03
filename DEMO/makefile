#DEMO MAKE FILE
PA_AMB_TOMAQUET_FOLDER=..
PAT_OBJECT_DIRECTORY=$(PA_AMB_TOMAQUET_FOLDER)/FileObjects
PAT_OBJECTS_USED=Screen.o AnimatedStaticObject.o AnimatedKineticObject.o AnimationManager.o Controller.o Vector2D.o GraphicStaticObject.o Scene.o
PAT_OBJECTS=$(patsubst %.o,$(PAT_OBJECT_DIRECTORY)/%.o, $(PAT_OBJECTS_USED))

#PA AMB TOMÀTEQT FOLDERS PTA_GRAPHICS=$(PA_AMB_TOMAQUET_FOLDER)/Graphics
PTA_INPUT=$(PA_AMB_TOMAQUET_FOLDER)/Input
PTA_MATH=$(PA_AMB_TOMAQUET_FOLDER)/Math
PTA_UTILS=$(PA_AMB_TOMAQUET_FOLDER)/Utils
PTA_GAME=$(PA_AMB_TOMAQUET_FOLDER)/Game
PTA_GAME_OBJECTS=$(PA_AMB_TOMAQUET_FOLDER)/GameObjects
PTA_SCENE=$(PA_AMB_TOMAQUET_FOLDER)/Scene
PTA_GRAPHICS=$(PA_AMB_TOMAQUET_FOLDER)/Graphics

#DEMO FOLDERS
MAIN=./Main
OBJECT_FILES=./FileObjects
GAME=./Game
GAME_OBJECTS=./GameObjects
TEST1=$(GAME_OBJECTS)/Test1
TEST2=$(GAME_OBJECTS)/Test2
PLAYER=$(GAME_OBJECTS)/Player
INSTRUCTIONS=$(GAME_OBJECTS)/Instructions
INPUT=./Input
SCENE=./Scene

#DEMO OBJECTS
DEMO_OBJECTS_USED=Main.o Game.o Test1.o Test1AnimationManager.o Test2.o Test2AnimationManager.o DemoSceneController.o Player.o Instructions.o DemoScene.o
DEMO_OBJECTS=$(patsubst %.o,$(OBJECT_FILES)/%.o, $(DEMO_OBJECTS_USED))


OBJECTS=$(PAT_OBJECTS) $(DEMO_OBJECTS)


#INCLUDE FOR OBJECTS
I_MAIN=-I$(PTA_GRAPHICS) -I$(PTA_INPUT) -I$(PTA_MATH) -I$(PTA_UTILS) -I$(PTA_GAME) -I$(PTA_GAME_OBJECTS) -I$(PTA_SCENE) -I$(SCENE)
I_GAME=-I$(PTA_GAME) -I$(PTA_GRAPHICS) -I$(PTA_INPUT) -I$(INPUT) -I$(PTA_UTILS) -I$(PTA_GAME_OBJECTS) -I$(PTA_MATH) -I$(TEST1)  -I$(TEST2) -I$(PLAYER) -I$(INSTRUCTIONS) -I$(PTA_SCENE) -I$(SCENE)
I_TEST1=-I$(TEST1) -I$(PTA_GAME_OBJECTS) -I$(PTA_GRAPHICS) -I$(PTA_UTILS)
I_TEST2=-I$(TEST2) -I$(PTA_GAME_OBJECTS) -I$(PTA_GRAPHICS) -I$(PTA_UTILS) -I$(PTA_MATH)
I_PLAYER=-I$(PTA_GAME_OBJECTS) -I$(PTA_MATH) -I$(PTA_GRAPHICS) -I$(PTA_UTILS)
I_CONTROLLER=-I$(PTA_INPUT) -I$(INPUT) -I$(PTA_GAME_OBJECTS) -I$(PTA_MATH) -I$(PTA_GRAPHICS) -I$(PTA_UTILS) -I$(PLAYER)
I_INSTRUCTIONS=-I$(PTA_GAME_OBJECTS)
I_SCENE=-I$(PTA_SCENE) -I$(SCENE) -I$(PTA_INPUT) -I$(INPUT) -I$(PTA_GAME_OBJECTS) -I$(PLAYER) -I$(TEST1) -I$(TEST2) -I$(INSTRUCTIONS) -I$(PTA_MATH) -I$(PTA_GRAPHICS) -I$(PTA_UTILS)

TARGET=PA_AMB_TOMAQUET_DEMO.out

CC=g++
COMPILER_FLAGS=-Wall -c -g -O0
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

$(OBJECT_FILES)/Test2.o: $(TEST2)/Test2.cpp $(TEST2)/Test2.h
	 $(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(I_TEST2) $< -o $@

$(OBJECT_FILES)/Test2AnimationManager.o: $(TEST2)/Test2AnimationManager.h
	 $(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(I_TEST2) -x c++ $< -o $@

$(OBJECT_FILES)/DemoSceneController.o: $(INPUT)/DemoSceneController.cpp $(INPUT)/DemoSceneController.h
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(I_CONTROLLER) $< -o $@

$(OBJECT_FILES)/Player.o: $(PLAYER)/Player.cpp $(PLAYER)/Player.h
	 $(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(I_PLAYER) $< -o $@

$(OBJECT_FILES)/Instructions.o: $(INSTRUCTIONS)/Instructions.h
	 $(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(I_INSTRUCTIONS) -x c++ $< -o $@

$(OBJECT_FILES)/DemoScene.o: $(SCENE)/DemoScene.cpp $(SCENE)/DemoScene.h
	 $(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(I_SCENE) $< -o $@



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
