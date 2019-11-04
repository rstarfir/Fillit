/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:59:35 by aagrivan          #+#    #+#             */
/*   Updated: 2019/11/04 20:35:34 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int			ft_check_form(char *str)
{
	int		i;
	int		link;

	i = 0;
	link = 0;
	while (i < 19)
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == '#' && (i - 1) <= 18)
				link++;
			if (str[i - 1] == '#' && (i - 1) >= 0)
				link++;
			if (str[i + 5] == '#' && (i + 5) <= 18)
				link++;
			if (str[i - 5] == '#' && (i - 5) >= 0)
				link++;
			if ((link == 6) || (link == 8))
				return (1);
		}
		i++;
	}
	return (-1);
}

int			ft_check_full(char *str)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (i < 19)
	{
		if (str[i] != '.' || str[i] != '#' || str[i] != '\n')
			return (0);
		if ((i + 1) % 5 != 0 && str[i] == '\n')
			return (0);
		if ((i + 1) % 19 == 0 && str[i] == '\n')
			return (0);
		if (str[i] == '\n')
			count++;
		i++;
	}
	(str[i] != '\n') ? 0 : 1;
	return (-1);
}

t_tetra		*ft_valid(const int fd, t_tetra *tmp)
{
	size_t	r;
	int		count;
	char	buffer[BUF_SSIZE];
	char	c;

	c = 'A';
	count = 0;
	(read(fd, buffer, 0) <= 19) ? ft_error() : -1;	/*fix this*/
	while ((r = read(fd, buffer, BUF_SSIZE)) >= 20) // buffer maybe free 
	{
		buffer[r] = '\0';
		if (ft_check_full(buffer) == 1 || ft_check_form(buffer) == 1)
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
