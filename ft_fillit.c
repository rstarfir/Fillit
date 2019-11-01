/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:47:55 by aagrivan          #+#    #+#             */
/*   Updated: 2019/11/01 20:48:09 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int			fillit(char **map, t_tetra *tmp, int size) //char
{
	t_coord	*xy;

	xy->x_set = 0;
	xy->y_set = 0;
	while (xy->y_set < size)
	{
		xy->x_set = 0;
		while (xy->x_set < size)
		{
			if (overlay(map, tmp, xy, size) == 1)
			{
				printf("overlay");
				//ft_shift();
			}
			xy->x_set++;
		}
		xy->y_set++;
	}
	return (0);
}

int			overmap(t_tetra *tmp, t_coord *xy, int size)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (tmp->tmino[i] + xy->x_set > (size - 1) ||
		tmp->tmino[i + 1] + xy->y_set > (size - 1))
			return (1);
		i += 2;
	}
	return (0);
}

int			overlay(char **map, t_tetra *tmp, t_coord *xy, int size)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	x = tmp->tmino[i] + xy->x_set;
	y = tmp->tmino[i + 1] + xy->y_set;
	while (i <= 6 && map[x][y] == '.')
	{
		i += 2;
		x = tmp->tmino[i] + xy->x_set;
		y = tmp->tmino[i + 1] + xy->y_set;
	}
	return (i != 8);
	/*int		i;
	int		x;
	int		y;

	y = 0;
	i = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (map[tmp->tmino[i + 1] + xy->y_set][tmp->tmino[i] + xy->x_set] != '.'
			|| !(map[tmp->tmino[i + 1] + xy->y_set][tmp->tmino[i] + xy->x_set]))
				return (1);
			x++;
		}
		y++;
	}*/
	return (0);
}

/*if (overmap(tmp, xy, size) == 1)
	{
		free_map(map, size);
		ft_mapsize(tmp, size + 1);
	}*/
