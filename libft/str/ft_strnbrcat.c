/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnbrcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:52:45 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/16 15:02:02 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnbrcat(char *str, int n)
{
	char			*s;
	int				len;

	len = ft_nlen(n, 10);
	s = str + len - 1;
	while (len--)
	{
		*s-- = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
