/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:52:27 by rstarfir          #+#    #+#             */
/*   Updated: 2019/10/25 20:53:20 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void		fillit(char **map, t_tetra *tmp, int size)
{
	int			max_x;
	int			max_y;
	int			i;
	int			j;

	i = 2;
	max_x = src[0];
	max_y = src[1];
	while (i < 8)
	{
		max_x = (src[i] > max_x) ? src[i] : max_x;
		max_y = (src[i + 1] < max_y) ? src[i + 1] : max_y;
		i += 2;
	}
	j = 0;
	while (j < 8)
	{
		map[tmp->tmino[j + 1]][tmp->tmino[j]] = tmp->alpha;

		if (max_x > (size - 1))
		{
			size += 1;
			ft_mapsize(tmp, size);
		}
		if (max_y > (size - 1))
		{
			size += 1;
			ft_mapsize(tmp, size);
		}
		j += 2;
	}
}
