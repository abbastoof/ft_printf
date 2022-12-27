# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 15:50:23 by mtoof             #+#    #+#              #
#    Updated: 2022/11/16 14:05:10 by mtoof            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c	\
		ft_isprint.c ft_memset.c ft_memcpy.c ft_memmove.c ft_strlen.c ft_tolower.c	\
		ft_toupper.c ft_memcmp.c ft_memchr.c ft_strncmp.c ft_strnstr.c ft_strrchr.c	\
		ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strdup.c ft_calloc.c ft_atoi.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_substr.c ft_strjoin.c	\
		ft_putendl_fd.c ft_strtrim.c ft_strmapi.c ft_itoa.c ft_striteri.c ft_split.c
SRC_B = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
		ft_lstmap_bonus.c
HEADER = libft.h
FLAGS = -Wall -Werror -Wextra

all: $(NAME)
	
$(NAME):
	cc $(FLAGS) -c $(SRC) -I $(HEADER)
	ar rcs $(NAME) $(SRC:.c=.o)

bonus: $(SRC_B:.c=.o)
	
$(SRC_B:.c=.o): $(SRC_B)	
	cc $(FLAGS) -c $(SRC_B) -I $(HEADER)
	ar rcs $(NAME) $(SRC_B:.c=.o)

clean:
	/bin/rm -f $(SRC:.c=.o) $(SRC_B:.c=.o)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
