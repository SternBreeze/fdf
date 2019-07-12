/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:10:45 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/21 16:17:36 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnstr(char const *s, int n)
{
	int	len;

	if (!s)
		return (0);
	if (n > (len = ft_strlen(s)) || n < 0)
		write(1, s, len);
	else
		write(1, s, n);
	return (n);
}
