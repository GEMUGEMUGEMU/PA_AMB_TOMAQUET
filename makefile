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

# Macro CPP2D
# From a .cpp get its .d
# $(1) Source file
define CPP2D
$(patsubst %.cpp,%.d,$(patsubst $(SRC)%,$(DEP)%,$(1)))
endef

# Macro CPP2HPP
# From a .cpp get its .o
# $(1) Source file
define CPP2HPP
$(patsubst %.cpp,%.hpp,$(1))
endef

include print_logo.makefile

TARGET:=PA_AMB_TOMAQUET.a
CCX:=g++
CCXFLAGS:=-Wall -pedantic -std=c++17
#CCXFLAGS:=-Wall -pedantic -std=c++17 -fsanitize=address
MKDIR:=mkdir -p
RM:=rm
AR:=ar
AR_FLAGS:=-crs
RANLIB:=ranlib
SRC:=src
OBJ:=obj

ALL_CPPS:=$(shell find $(SRC)/ -type f -iname *.cpp)
ALL_CPP_OBJ:=$(foreach file,$(ALL_CPPS),$(call CPP2O,$(file)))
ALL_OBJ:=$(ALL_CPP_OBJ)
ALL_HS:=$(shell find $(SRC)/ -type f -iname *.h)
ALL_HPPS:=$(shell find $(SRC)/ -type f -iname *.hpp)
SRC_SUBDIRS:=$(shell find $(SRC)/ -type d)
OBJ_SUBDIRS:=$(patsubst $(SRC)%,$(OBJ)%,$(SRC_SUBDIRS))
INCLUDE_FOLDERS:=$(foreach this_folder,$(SRC_SUBDIRS),-I./$(this_folder))


DEPEND_FILES:=$(patsubst %.o,%.d,$(ALL_OBJ))
DEPFLAGS =-MMD -MP

TEST_PATH:=./tests
TESTS_PAT:=$(TEST_PATH)/TESTS_PAT.out

RELASE?=0
ifeq ($(RELASE),1)
	CCXFLAGS+= -O3
else
	DEBUG:=1
endif

DEBUG?=1
ifeq ($(DEBUG),1)
	CCXFLAGS+= -DDEBUG_MODE -g
endif

.PHONY: run_test
run_test: $(TARGET)
	$(MAKE) -C $(TEST_PATH)
	$(TESTS_PAT)

$(TARGET): $(OBJ_SUBDIRS) $(ALL_OBJ)
	$(call print_logo)
	$(AR) $(AR_FLAGS) $(TARGET) $(ALL_OBJ)
	$(RANLIB) $(TARGET)

# Generate and evaluate rules
$(foreach FILE,$(ALL_CPPS),$(eval $(call COMPILE,$(CCX),$(call CPP2O,$(FILE)),$(FILE),,$(CCXFLAGS) $(INCLUDE_FOLDERS) $(DEPFLAGS))))

# Generate obj folder tree
$(OBJ_SUBDIRS):
	$(MKDIR) $(OBJ_SUBDIRS)

-include $(DEPEND_FILES)

.PHONY: clean info

clean:
	$(RM) -r "./$(OBJ)"
	$(RM) "./$(TARGET)"
info:
	$(info $(DEPEND_FILES))
	$(info $(SRC_SUBDIRS))
	$(info $(TESTS_PAT))

