/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:07:48 by aagrivan          #+#    #+#             */
/*   Updated: 2019/11/07 14:03:51 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int			main(int ac, char **av)
{
	int		fd;
	t_tetra	*tmp;
	int		size;
	char	**map;

	fd = 0;
	tmp = NULL;
	size = 0;
	if (ac != 2)
		ft_putendl("usage: fillit <name file>");
	else
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
			ft_error();
		tmp = ft_valid(fd, tmp);
		close(fd);
		size = ft_min_map(tmp);
		map = ft_mapsize(size);
		return ((!solve_tetr(map, tmp, size)) ? -1 : 0);
	}
	return (0);
}

void		ft_error(void)
{
	ft_putendl("error");
	exit(1);
}

int			solve_tetr(char **map, t_tetra *tmp, int size)
{
	while (!fillit(map, tmp, size))
	{
		free_map(map, size);
		size++;
		map = ft_mapsize(size);
	}
	display_map(map, size);
	free_map(map, size);
	ft_del_elem(tmp);
	return (0);
}
