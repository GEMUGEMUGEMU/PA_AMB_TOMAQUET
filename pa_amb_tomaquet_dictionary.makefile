#
#        ~_
#     ~_ )_)~_
#     )_))_))_)
#     _!__!__!_
#   ~~\t  Gemu/~~
#    ~GEAR~GEAR~
#
#  File Name: pa_amb_tomaquet_dictionary.makefile
#  Purpose:
#  Creation Date: 09-02-21
#  Created By: Andrea Andreu Salvagnin
#
# PAT_PATH path to PA_AMB_TOMAQUET that have to be defined
# befor including this makefile

PAT_LIB:=$(PAT_PATH)/PA_AMB_TOMAQUET.a
PAT_FOLDERS:=$(shell find $(PAT_PATH)/src/ -type d)
INCLUDE_PAT_FOLDERS:=$(foreach this_folder,$(PAT_FOLDERS),-I./$(this_folder))


