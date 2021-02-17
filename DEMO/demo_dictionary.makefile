#
#        ~_
#     ~_ )_)~_
#     )_))_))_)
#     _!__!__!_
#   ~~\t  Gemu/~~
#    ~GEAR~GEAR~
#
#  File Name: demo_dictionary.makefile
#  Purpose:
#  Creation Date: 16-02-21
#  Created By: Andrea Andreu Salvagnin
#

DEMO_FOLDERS:=$(shell find $(DEMO_PATH)/src/ -type d)
INCLUDE_DEMO_FOLDERS:=$(foreach this_folder,$(DEMO_FOLDERS),-I./$(this_folder))


