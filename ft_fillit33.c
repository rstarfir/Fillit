/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit33.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:52:27 by rstarfir          #+#    #+#             */
/*   Updated: 2019/11/03 16:21:36 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int			fillit(char **map, t_tetra *tmp, int size)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	y = 0;
	if (tmp == NULL)
		return (1);
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (overlay(map, tmp, x, y, size) == 1)
			{
				ft_shift(map, tmp, x, y);
				if (overmap(tmp, size, x, y) == 1)
				{
					printf("enterif5\n");
					free(map);
					ft_mapsize(tmp, size + 1);
				}
			}
			printf("enterwhile3\n");
			else
			{
				printf("enterif4\n");
				if (fillit(map, tmp->next, size))
						return (1);
				else
					set_dot(map, tmp, x, y);
			}
			printf("error10\n");
			x++;
		}
		y++;
	}
	return (0);
}

int			overlay(char **map, t_tetra *tmp, int x, int y, int size)
{
	int		i;
	int		k;
	int		l;

	k = 0;
	i = 0;
	while (k < size)
	{
		l = 0;
		while (l < size)
		{
			if (map[tmp->tmino[i + 1] + y][tmp->tmino[i] + x] != '.'
			|| !(map[tmp->tmino[i + 1] + y][tmp->tmino[i] + x]))
				return (1);
			l++;
		}
		k++;
	}
}

int			overmap(t_tetra *tmp, int size, int x, int y)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		if (tmp->tmino[i] + x > (size - 1) ||
		tmp->tmino[i + 1] + y > (size - 1))
			return (1);
		i += 2;
	}
	return (0);
}

int			ft_shift(char **map, t_tetra *tmp, int x, int y)
{
	int		i;
	int		crd_x;
	int		crd_y;

	i = 0;
	crd_x = 0;
	crd_y = 0;
	printf("entershift\n");
	while (i <= 6)
	{
		crd_x = tmp->tmino[i] + x;
		crd_y = tmp->tmino[i + 1] + y;
		map[crd_x][crd_y] = tmp->alpha;
		i += 2;
		printf("shiftwhileloop\n");
	}
	return (1);
}

void		set_dot(char **map, t_tetra *tmp, int x, int y)
{
	int		i;
	int		crd_x;
	int		crd_y;

	i = 0;
	printf("entershift\n");
	while (i < 8)
	{
		crd_x = tmp->tmino[i] + x;
		crd_y = tmp->tmino[i + 1] + y;
		map[crd_x][crd_y] = '.';
		i += 2;
	}
}
