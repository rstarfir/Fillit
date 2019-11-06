/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:03:44 by rstarfir          #+#    #+#             */
/*   Updated: 2019/11/06 20:58:21 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int			ft_min_map(t_tetra *tmp)
{
	int		count;
	int		size;

	count = 0;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	size = 0;
	(count == 1) ? size = 2 : 1;
	(count == 2) ? size = 3 : 1;
	(count == 3 || count == 4) ? size = 4 : 1;
	(count == 5 || count == 6) ? size = 5 : 1;
	(count == 7 || count == 8) ? size = 6 : 1;
	(count == 9 || count == 10) ? size = 7 : 1;
	(count >= 11 && count <= 16) ? size = 8 : 1;
	(count >= 17 && count <= 20) ? size = 9 : 1;
	(count >= 21 && count <= 25) ? size = 10 : 1;
	(count == 26) ? size = 11 : 1;
	return (size);
}

char		**ft_mapsize(int size)
{
	int		x;
	char	**map;

	x = 0;
	if (size == 0)
		ft_error();
	map = (char **)malloc(sizeof(char*) * size);
	while (x < size)
	{
		map[x] = (char *)malloc(sizeof(char) * size + 1);
		map[x] = ft_memset(map[x], '.', size);
		map[x][size + 1] = '\0';
		x++;
	}
	return (map);
}

void		free_map(char **map, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_memdel((void **)&map[i]);
		i++;
	}
	ft_memdel((void **)&map);
}

void		display_map(char **map, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putendl(map[i]);
		i++;
	}
}
