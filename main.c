/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:07:48 by aagrivan          #+#    #+#             */
/*   Updated: 2019/10/28 20:41:58 by aagrivan         ###   ########.fr       */
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
	t_tetra	*tmp;
	int		size;

	fd = 0;
	size = 0;
	if (ac != 2)
		ft_putendl("usage: fillit <name file>");
	else
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
			ft_error();
		tmp = ft_valid(fd);
		close(fd);
		size = ft_min_map(tmp);
		ft_mapsize(tmp, size);
	}
	return (0);
}
	