# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpicoule <tpicoule@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 09:30:10 by tpicoule          #+#    #+#              #
#    Updated: 2023/04/05 14:07:02 by tpicoule         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

SOURCES		= push_swap.c \
			  instrct.c \
			  instrct_2.c \
			  instrct_3.c \
			  checker_args.c \
			  push_swap_utils.c \
			  push_swap_utils_2.c \
			  push_swap_utils_3.c \
			  push_swap_utils_4.c \
			  random_nbr.c \
			  random_number_100.c
OBJECTS		= ${SOURCES:.c=.o}
RM			= rm -f
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: 	${OBJECTS}

all:		${NAME}

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
