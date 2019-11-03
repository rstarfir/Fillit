/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 14:47:55 by aagrivan          #+#    #+#             */
/*   Updated: 2019/11/03 18:10:37 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int			fillit(char **map, t_tetra *tmp, int size)
{
	if (!tmp)
		return (1);
	tmp->tmino[8] = 0;
	tmp->tmino[9] = 0;

	while (!overmap(tmp, size, 'y'))
	{
		while (!overmap(tmp, size, 'x'))
		{
			if (!overlay(map, tmp))
			{
				fill_the_map(map, tmp, tmp->alpha);
				if (fillit(map, tmp->next, size))
					return (1);
				else
					fill_the_map(map, tmp, '.');
			}
			(tmp->tmino[8])++;
		}
		tmp->tmino[8] = 0;
		(tmp->tmino[9])++;
	}
	return (0);
}

int			overmap(t_tetra *tmp, int size, char xy)
{
	int		i;

	i = 0;
	if (xy == 'x')
	{
		while (i <= 6)
		{
			if (tmp->tmino[i] + tmp->tmino[8] > size - 1)
				return (1);
			i += 2;
		}
	}
	else
	{
		while (i <= 6)
		{
			if (tmp->tmino[i + 1] + tmp->tmino[9] > size - 1)
				return (1);
			i += 2;
		}
	}
	return (0);
}

int			overlay(char **map, t_tetra *tmp)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	x = 0;
	y = 0;
	while (i <= 6)
	{
		x = tmp->tmino[i] + tmp->tmino[8];
		y = tmp->tmino[i + 1] + tmp->tmino[9];
		if (map[y][x] != '.')
			return (1);
		i += 2;
	}
	return (0);
}

void		fill_the_map(char **map, t_tetra *tmp, char c)
{
	int		i;
	int		x;
	int		y;

	x = 0;
	y = 0;
	i = 0;
	while (i <= 6)
	{
		x = tmp->tmino[i] + tmp->tmino[8];
		y = tmp->tmino[i + 1] + tmp->tmino[9];
		map[y][x] = c;
		i += 2;
	}
}
