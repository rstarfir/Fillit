/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:09:15 by aagrivan          #+#    #+#             */
/*   Updated: 2019/11/05 19:58:45 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include <fcntl.h>
# include "libft.h"
# include <stdio.h>

# define BUF_SSIZE 21

typedef struct				s_tetra
{
    int						tmino[10];
	char					alpha;
    struct s_tetra			*next;
}							t_tetra;

t_tetra	*ft_valid(const int fd, t_tetra *tmp);
int		ft_check_full(char *str, int r);
int		ft_check_form(char *str);
void	ft_error(void);
t_tetra *ft_tetra(char *buffer, char c);
t_tetra	*ft_addtetr(t_tetra *tmp, char *buffer, char c);
void	min_xy(int *src);
char	**ft_mapsize(int size);
void	free_map(char **map, int size);
int		ft_min_map(t_tetra *tmp);
void	display_map(char **map, int size);
int 	fillit(char **map, t_tetra *tmp, int size);
int		overlay(char **map, t_tetra *tmp);
int		overmap(t_tetra *tmp, int size, char xy);
void	fill_the_map(char **map, t_tetra *tmp, char c);
t_tetra	*ft_del_elem(t_tetra *tmp);

#endif
