/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:07:48 by aagrivan          #+#    #+#             */
/*   Updated: 2019/10/19 18:50:27 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int         main(int ac, char **av)
{
	int		fd;
    char	buffer[BUF_SSIZE + 1];
	int		res;

	fd = 0;
	if (ac != 2)
		ft_putendl("usage: write fillit <name file>");
	else
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
			return (-1);
		if ((res = read(fd, buffer, BUF_SSIZE)) < 0)
			return (-1);
		buffer[res] = '\0';
		if (res < 20 || res > 545)
			return (-1);
		close(fd);
		ft_valid(buffer); //free tetramin 
		//save - tetramin - t_list?
		//make map
		//solve map
	}
	return (0);
}
