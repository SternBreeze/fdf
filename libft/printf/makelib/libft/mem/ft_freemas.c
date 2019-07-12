/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freemas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmors-um <gmors-um@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 18:32:17 by gmors-um          #+#    #+#             */
/*   Updated: 2018/12/25 19:52:26 by gmors-um         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_freemas(char ***mas, int size, int ret)
{
	char			**m;

	m = *mas;
	ft_free_content(m, size);
	if (*mas)
		free(*mas);
	*mas = NULL;
	return (ret);
}
