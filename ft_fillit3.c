/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:59:35 by aagrivan          #+#    #+#             */
/*   Updated: 2019/10/19 18:47:47 by rstarfir         ###   ########.fr       */
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
			if (str[i + 1] == '#' && (i + 1) < 20)
				link++;
			if (str[i - 1] == '#')
				link++;
			if (str[i + 5] == '#' && (i + 5) < 20)
				link++;
			if (str[i - 5] == '#')
				link++;
			if ((link == 6) || (link == 8))
				return (1);
		}
	//	printf("All good check_form - %i.\n", i);
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
			if (str[i] == '.' || str[i] == '#')
				count++;
			if ((i + 1) % 5 == 0 && str[i] == '\n')
				count++;
			if (count > 19)
				return (1);
			i++;
		}
//		printf("All good check_form_full\n");
		return (-1);
	}
	return (-1);
}

int			ft_valid(char *line)
{
	int		count;
	char	*str;
	size_t	len;
	int		i;

	count = 0;
	if (!(line))
		return (-1);
	len = ft_strlen(line);
	
	while (i < 545)
	{
	//	str = ft_strnew(21);
	//	str = ft_strcpy(str, buffer);
		if (ft_check_full(line) == 1)
		{
			if (ft_check_form(line) != 1)
			{
				ft_strclr(line);
				ft_putendl("NOT");
			}
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


