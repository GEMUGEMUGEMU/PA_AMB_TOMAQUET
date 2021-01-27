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

OBJECTS= $(TESTS)

TARGET=Tests.out

$(TARGET): $(OBJECTS)
	$(CC) -g $(OBJECTS) -o $@

$(TESTS): $(TESTS_CPP)
	$(CC) -I./Catch1/ -I./TEST2/ $(COMPILER_FLAGS) $< -o $@


include $(PAT_FOLDER)/makefile.pa_amb_tomaquet_rules

.PHONY: clean
clean:
	-rm $(FILE_OBJECTS_FOLDER)/*.o
	-rm $(FILE_OBJECTS_FOLDER)/*.gch
	-rm $(TARGET)
