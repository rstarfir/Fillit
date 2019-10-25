/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:03:44 by rstarfir          #+#    #+#             */
/*   Updated: 2019/10/25 20:54:13 by rstarfir         ###   ########.fr       */
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
	(count == 5 || count == 6) ? size = 5 : 1;
	(count == 7 || count == 8) ? size = 6 : 1;
	(count == 9 || count == 10) ? size = 7 : 1;
	(count >= 11 && count <= 16) ? size = 8 : 1;
	(count >= 17 && count <= 20) ? size = 9 : 1;
	(count >= 21 && count <= 25) ? size = 10 : 1;
	(count == 26) ? size = 11 : 1;
	return (size);
}

char		**ft_mapsize(t_tetra *tmp, int size)
{
	int		x;
	char	**map;

	x = 0;
	map = (char **)malloc(sizeof(char*) * size);//guard from leaks
	while (x < size)
	{
		map[x] = (char *)malloc(sizeof(char) * size);//guard from leaks
		map[x] = ft_memset(*map, '.', size);
		x++;
	}
	fillit(map, tmp, size);
	display_map(map, size);
	return (map);
}

void		display_map(char **map, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		//ft_putendl(*map);
		ft_putendl(map[i]);
		i++;
	}
}
