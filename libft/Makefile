# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljohnson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/03 14:41:20 by ljohnson          #+#    #+#              #
#    Updated: 2022/01/04 14:53:28 by ljohnson         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re norm comp

NAME = libft.a
MAIN = 

#//////////////////////////////////////////////////////////////////////////////
#		ALL FILES
#//////////////////////////////////////////////////////////////////////////////

SRC_BOOL =	ft_isalnum.c		ft_isalpha.c		ft_isascii.c		ft_isdigit.c		ft_isprint.c	\
			ft_ischarset.c		ft_isnotcharset.c

SRC_LST =	ft_lstadd_back.c	ft_lstadd_front.c	ft_lstclear.c		ft_lstdelone.c		ft_lstiter.c	\
			ft_lstlast.c		ft_lstmap.c			ft_lstnew.c			ft_lstsize.c

SRC_MEM =	ft_bzero.c			ft_calloc.c			ft_memchr.c			ft_memcmp.c			ft_memcpy.c		\
			ft_memmove.c		ft_memset.c			ft_free.c

SRC_PRINT =	ft_int_putchar.c	ft_int_putnbr.c		ft_int_putptr.c		ft_putstr_fd.c		ft_putchar_fd.c	\
			ft_putendl_fd.c		ft_putnbr_fd.c		ft_int_putstr.c		ft_int_putnbr_base.c

SRC_PROJ =	ft_printf.c			get_next_line.c

SRC_STR =	ft_atoi.c			ft_int_strchr.c		ft_itoa.c			ft_split.c			ft_strchr.c		\
			ft_strdup.c			ft_striteri.c		ft_strjoin.c		ft_strlcat.c		ft_strlcpy.c	\
			ft_strlen.c			ft_strmapi.c		ft_strncmp.c		ft_strnjoin.c		ft_strnstr.c	\
			ft_strrchr.c		ft_strstr.c			ft_strtrim.c		ft_substr.c			ft_tolower.c	\
			ft_toupper.c		ft_atol.c

SRCS =	${addprefix lib_src/lib_bool/,${SRC_BOOL}}	${addprefix lib_src/lib_lst/,${SRC_LST}}		\
		${addprefix lib_src/lib_mem/,${SRC_MEM}}	${addprefix lib_src/lib_print/,${SRC_PRINT}}	\
		${addprefix lib_src/lib_proj/,${SRC_PROJ}}	${addprefix lib_src/lib_str/,${SRC_STR}}

#//////////////////////////////////////////////////////////////////////////////
#		OBJ CREATION
#//////////////////////////////////////////////////////////////////////////////

OBJS = ${addprefix ${OBJP},${subst ${SRCP},/,${SRCS:.c=.o}}}

SRCP = lib_src/
OBJP = lib_obj
INCP = ./lib_includes/

#//////////////////////////////////////////////////////////////////////////////
#		COMMAND SHORTCUTS
#//////////////////////////////////////////////////////////////////////////////

CC = gcc
CF = -Wall -Wextra -Werror
CS = -g -fsanitize=address
CG = -g3

NCF = norminette -R CheckForbiddenSourceHeader
NCD = norminette -R CheckDefine

AR = ar rcs
RM = rm -rf

#//////////////////////////////////////////////////////////////////////////////
#		RULES
#//////////////////////////////////////////////////////////////////////////////

all: ${NAME}

# Binary creation

${NAME}: ${OBJS}
	@${AR} ${NAME} ${OBJS}
	@echo ${NAME} complete

${OBJS}: ${OBJP}

${OBJP}:
	@mkdir ${OBJP}
	@mkdir	${OBJP}/lib_bool/	${OBJP}/lib_lst/	${OBJP}/lib_mem/	\
			${OBJP}/lib_print/	${OBJP}/lib_proj/	${OBJP}/lib_str/
	@echo creating obj directories

${OBJP}/%.o: ${SRCP}%.c ${INCP}libft.h
	${CC} ${CF} -c -o $@ $<

# Additional rules

norm:
	${NCF} ${SRCP}
	${NCD} ${INCP}

comp: ${SRCS} ${MAIN}
	${CC} ${CF} ${CS} $^
	${CC} ${CF} ${CG} $^

# Mandatory rules

clean:
	@${RM} ${OBJS}
	@echo all object files removed

fclean: clean
	@${RM} ${NAME} ${OBJP}
	@echo library removed

re: fclean all