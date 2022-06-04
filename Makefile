# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgabriel <hgabriel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/08 18:41:06 by hgabriel          #+#    #+#              #
#    Updated: 2022/06/03 13:40:06 by hgabriel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		=  ft_printf.c		\
			   ft_printf_parser.c	\
			   ft_printf_utils.c	\
			   handle_c.c			\
			   handle_id.c			\
			   handle_ptr.c			\
			   handle_str.c			\
			   handle_u.c			\
			   handle_xX.c			\

OBJSDIR 	= obj/

OBJS 		= $(addprefix $(OBJSDIR), ${SRCS:.c=.o})

NAME		= ${LIB}
LIB			= libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${LIB} ${OBJS}

$(OBJSDIR)%.o: %.c
	@mkdir -p $(OBJSDIR)
	${CC} ${CFLAGS} -I. -c $< -o $@

clean:
	rm -rf ${OBJSDIR}

fclean: clean
	rm -f ${LIB}

re: fclean all

.PHONY: all clean fclean re bonus
