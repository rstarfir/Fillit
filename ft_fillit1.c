/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:59:35 by aagrivan          #+#    #+#             */
/*   Updated: 2019/10/19 15:33:50 by aagrivan         ###   ########.fr       */
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
			if (str[i] != '.' || str[i] != '#' || str[i] != '\n')
				return (-1);
			if (str[i + 1] == '\n')
			i++;
		}
		return (1);
	}
	return (-1);
}

int			ft_valid(char *line)
{
	int		count;
	int		len;
	char	*str;
	int		i;

	i = 0;
	count = 0;
	if (!(line))
		return (-1);
	len = ft_strlen(line);
	while (i < len)
	{
		if (ft_check_full(line) == 1)
		{
			if (ft_check_form(line) != 1)
				ft_strclr(str);
			else
				ft_putendl("All good check_form.");
//			ft_putendl("All good check_full.");
		}
		i += 21;
//		printf("%zu\n", r);
		count++;
		printf("Figure %i\n", count);
	}
//	printf("Error0\n");
//	printf("%zu\n", r);
	return (0);
}
