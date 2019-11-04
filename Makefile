# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 14:37:43 by rstarfir          #+#    #+#              #
#    Updated: 2019/11/04 17:41:08 by rstarfir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
FILES = ft_valid.c main.c ft_tetra.c ft_fillit.c ft_map.c
LIBFT = libft/*.c
LIBFT2 = libft/
HEADER = ft_fillit.h
OBJECTS = $(FILES:%.c=%.o)

all: $(NAME)

$(NAME):
	gcc  $(FILES) -o $(NAME) $(FILES) $(LIBFT) -I $(HEADER) -L $(LIBFT2)

clean: 
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re