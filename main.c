/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:07:48 by aagrivan          #+#    #+#             */
/*   Updated: 2019/10/19 15:53:52 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int         main(int ac, char **av)
{
	int		fd;
    char	*line;

	fd = 0;
	line = "sting";
	if (ac != 2)
		ft_putendl("usage: write fillit <name file>");
	else
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
			return (-1);
		ft_valid(line, fd); //free tetramin 
		//save - tetramin - t_list?
		//make map
		//solve map
		close(fd);
	}
	return (0);
}