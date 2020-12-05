#Declare variables
OBJECT_DIRECTORY=FileObjects
PAT_OBJECTS=Screen.o Sprite.o Vector2D.o Controller.o LinkedList.o Stack.o \
	AnimationManager.o GraphicObject.o AnimatedStaticObject.o \
	AnimatedKineticObject.o GraphicStaticObject.o Scene.o SceneManager.o

OBJECTS=$(patsubst %.o,$(OBJECT_DIRECTORY)/%.o, $(PAT_OBJECTS))

COMPILER_FLAGS=-Wall -c -g
#CC defines wich compiler will be used
CC = g++
LINKER_FLAGS = -lSDL2 -lSDL2_image


#HEADERS FOLDERS:
GRAPHICS=./Graphics
MATH=./Math
INPUT=./Input
UTILS=./Utils
GAME_OBJECTS=./GameObjects
SCENE=./Scene

#INCLUDERS FOR:
I_PLAYER=-I$(GRAPHICS) -I$(MATH)
I_CONTROLLER=-I$(GRAPHICS) -I$(MATH) -I$(GAME_OBJECTS) -I$(UTILS)
I_GAME=-I$(GRAPHICS) -I$(INPUT) -I$(ENTITY) -I$(MATH) -I$(UTILS) \
	-I$(GAME_OBJECTS) -I$(SCENE)
I_MAIN=-I$(GRAPHICS) -I$(INPUT) -I$(ENTITY) -I$(MATH) -I$(UTILS) \
	-I$(GAME_OBJECTS) -I$(SCENE)
I_SCREEN=-I$(UTILS) -I$(GRAPHICS)
I_ANIMATED_STATIC_OBJECT=-I$(GRAPHICS) -I$(GAME_OBJECTS) -I$(UTILS)
I_ANIMATED_KINETIC_OBJECT=-I$(GRAPHICS) -I$(GAME_OBJECTS) -I$(UTILS) -I$(MATH)
I_ANIMATION_MANAGER=-I$(UTILS)
I_GRAPICH_STATIC_OBJECT=-I$(GAME_OBJECTS)
I_SCENE=-I$(INPUT) -I$(GAME_OBJECTS) -I$(MATH) -I$(GRAPHICS) -I$(UTILS)
I_SCENE_MANAGER=-I$(INPUT) -I$(UTILS)


.PHONY: objects

objects: $(OBJECTS)
	@echo PA AMB TOMÀQUET objects builded


$(OBJECT_DIRECTORY)/Screen.o: $(GRAPHICS)/Screen.cpp $(GRAPHICS)/Screen.h
	$(CC) $(COMPILER_FLAGS) $(I_SCREEN) $(LINKER_FLAGS) $< -o $@

$(OBJECT_DIRECTORY)/Sprite.o: $(GRAPHICS)/Sprite.cpp $(GRAPHICS)/Sprite.h
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $< -o $@

$(OBJECT_DIRECTORY)/Controller.o: $(INPUT)/Controller.h
	$(CC) $(COMPILER_FLAGS) $(I_CONTROLLER) $(LINKER_FLAGS) -x c++ $< -o $@

$(OBJECT_DIRECTORY)/LinkedList.o: $(UTILS)/LinkedList.h
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -x c++ $< -o $@

$(OBJECT_DIRECTORY)/Stack.o: $(UTILS)/Stack.h
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -x c++ $< -o $@

$(OBJECT_DIRECTORY)/Vector2D.o: $(MATH)/Vector2D.cpp Math/Vector2D.h
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $< -o $@

$(OBJECT_DIRECTORY)/GraphicObject.o: $(GAME_OBJECTS)/GraphicObject.h
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -x c++ $< -o $@

$(OBJECT_DIRECTORY)/AnimatedStaticObject.o: \
	$(GAME_OBJECTS)/AnimatedStaticObject.cpp \
	$(GAME_OBJECTS)/AnimatedStaticObject.h
	$(CC) $(COMPILER_FLAGS) $(I_ANIMATED_STATIC_OBJECT) $(LINKER_FLAGS) $< -o $@

$(OBJECT_DIRECTORY)/AnimatedKineticObject.o: \
	$(GAME_OBJECTS)/AnimatedKineticObject.cpp \
	$(GAME_OBJECTS)/AnimatedKineticObject.h
	$(CC) $(COMPILER_FLAGS) $(I_ANIMATED_KINETIC_OBJECT) $(LINKER_FLAGS) $< -o $@

$(OBJECT_DIRECTORY)/AnimationManager.o: \
	$(GRAPHICS)/AnimationManager.cpp $(GRAPHICS)/AnimationManager.h
	$(CC) $(COMPILER_FLAGS) $(I_ANIMATION_MANAGER) $(LINKER_FLAGS) $< -o $@

$(OBJECT_DIRECTORY)/GraphicStaticObject.o: \
	$(GAME_OBJECTS)/GraphicStaticObject.cpp \
	$(GAME_OBJECTS)/GraphicStaticObject.h
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(I_GRAPICH_STATIC_OBJECT) $< -o $@

$(OBJECT_DIRECTORY)/Scene.o: $(SCENE)/Scene.h
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(I_SCENE) -x c++ $< -o $@

$(OBJECT_DIRECTORY)/SceneManager.o: $(SCENE)/SceneManager.h
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(I_SCENE_MANAGER) -x c++ $< -o $@



.PHONY: clean
clean:
	rm $(OBJECT_DIRECTORY)/*.o $(OBJECT_DIRECTORY)/*.gch

