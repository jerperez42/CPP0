# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jerperez <jerperez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 10:28:10 by jerperez          #+#    #+#              #
#    Updated: 2024/02/07 15:23:19 by jerperez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98	

SRCS	=	Account.cpp\
			tests.cpp\

OBJ_DIR	=	obj

OBJ		= 	$(SRCS:.cpp=.o)
OBJS	= 	$(addprefix $(OBJ_DIR)/, $(OBJ))

###############################################

_COLOR_END=\033[0m
_COLOR_BOLD=\033[1m
_COLOR_RED=\033[31m
_COLOR_GREEN=\033[32m
_COLOR_YELLOW=\033[33m

###############################################

#PNG=philo.png
#PNGX=$$(tput cols)

#_PIC64=

###############################################

all: $(NAME)

$(OBJ_DIR)/%.o: %.cpp
	@echo Compiling: $<
	@mkdir -p $(@D)
	@$(CXX) $(CPPFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	@$(CXX) $(CPPFLAGS) -o $@ $^
ifdef _PIC64
ifdef PNG
ifneq ($(PNGX), )
	@echo "$(_PIC64)" | base64 -d > $(PNG)
	@chafa $(PNG) -s $(PNGX)
	@rm $(PNG)
endif
endif
endif
	@echo "$(_COLOR_GREEN)Ready to use $(_COLOR_BOLD)$(NAME) !$(_COLOR_END)"

clean:
	@rm -rf $(OBJ_DIR)/
	@echo "$(_COLOR_YELLOW)$(OBJ_DIR) directory removed.$(_COLOR_END)"

fclean: clean
	@rm -f $(NAME) $(NAME_B)
	@echo "$(_COLOR_YELLOW)Program(s) removed.$(_COLOR_END)"

re: fclean all

.PHONY: all re clean fclean