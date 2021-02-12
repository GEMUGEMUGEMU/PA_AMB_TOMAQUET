#
#        ~_
#     ~_ )_)~_
#     )_))_))_)
#     _!__!__!_
#   ~~\t  Gemu/~~
#    ~GEAR~GEAR~
#
#  File Name: makefile
#  Purpose: PA_AMB_TOMAQUET makefile
#  Creation Date: 08-02-21
#  Created By: Andrea Andreu Salvagnin
#

# Macro COMPILER
# Generate rules
# $(1) Compiler
# $(2) Object file to generate
# $(3) Source file
# $(4) Additional dependencies
# $(5) Compiler flags
define COMPILE
$(2): $(3) $(4)
	$(1) -c -o $(2) $(3) $(5)
endef

# Macro CPP2O
# From a .cpp get its .o
# $(1) Source file
define CPP2O
$(patsubst %.cpp,%.o,$(patsubst $(SRC)%,$(OBJ)%,$(1)))
endef

# Macro CPP2HPP
# From a .cpp get its .o
# $(1) Source file
define CPP2HPP
$(patsubst %.cpp,%.hpp,$(1))
endef


TARGET:=PA_AMB_TOMAQUET.a
CC:=g++
SDL2_FLAGS:=-lSDL2 -lSDL2_image `sdl2-config --cflags` -lSDL2_ttf
CCFLAGS:=-Wall -pedantic -std=c++14 $(SDL2_FLAGS)
MKDIR:=mkdir -p
RM:=rm
AR:=ar
AR_FLAGS:=-crs
RANLIB:=ranlib
SRC:=src
OBJ:=obj

ALL_CPPS:=$(shell find $(SRC)/ -type f -iname *.cpp)
ALL_CPP_OBJ:=$(foreach FILE,$(ALL_CPPS),$(call CPP2O,$(FILE)))
ALL_OBJ:=$(ALL_CPP_OBJ)
ALL_HS:=$(shell find $(SRC)/ -type f -iname *.h)
ALL_HPPS:=$(shell find $(SRC)/ -type f -iname *.hpp)
SRC_SUBDIRS:=$(shell find $(SRC)/ -type d)
OBJ_SUBDIRS:=$(patsubst $(SRC)%, $(OBJ)%,$(SRC_SUBDIRS))
INCLUDE_FOLDERS:=$(foreach this_folder,$(SRC_SUBDIRS),-I./$(this_folder))


DEBUG?=1
ifeq ($(DEBUG),1)
	CCFLAGS+= -DDEBUG_MODE -g
endif

RELASE?=0
ifeq ($(RELASE),1)
	CCLAGS+= -O3
endif


$(TARGET): $(OBJ_SUBDIRS) $(ALL_OBJ)
	$(AR) $(AR_FLAGS) $(TARGET) $(ALL_OBJ)
	$(RANLIB) $(TARGET)

# Generate and evaluate rules
$(foreach FILE,$(ALL_CPPS),$(eval $(call COMPILE,$(CC),$(call CPP2O,$(FILE)),$(FILE),$(call CPP2HPP,$(FILE)),$(CCFLAGS) $(INCLUDE_FOLDERS))))

# Generate obj folder tree
$(OBJ_SUBDIRS):
	$(MKDIR) $(OBJ_SUBDIRS)


.PHONY: clean info
clean:
	$(RM) -r "./$(OBJ)"
	$(RM) "./$(TARGET)"
info:
	$(info $(SRC_SUBDIRS))

