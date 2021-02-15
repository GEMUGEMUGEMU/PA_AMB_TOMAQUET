#
#        ~_
#     ~_ )_)~_
#     )_))_))_)
#     _!__!__!_
#   ~~\t  Gemu/~~
#    ~GEAR~GEAR~
#
#  File Name: makefile
#  Purpose: DEMO makefile
#  Creation Date: 08-02-21
#  Created By: Andrea Andreu Salvagnin
#

# Macro COMPILE
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
# $(2) All HPP
define CPP2HPP
#$(patsubst %.cpp,%.hpp,$(1))

$(findstring $(patsubst %.cpp,%.hpp,$(1)),$(2))
endef

define print_logo
@echo "        ~_"
@echo "     ~_ )_)~_"
@echo "     )_))_))_) Make $(TARGET)"
@echo "     _!__!__!_"
@echo "   ~~\   Gemu/~~"
endef


TARGET:=NISHIKIGOI_DEMO.out
CC:=g++
CCFLAGS:=-Wall -pedantic -std=c++14 $(SDL2_FLAGS)
LIBS:=
MKDIR:=mkdir -p
RM:=rm
SRC:=src
OBJ:=obj

SDL2_FLAGS:=-lSDL2 -lSDL2_image `sdl2-config --cflags` -lSDL2_ttf
CCFLAGS+= $(SDL2_FLAGS)

ALL_CPPS:=$(shell find $(SRC)/ -type f -iname *.cpp)
ALL_CPP_OBJ:=$(foreach FILE,$(ALL_CPPS),$(call CPP2O,$(FILE)))
ALL_OBJ:=$(ALL_CPP_OBJ)
ALL_HS:=$(shell find $(SRC)/ -type f -iname *.h)
ALL_HPPS:=$(shell find $(SRC)/ -type f -iname *.hpp)
SRC_SUBDIRS:=$(shell find $(SRC)/ -type d)
OBJ_SUBDIRS:=$(patsubst $(SRC)%, $(OBJ)%,$(SRC_SUBDIRS))
INCLUDE_SOURCE_FOLDERS:=$(foreach this_folder,$(SRC_SUBDIRS),-I./$(this_folder))


# PA_AMB_TOMAQUET
PAT_PATH:=..
include $(PAT_PATH)/pa_amb_tomaquet_dictionary.makefile

INCLUDE_FOLDERS:=$(INCLUDE_SOURCE_FOLDERS) $(INCLUDE_PAT_FOLDERS)


DEBUG?=1
ifeq ($(DEBUG),1)
	CCFLAGS+= -DDEBUG_MODE -g
endif

RELASE?=0
ifeq ($(RELASE),1)
	CCFLAGS+= -O3
endif


$(TARGET): $(PAT_LIB) $(OBJ_SUBDIRS) $(ALL_OBJ)
	$(call print_logo)
	$(CC) -o $(TARGET) $(ALL_OBJ) $(PAT_LIB) $(SDL2_FLAGS)


$(foreach FILE,$(ALL_CPPS),$(eval $(call COMPILE,$(CC),$(call CPP2O,$(FILE),$(ALLHPPS)),$(FILE),$(call CPP2HPP,$(FILE)),$(CCFLAGS) $(INCLUDE_FOLDERS))))

$(OBJ_SUBDIRS):
	$(MKDIR) $(OBJ_SUBDIRS)

$(PAT_LIB): make_pat_lib
	$(MAKE) -C $(PAT_PATH)

.PHONY: clean info

clean:
	- $(RM) -r "./$(OBJ)"
	- $(RM) "./$(TARGET)"
info:
#	$(info $(ALL_HPPS))
	$(info $(MAKE_PAT))
	$(info $(PAT_LIB))

