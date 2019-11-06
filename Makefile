# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 14:37:43 by rstarfir          #+#    #+#              #
#    Updated: 2019/11/05 21:04:17 by rstarfir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fillit

LIBFT = libft

CFLAGS = -g -Wall -Wextra -Werror

LFLAGS = -L $(LIBFT) -lft

CC = gcc

SRCS = ft_valid.c \
	main.c \
	ft_tetra.c \
	ft_fillit.c \
	ft_map.c

OBJS = $(SRCS:%.c=%.o)

INCLUDES = libft/includes

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -o $@ -c $<

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all
  