# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/21 21:53:58 by therodri          #+#    #+#              #
#    Updated: 2022/11/26 21:56:51 by hlesny           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

FILES = ft_printf ft_printf_utils set_format convert convert_utils convert_and_print print_input\

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(SRCS_DIR), $(addsuffix .o, $(FILES)))

LIBFT_DIR = libft2/
LIBFT_NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS) ${LIBFT_DIR}${LIBFT_NAME}
	cp ${LIBFT_DIR}${LIBFT_NAME} $@
	${AR} $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

${LIBFT_DIR}${LIBFT_NAME}:
	make -C ${LIBFT_DIR}

clean:
	make -C ${LIBFT_DIR} clean
	rm -f $(OBJS)

fclean: clean
	make -C ${LIBFT_DIR} fclean
	rm -f $(NAME)

re: clean all

bonus: all

.PHONY: all clean fclean re bonus