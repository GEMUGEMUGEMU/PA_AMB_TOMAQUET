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

T_PAT_UTILS=./Utils/T_PAT_Utils.cpp

TESTS_CPP=./Tests.cpp
TESTS=$(FILE_OBJECTS_FOLDER)/Tests.o

T_OBJECTS= $(TESTS)
PAT_OBJECTS= $(PAT_UTILS_O)

TARGET=Tests.out

$(TARGET): $(T_OBJECTS)
	$(CC) -g \
	$(T_OBJECTS) \
	$(PAT_OBJECTS) \
	-o $@

$(TESTS): $(T_PAT_UTILS) $(TESTS_CPP)
	$(CC) \
	-I./Catch1/ -I./TEST2/ -I./Utils/ -I$(PAT_UTILS) \
	$(COMPILER_FLAGS) $(TESTS_CPP)  -o $@


.PHONY: $(T_PAT_UTILS)

$(T_PAT_UTILS): $(PAT_UTILS_H) $(PAT_UTILS_CPP)

include $(PAT_FOLDER)/makefile.pa_amb_tomaquet_rules

.PHONY: clean
clean:
	-rm $(FILE_OBJECTS_FOLDER)/*.o
	-rm $(FILE_OBJECTS_FOLDER)/*.gch
	-rm $(TARGET)
