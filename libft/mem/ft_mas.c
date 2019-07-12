/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:54:55 by jjacobso          #+#    #+#             */
/*   Updated: 2019/02/16 12:32:57 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			**ft_mas(int x, int y, int c)
{
	int		**res;
	int		i;
	int		j;

	if (!(res = (int **)malloc(sizeof(int *) * x)))
		return (NULL);
	i = -1;
	while (++i < x)
		if (!(res[i] = (int *)malloc(sizeof(int) * y)))
			return (NULL);
	i = -1;
	while (++i < x)
	{
		j = -1;
		while (++j < y)
			res[i][j] = c;
	}
	return (res);
}
