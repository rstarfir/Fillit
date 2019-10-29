/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:10:20 by rstarfir          #+#    #+#             */
/*   Updated: 2019/10/26 17:34:51 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

void			min_xy(int *src)
{
	int			min_x;
	int			min_y;
	int			i;

	i = 2;
	min_x = src[0];
	min_y = src[1];
	while (i < 8)
	{
		min_x = (src[i] < min_x) ? src[i] : min_x;
		min_y = (src[i + 1] < min_y) ? src[i + 1] : min_y;
		i += 2;
	}
	//printf("min_x = %i, min_y = %i", min_x, min_y);
	i = 0;
	while (i < 8)
	{
		src[i] -= min_x;
		src[i + 1] -= min_y;
		i += 2;
	}
}

void			ft_params(char *buffer, int *src)
{
	int			i;
	int			j;
//	int 		count; // del

	i = 0;
	j = 0;
//	count = 0;
	while (i++ < 21)
		if (buffer[i] == '#')
		{
			src[j] = i % 5; // x
			src[j + 1] = i / 5; // y
			j += 2;
		}
	min_xy(src);
	/*i = 0;
	while (i < 8)
	{
		printf("src[%i] = %d\n", count, src[i]);
		i++;
		count++;
	}*/
}

t_tetra			*ft_tetra(char *buffer, char c)
{
	t_tetra		*tmp;
	int			i;
	int			j;

	j = 0;
	i = 0;
	if (!(tmp = (t_tetra *)malloc(sizeof(t_tetra))))
		ft_error();
	ft_params(buffer, tmp->tmino);
	tmp->alpha = c;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

t_tetra			*ft_addtetr(t_tetra *tmp, char *buffer, char c)
{
	t_tetra		*tmp1;
	t_tetra		*p;

	if (!(tmp1 = (t_tetra *)malloc(sizeof(t_tetra))))
		ft_error();
	p = tmp->next;
	tmp->next = tmp1;
	ft_params(buffer, tmp1->tmino);
	tmp1->alpha = c;
	tmp1->next = p;
	tmp1->prev = tmp;
	if (p != NULL)
		p->prev = tmp1;
	return (tmp1);
}