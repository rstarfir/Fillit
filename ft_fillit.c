/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 18:59:35 by aagrivan          #+#    #+#             */
/*   Updated: 2019/10/15 14:16:48 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int			ft_valid(char **line, const int fd)
{
	size_t	r;
	char	buffer[BUFF_SSIZE + 1];
	int		count;

	if (fd < 0 || !(line) || read(fd, buffer, 0) < 0)
		return (-1);
	//if (read (fd, )> 545)
	//	return (-1);
	while ((r = read(fd, buffer, BUFF_SSIZE)))
	{
		printf("%zu\n", r);
		count++;
		printf("%i\n", count);
	}
	printf("Error0");
	printf("%zu\n", r);
	return (0);
}
