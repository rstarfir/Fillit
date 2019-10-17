/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:07:48 by aagrivan          #+#    #+#             */
/*   Updated: 2019/10/15 14:18:21 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int         main(int ac, char **av)
{
    int     fd;
    int     i;
    char    *line;

	i = 0;
	if (ac < 2)
		write(2, "File name missing.\n", 19);
	else if (ac == 2)
	{
		fd = open(av[i], O_RDONLY);
		ft_valid(&line, fd);
		close(fd);
	}
	else
        write(2, "Error0\n", 7);
	return (0);
}