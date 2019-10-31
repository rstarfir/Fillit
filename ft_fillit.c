/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:52:27 by rstarfir          #+#    #+#             */
/*   Updated: 2019/10/31 21:25:45 by rstarfir         ###   ########.fr       */
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
			printf("enterwhile3\n");
			if (overmap(tmp, size, x, y) == 1)
			{
				printf("enterif5\n");
				free(map);
				ft_mapsize(tmp, size + 1);
			}
			else
			{
				if (overlay(map, tmp, x, y) == 8)
				{
					if (ft_shift(map, tmp, x, y))
					{
						printf("enterif4\n");
						if (fillit(map, tmp->next, size))
							return (1);
						else
							set_dot(map, tmp, x, y);
					}
				}
			}
			printf("error10\n");
			x++;
		}
		y++;
	}
	return (0);
}

int			overlay(char **map, t_tetra *tmp, int x, int y)
{
	int		i;
	int		xx;
	int		yy;

	i = 0;
	xx = tmp->tmino[i] + x;
	yy = tmp->tmino[i + 1] + y;
	while (i <= 6 && map[yy][xx] == '.')
	{
		i += 2;
		printf("overlay\n");
		xx = tmp->tmino[i] + x;
		yy = tmp->tmino[i + 1] + y;
		printf("x = %d\n", x);
		printf("y = %d\n", y);
	}
	return (i != 8);
}

int			overmap(t_tetra *tmp, int size, int x, int y)
{
	if (tmp->tmino[0] + x < size &&
	tmp->tmino[1] + y < size &&
	tmp->tmino[2] + x < size &&
	tmp->tmino[3] + y < size &&
	tmp->tmino[4] + x < size &&
	tmp->tmino[5] + y < size &&
	tmp->tmino[6] + x < size &&
	tmp->tmino[7] + y < size)
		return (0);
	else
		return (1);
}

int			ft_shift(char **map, t_tetra *tmp, int x, int y)
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
		map[crd_y][crd_x] = tmp->alpha;
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
		map[crd_y][crd_x] = '.';
		i += 2;
	}
}
