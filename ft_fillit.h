/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:09:15 by aagrivan          #+#    #+#             */
/*   Updated: 2019/10/18 16:17:02 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h>

# define BUF_SSIZE 21
typedef struct              s_tetramino
{
    char                    letter;
    struct s_tetramino      *next;
}                           t_tetramino;

int		ft_valid(char *line, const int fd);
int		ft_check_full(char *str);
int		ft_check_form(char *str);

#endif