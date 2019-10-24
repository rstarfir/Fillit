/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:03:44 by rstarfir          #+#    #+#             */
/*   Updated: 2019/10/24 22:36:54 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int			ft_mapsize(int *count)
{
	if (count == 1)
		return (2);
	if (count == 2)
		return (3);
	if (count == 3 || count == 4)
		return (4);
	if (count == 5 || count == 6)
		return (5);
	if (count == 7 || count == 8);
		return (6);
	if (count == 9 || count == 10)
		return (7);
	if (count >= 11 && count <= 16)
		return (8);
	if (count >= 17 && count <= 20)
		return (9);
	if (count >= 21 && count <= 25) 
		return (10);
	if (count == 26)
		return (11);	
	//printf("%i\n", count);
	//create_map();
	return (0);
}

int			ft_count(t_tetra *tmp)
{
	int		count;

	count = 0;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	ft_mapsize(count)
	return (tmp);
}
