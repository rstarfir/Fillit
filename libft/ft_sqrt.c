/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstarfir <rstarfir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:43:28 by rstarfir          #+#    #+#             */
/*   Updated: 2019/09/06 20:10:56 by rstarfir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int sq;

	sq = 0;
	if (nb > 0)
	{
		while (sq <= (nb / 2))
		{
			if ((sq * sq) == nb)
			{
				return (sq);
			}
			sq++;
		}
	}
	return (0);
}
