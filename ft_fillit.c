/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:59:35 by aagrivan          #+#    #+#             */
/*   Updated: 2019/10/17 22:15:26 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int			ft_check_form(char *str)
{
	int		i;
	int		link;

	i = 0;
	link = 0;
	while (i < 21)
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == '#' && (i + 1) < 21)
				link++;
			if (str[i - 1] == '#')
				link++;
			if (str[i + 5] == '#' && (i + 5) < 21)
				link++;
			if (str[i - 5] == '#')
				link++;
			if ((link == 6) || (link == 8))
				return (1);
		}
//		printf("All good check_form - %i.\n", i);
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
	if (*str)
	{
		while (str[i])
		{
			if (str[i] == '.' || str[i] == '#' || str[i % 5] == '\n')
				count++;
			i++;
		}
		return (1);
	}
	return (-1);
}

int			ft_valid(char *line, const int fd)
{
	size_t	r;
	int		count;
	char	buffer[BUF_SSIZE + 1];
	char	*str;

	count = 0;
	if (!(line) || read(fd, buffer, 0) < 0)
		return (-1);
	//if (read (fd, )> 545)
	//	return (-1);
	while ((r = read(fd, buffer, BUF_SSIZE)) > 19)
	{
		buffer[r] = '\0';
		str = ft_strnew(21);
		str = ft_strcpy(str, buffer);
		if (ft_check_full(str) == 1)
		{
			if (ft_check_form(str) != 1)
				ft_strclr(str);
			else
				ft_putendl("All good check_form.");
//			ft_putendl("All good check_full.");
		}
//		printf("%zu\n", r);
		count++;
		printf("Figure %i\n", count);
	}
//	printf("Error0\n");
//	printf("%zu\n", r);
	return (0);
}
