# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 11:59:06 by ljohnson          #+#    #+#              #
#    Updated: 2022/01/14 14:56:11 by ljohnson         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re norm

NAME = push_swap
LIBFT = libft/libft.a

#//////////////////////////////////////////////////////////////////////////////
#		ALL FILES
#//////////////////////////////////////////////////////////////////////////////

SRCS =	ps_src/push_swap.c			ps_src/ps_utils.c			ps_src/ps_hub.c				ps_src/ps_sort_small.c	\
		ps_src/ps_sort_big.c		ps_src/ps_maths.c	\
		ps_src/ps_inst_swap.c		ps_src/ps_inst_rot.c		ps_src/ps_inst_revrot.c		ps_src/ps_inst_push.c	\
		ps_src/ps_display.c
HEAD = ps_inc/push_swap.h
OBJS = ${SRCS:.c=.o}

#//////////////////////////////////////////////////////////////////////////////
#		COMMAND SHORTCUTS
#//////////////////////////////////////////////////////////////////////////////

CC = gcc
CF = -Wall -Wextra -Werror
CI = -I
CS = -g -fsanitize=address
CG = -g3

RM = rm -rf

#//////////////////////////////////////////////////////////////////////////////
#		RULES
#//////////////////////////////////////////////////////////////////////////////

all: ${NAME}

# Binary creation

${NAME}: ${OBJS} ${HEAD} ${LIBFT} Makefile
	${CC} ${CF} ${OBJS} ${LIBFT} -o ${NAME}

%.o : %.c ${HEAD} ${LIBFT}
	${CC} -c ${CF} $< -o ${<:.c=.o}

${LIBFT}: libft/Makefile
	make -C libft/

# Mandatory rules

clean:
	${RM} ${OBJS}
	
fclean: clean
	${RM} ${NAME}
	make fclean -C libft/

re: fclean all