/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:09:15 by aagrivan          #+#    #+#             */
/*   Updated: 2019/10/15 14:16:57 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h>

# define BUFF_SSIZE 21


int		ft_valid(char **line, const int fd);

#endif