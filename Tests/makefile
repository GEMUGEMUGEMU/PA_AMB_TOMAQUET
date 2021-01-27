#
#        ~_
#     ~_ )_)~_
#     )_))_))_)
#     _!__!__!_
#   ~~\t  Gemu/~~
#    ~GEAR~GEAR~
#
#  File Name: makefile
#  Purpose:
#  Creation Date: 27-01-21
#  Created By: Andrea Andreu Salvagnin
#

#COMPILER_FLAGS=-Wall -c -g
COMPILER_FLAGS=-c
#CC defines wich compiler will be used
CC = g++

# path to PA_AMB_TOMAQUET folder
PAT_FOLDER=..
# path to target file objects folder
FILE_OBJECTS_FOLDER=./FileObjects

include $(PAT_FOLDER)/makefile.dictionary

TESTS_CPP=./Tests.cpp
TESTS=$(FILE_OBJECTS_FOLDER)/Tests.o

T_MATH_UTILS=./Math/T_PAT_MathUtils.cpp
T_VECTOR_2D=./Math/T_PAT_Vector2D.cpp


T_OBJECTS= $(TESTS)
PAT_OBJECTS= $(PAT_MATH_UTILS_O) $(PAT_VECTOR2D_O)


TARGET=Tests.out

$(TARGET): $(T_OBJECTS) $(PAT_OBJECTS)
	$(CC) -g \
	$(T_OBJECTS) \
	$(PAT_OBJECTS) \
	-o $@

$(TESTS): $(TESTS_CPP) $(T_MATH_UTILS) $(T_VECTOR_2D)
	$(CC) \
	-I./Catch1/ -I./Math/ -I$(PAT_MATH) \
	$(COMPILER_FLAGS) $(TESTS_CPP) -o $@


include $(PAT_FOLDER)/makefile.pa_amb_tomaquet_rules

.PHONY: clean
clean:
	-rm $(FILE_OBJECTS_FOLDER)/*.o
	-rm $(FILE_OBJECTS_FOLDER)/*.gch
	-rm $(TARGET)
