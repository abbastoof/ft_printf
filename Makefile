# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atoof <atoof@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 16:18:38 by atoof             #+#    #+#              #
#    Updated: 2022/12/07 17:46:13 by atoof            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ft_printf.h
FLAG = -Wall -Wextra -Werror
SRC = ft_substr.c ft_putchar_fd.c ft_printf.c

all: $(NAME)

$(NAME):
	cc $(FLAG) -c $(SRC)
	ar rus $(NAME) $(SRC:.c=.o)

clean:
	/bin/rm -f $(SRC:.c=.o)
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
