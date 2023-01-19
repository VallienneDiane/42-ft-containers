# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 16:22:00 by dvallien          #+#    #+#              #
#    Updated: 2023/01/19 11:47:35 by dvallien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = container
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address

PATH_SRCS		=	srcs
PATH_DEP		=	dep
PATH_OBJS		=	obj
PATH_INCLUDES	=	incs

LST_SRCS		=	main.cpp

LST_INCS		=	Vector.hpp 					\
					enable_if.hpp				\
					equal.hpp					\
					is_integral.hpp 			\
					iterator_traits.hpp			\
					iterator_vector.hpp			\
					lexicographical_compare.hpp	\
					reverse_iterator.hpp		

LST_OBJS		=	${LST_SRCS:.cpp=.o}
LST_DEP			=	${LST_SRCS:.cpp=.d}


SRC =		$(addprefix ${PATH_SRCS}/,${LST_SRCS})
DEP =		$(addprefix ${PATH_DEP}/,${LST_DEP})
OBJS =		$(addprefix ${PATH_OBJS}/,${LST_OBJS})

all :				${NAME} Makefile

${NAME} :			${OBJS}
					${CC} ${FLAGS} ${OBJS} -o $@

${PATH_DEP}/%.d :	${PATH_SRCS}/%.cpp Makefile
					mkdir -p $(PATH_DEP)
					${CC} ${FLAGS} -MM -MF $@ -MT "${PATH_OBJS}/$*.o $@" $<


${PATH_OBJS}/%.o:	${PATH_SRCS}/%.cpp Makefile
					mkdir -p $(PATH_OBJS)
					${CC} ${FLAGS} -c $< -o $@ -I ${PATH_INCLUDES}

clean :
					rm -rf obj dep

fclean :			clean
					rm -f ${NAME}

re :				fclean all

-include ${DEP}

.PHONY: all re clean fclean