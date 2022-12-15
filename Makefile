# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 16:22:00 by dvallien          #+#    #+#              #
#    Updated: 2022/12/14 16:44:02 by dvallien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = container
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address

PATH_SRCS		=	srcs
PATH_DEP		=	dep
PATH_OBJS		=	obj
PATH_INCLUDES	=	incs

LST_SRCS		=	srcs/main.cpp 			\

LST_INCS		=	incs/vector/Vector.hpp	\
					incs/map/Map.hpp		\
					incs/stack/Stack.hpp

LST_OBJS		=	${LST_SRCS:.cpp=.o}
LST_DEP			=	${LST_SRCS:.cpp=.d}

SUB_DIR	:= 	cmds	\

SRC =		$(addprefix ${PATH_SRCS}/,${LST_SRCS})
DEP =		$(addprefix ${PATH_DEP}/,${LST_DEP})
OBJS =		$(addprefix ${PATH_OBJS}/,${LST_OBJS})

all :				${NAME} Makefile

${NAME} :			${OBJS}
					${CC} ${FLAGS} ${OBJS} -o $@

${PATH_DEP}/%.d :	${PATH_SRCS}/%.cpp Makefile
					mkdir -p $(PATH_DEP) $(addprefix $(PATH_DEP)/, $(SUB_DIR))
					${CC} ${FLAGS} -MM -MF $@ -MT "${PATH_OBJS}/$*.o $@" $<


${PATH_OBJS}/%.o:	${PATH_SRCS}/%.cpp Makefile
					mkdir -p $(PATH_OBJS) $(addprefix $(PATH_OBJS)/, $(SUB_DIR))
					${CC} ${FLAGS} -c $< -o $@ -I ${PATH_INCLUDES}

clean :
					rm -rf obj dep

fclean :			clean
					rm -f ${NAME}

re :				fclean all

-include ${DEP}

.PHONY: all re clean fclean