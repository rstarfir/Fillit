/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aagrivan <aagrivan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:09:15 by aagrivan          #+#    #+#             */
/*   Updated: 2019/11/01 20:25:26 by aagrivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_FILLIT_H
# define FT_FILLIT_H

# include <fcntl.h>
# include "libft/libft.h"
# include <stdio.h>

# define BUF_SSIZE 21

typedef struct				s_tetra
{
    int						tmino[8];
	char					alpha;
    struct s_tetra			*next;
	struct s_tetra			*prev;
}							t_tetra;

typedef struct              s_coord
{
    int                     x_set;
    int                     y_set;
}                           t_coord;

t_tetra	*ft_valid(const int fd);
int		ft_check_full(char *str);
int		ft_check_form(char *str);
void	ft_error(void);
t_tetra *ft_tetra(char *buffer, char c);
t_tetra	*ft_addtetr(t_tetra *tmp, char *buffer, char c);
void	min_xy(int *src);
char	**ft_mapsize(t_tetra *tmp, int size);
void	free_map(char **map, int size);
int		ft_min_map(t_tetra *tmp);
void	display_map(char **map, int size);
int 	fillit(char **map, t_tetra *tmp, int size);
int		overlay(char **map, t_tetra *tmp, t_coord *xy, int size);
int		overmap(t_tetra *tmp, t_coord *xy, int size);
int		ft_shift(char **map, t_tetra *tmp, int x, int y);
void	set_dot(char **map, t_tetra *tmp, int x, int y);

#endif
