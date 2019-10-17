# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/28 11:50:47 by aagrivan          #+#    #+#              #
#    Updated: 2019/10/17 19:16:29 by rstarfir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY = all clean fclean re
NAME = fillit
FLAGS = -Wall -Wextra -Werror
FILES = ft_fillit.c main.c
LIBFT = libft/*.c
LIBFT2 = libft/
HEADER = ft_fillit.h 

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -o $(NAME) $(FILES) $(LIBFT) -I $(HEADER) -L $(LIBFT2)

clean: 
	/bin/rm -f $(NAME)

re: clean all
