# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgabriel <hgabriel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/08 18:41:06 by hgabriel          #+#    #+#              #
#    Updated: 2022/06/15 05:11:21 by hgabriel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ${LIB}

SRCS 		=  handle_c.c handle_id.c handle_ptr.c handle_str.c handle_u.c handle_xX.c \
			   ft_printf_parser.c ft_printf_utils.c ft_printf.c \

SRCSDIR		= srcs/
OBJSDIR 	= obj/

OBJS 		= $(addprefix $(OBJSDIR), ${SRCS:.c=.o})

LIB			= libftprintf.a
LIBFT		= libft/
INCLUDES	= includes

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	make re -C ${LIBFT}
	ar rcs ${LIB} ${OBJS} ${LIBFT}*.o

$(OBJSDIR)%.o: $(SRCSDIR)%.c
	@mkdir -p $(OBJSDIR)
	${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o $@

clean:
	rm -rf ${OBJSDIR}

fclean: clean
	rm -f ${LIB}

re: fclean all

.PHONY: all clean fclean re bonus