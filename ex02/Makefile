# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 21:02:13 by kfujita           #+#    #+#              #
#    Updated: 2023/06/23 22:05:07 by kfujita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	main

SRCS	:= \
	$(NAME).cpp\
	Fixed.cpp\

OBJS	:= $(SRCS:.cpp=.o)
DEPS	:= $(OBJS:.o=.d)

override CXXFLAGS	+=	-Wall -Wextra -Werror -MMD -MP -std=c++98

CXX		:=	c++

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

debug: clean_local_obj
	make CXXFLAGS='-DDEBUG -g'
faddr: clean_local_obj
	make CXXFLAGS='-g -fsanitize=address'
fleak: clean_local_obj
	make CXXFLAGS='-g -fsanitize=leak'

clean_local_obj:
	rm -f $(OBJS)

clean: clean_local_obj
	rm -f $(DEPS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

-include $(DEPS)

.PHONY:	clean_local_obj
