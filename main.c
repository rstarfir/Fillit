/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:07:48 by aagrivan          #+#    #+#             */
/*   Updated: 2019/10/23 17:54:57 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void		ft_error(void)
{
	ft_putendl("error");
	exit(1);
}

int         main(int ac, char **av)
{
	int		fd;

	fd = 0;
	if (ac != 2)
		ft_putendl("usage: fillit <name file>");
	else
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
			ft_error();
		ft_valid(fd); //free tetramin 
		//save - tetramin - t_list?
		//make map
		//solve map
		close(fd);
	}
	return (0);
}
	