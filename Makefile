# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 14:37:43 by rstarfir          #+#    #+#              #
#    Updated: 2019/11/01 20:25:59 by aagrivan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY = all clean fclean re
NAME = fillit
FLAGS = -Wall -Wextra -Werror
FILES = ft_valid.c main.c ft_tetra.c ft_fillit.c ft_map.c
LIBFT = libft/*.c
LIBFT2 = libft/
HEADER = ft_fillit.h 

all: $(NAME)

$(NAME):
	gcc  -o $(NAME) $(FILES) $(LIBFT) -I $(HEADER) -L $(LIBFT2)

clean: 
	/bin/rm -f $(NAME)

re: clean all
