#Declare variables
OBJECT_DIRECTORY=FileObjects
OBJECTS=$(OBJECT_DIRECTORY)/Screen.o $(OBJECT_DIRECTORY)/Sprite.o $(OBJECT_DIRECTORY)/Vector2D.o $(OBJECT_DIRECTORY)/Controller.o $(OBJECT_DIRECTORY)/LinkedList.o $(OBJECT_DIRECTORY)/AnimationManager.o $(OBJECT_DIRECTORY)/GraphicObject.o $(OBJECT_DIRECTORY)/AnimatedStaticObject.o
COMPILER_FLAGS=-Wall -c -g
#CC defines wich compiler will be used
CC = g++
LINKER_FLAGS = -lSDL2 -lSDL2_image


#HEADERS FOLDERS:
GRAPHICS=./Graphics/
MATH=./Math/
ENTITY=./Entity/
INPUT=./Input/
UTILS=./Utils/
GAME_OBJECTS=./GameObjects/

#INCLUDERS FOR:
I_ENTITY=-I$(GRAPHICS)
I_PLAYER=-I$(GRAPHICS) -I$(MATH)
I_CONTROLLER=-I$(ENTITY) -I$(GRAPHICS) -I$(MATH)
I_GAME=-I$(GRAPHICS) -I$(INPUT) -I$(ENTITY) -I$(MATH) -I$(UTILS) -I$(GAME_OBJECTS)
I_MAIN=-I$(GRAPHICS) -I$(INPUT) -I$(ENTITY) -I$(MATH) -I$(UTILS) -I$(GAME_OBJECTS)
I_SCREEN=-I$(UTILS) -I$(ENTITY) -I$(GRAPHICS)
I_ANIMATED_STATIC_OBJECT=-I$(GRAPHICS) -I$(GAME_OBJECTS) -I$(UTILS)
I_ANIMATION_MANAGER=-I$(UTILS)



.PHONY: objects

objects: $(OBJECTS)
	@echo PA AMB TOMÀQUET objects builded


$(OBJECT_DIRECTORY)/Screen.o: $(GRAPHICS)Screen.cpp $(GRAPHICS)Screen.h
	$(CC) $(COMPILER_FLAGS) $(I_SCREEN) $(LINKER_FLAGS) $< -o $@

$(OBJECT_DIRECTORY)/Sprite.o: $(GRAPHICS)Sprite.cpp $(GRAPHICS)Sprite.h
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $< -o $@

$(OBJECT_DIRECTORY)/Controller.o: Input/Controller.cpp Input/Controller.h
	$(CC) $(COMPILER_FLAGS) $(I_CONTROLLER) $(LINKER_FLAGS) $< -o $@

$(OBJECT_DIRECTORY)/LinkedList.o: Utils/LinkedList.h
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -x c++ $< -o $@
	
$(OBJECT_DIRECTORY)/Vector2D.o: Math/Vector2D.cpp Math/Vector2D.h
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $< -o $@
	
$(OBJECT_DIRECTORY)/GraphicObject.o: $(GAME_OBJECTS)GraphicObject.h
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) -x c++ $< -o $@

$(OBJECT_DIRECTORY)/AnimatedStaticObject.o: $(GAME_OBJECTS)AnimatedStaticObject.cpp $(GAME_OBJECTS)AnimatedStaticObject.h
	$(CC) $(COMPILER_FLAGS) $(I_ANIMATED_STATIC_OBJECT) $(LINKER_FLAGS) $< -o $@ 

$(OBJECT_DIRECTORY)/AnimationManager.o: $(GRAPHICS)AnimationManager.cpp $(GRAPHICS)AnimationManager.h
	$(CC) $(COMPILER_FLAGS) $(I_ANIMATION_MANAGER) $(LINKER_FLAGS) $< -o $@
	
.PHONY: clean
clean:
	rm $(OBJECT_DIRECTORY)/*.o $(OBJECT_DIRECTORY)/*.gch 

