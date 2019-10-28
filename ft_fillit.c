/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:52:27 by rstarfir          #+#    #+#             */
/*   Updated: 2019/10/28 20:43:50 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int			fillit(char **map, t_tetra *tmp, int size, int min_xy)
{
	int		i;
	int		x;
	int		y;
	int		j;

	y = min_xy / size;
	x = min_xy % size;
	i = -1;
	j = 0;
	printf("error1\n");
	if (tmp == NULL)
		return (1);
	printf("error2\n");
/*	if (map[y][x] != '.')
	{
		printf("error3\n");
		fillit(map, tmp, size, min_xy + 1);
//		return (fillit(map, tmp, size, min_xy + 1));
	}*/
	while (i++ <= size)
	{
		printf("error5\n");
		if (overlay(map, tmp, x, y) != 0)
		{
			printf("error6\n");
			if (overmap(size, x, y) == 1)
			{
				free(map);
				ft_mapsize(tmp, size + 1);
			}
			ft_shift(tmp, x, y);
			fillit(map, tmp, size, min_xy + 1);
		}
		printf("error10\n");
		map[tmp->tmino[j + 1]][tmp->tmino[j]] = tmp->alpha;
		tmp = tmp->next;
/*	if (fillit(map, tmp, size, min_xy + 1))
		return (1);
		else
		map[y][x] = '.';*/
	}
	return (1);
}

int			overlay(char **map, t_tetra *tmp, int x, int y)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		printf("error8\n");
		printf("x = %i y = %i\n", x, y);

				printf("x = %d\n", x);		printf("y = %d\n", y);
		if (map[y][x] != '.')
			{
				printf("error9\n");
				return (1);
			}
		i += 2;
				x = tmp->tmino[i];
		y = tmp->tmino[i + 1];
	}
	return (0);
}

int			overmap(int size, int x, int y)
{
//	printf("error\n");
	if (x > (size - 1) || y > (size - 1))
		return (1);
	else
		return (0);
//	return (x > (size - 1) || (y > (size - 1))) ? 1 : 0;
}

void		ft_shift(t_tetra *tmp, int x, int y)
{
	int		i;

	i = 0;
	while (i < 8)
	{
		tmp->tmino[i] = tmp->tmino[i] + x;
		tmp->tmino[i + 1] = tmp->tmino[i + 1] + y;
		i += 2;
	}
}
