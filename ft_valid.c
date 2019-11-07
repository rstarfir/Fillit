/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:59:35 by aagrivan          #+#    #+#             */
/*   Updated: 2019/11/07 14:07:52 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

static int	ft_check_form(char *str)
{
	int		i;
	int		link;

	i = 0;
	link = 0;
	while (str[i])
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
		}
		i++;
	}
	return (link == 6 || link == 8) ? 1 : -1;
}

static int	ft_check_full(char *str)
{
	int		i;
	int		count;
	int		j;

	count = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '.' || str[i] == '#' || str[i] == '\n')
		{
			((str[i] == '#' || str[i] == '.') && (i < 19)) ? count++ : count;
			(str[i] == '#' && (i < 19)) ? j++ : j;
			if ((i + 1) % 5 == 0 && str[i] == '\n')
				count++;
			else if ((i + 1) % 5 == 0 && str[i] != '\n')
				return (0);
			((i + 1) % 21 == 0 && str[i] == '\n') ? count++ : count;
		}
		else
			ft_error();
		i++;
	}
	(j != 4) ? ft_error() : j;
	return (count == 20 || count == 21) ? 1 : -1;
}

t_tetra		*ft_valid(const int fd, t_tetra *tmp)
{
	size_t	r;
	int		count;
	size_t	r2;
	char	buffer[BUF_SSIZE + 1];
	char	c;

	c = 'A';
	count = 0;
	(read(fd, buffer, 0) < 0) ? ft_error() : -1;
	while ((r = read(fd, buffer, BUF_SSIZE)) > 0)
	{
		buffer[r] = '\0';
		r2 = r;
		tmp = create_list(buffer, tmp, c);
		c++;
		count++;
		if (count > 26)
			ft_error();
	}
	check_last_elem(r2);
	return (tmp);
}

void		check_last_elem(size_t r2)
{
	if (r2 != 20)
		ft_error();
}

t_tetra		*create_list(char *buffer, t_tetra *tmp, char c)
{
	if (ft_check_full(buffer) == 1 && ft_check_form(buffer) == 1)
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
	return (tmp);
}
