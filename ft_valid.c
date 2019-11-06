/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:59:35 by aagrivan          #+#    #+#             */
/*   Updated: 2019/11/05 23:34:58 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int			ft_check_form(char *str)
{
	int		i;
	int		link;

	i = 0;
	link = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == '#' && (i + 1) < 21)
				link++;
			if (str[i - 1] == '#' && (i - 1) > -1)
				link++;
			if (str[i + 5] == '#' && (i + 5) < 21)
				link++;
			if (str[i - 5] == '#' && (i - 5) > -1)
				link++;
			if ((link == 6) || (link == 8))
				return (1);
		}
		i++;
	}
	return (-1);
}

int			ft_check_full(char *str, int r)
{
	int		i;
	int		count;

	count = -1;
	i = 0;
	if (*str)
	{
		while (str[i])
		{
			if ((str[i] == '.' || str[i] == '#') && (i < 19))
				count++;
			if ((i + 1) % 5 == 0 && str[i] == '\n')
				count++;
			else if ((i + 1) % 5 == 0 && str[i] != '\n')
				return (0);
			if (((i + 1) % 21 == 0 && str[i] == '\n') || r == 20)
				count++;
			if (count > 19)
				return (1);
			i++;
		}
	}
	if (str[i] != '\n')
		return (0);

	return (-1);
}

t_tetra		*ft_valid(const int fd, t_tetra *tmp)
{
	size_t	r;
	int		count;
	char	buffer[BUF_SSIZE + 1];
	char	c;

	c = 'A';
	count = 0;
	(read(fd, buffer, 0) < 0) ? ft_error() : -1;	/*fix this*/
	while ((r = read(fd, buffer, BUF_SSIZE)) >= 19) // buffer maybe free 
	{
		buffer[r] = '\0';
		if (ft_check_full(buffer, r) == 1 && ft_check_form(buffer) == 1)
		{
			if (c == 'A')
				tmp = ft_tetra(buffer, c);
			else
				ft_addtetr(tmp, buffer, c);
		}
		else
		{
			ft_error();
			ft_del_elem(tmp);
		}
		c++;
		count++;
		if (count > 26)
			ft_error();
	}
	return (tmp);
}
