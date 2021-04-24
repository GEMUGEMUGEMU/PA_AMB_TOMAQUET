#
#        ~_
#     ~_ )_)~_
#     )_))_))_)
#     _!__!__!_
#   ~~\t  Gemu/~~
#    ~GEAR~GEAR~
#
#  File Name: print_logo.makefile
#  Purpose: include print logo
#  Creation Date: 18-02-21
#  Created By: Andrea Andreu Salvagnin
#

define print_logo
@echo "        \e[0;31m~\e[0m\e[1;33m_\e[0m"
@echo "     \e[1;34m~\e[1;33m_ )_)\e[1;34m~\e[1;33m_\e[0m"
@echo "     \e[1;33m)_))_))_) \e[1;36mMake $(TARGET)\e[0m"
@echo "     \e[1;34m_!__!__!_\e[1m"
@echo "   \e[1;36m~~\e[1;34m\   \e[1;33mGemu\e[1;34m/\e[1;36m~~\e[0m"
@echo "    \e[1;36m~\e[1;35mGEAR\e[1;36m~\e[1;35mGEAR\e[1;36m~\e[0m"
endef


