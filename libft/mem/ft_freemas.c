/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freemas.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmors-um <gmors-um@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 18:32:17 by gmors-um          #+#    #+#             */
/*   Updated: 2019/02/08 18:27:24 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_freemas(char ***mas, int ret)
{
	char			**m;

	m = *mas;
	ft_free_content(m);
	if (*mas)
		free(*mas);
	*mas = NULL;
	return (ret);
}
