/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:34:24 by jjacobso          #+#    #+#             */
/*   Updated: 2019/04/04 18:32:09 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					check_flag(char flags, char flag)
{
	return ((flags & flag) != 0);
}

void				set_flag(t_spec *spec, char c)
{
	int				i;

	i = 0;
	while (FLAGS[i] != c && i < (int)ft_strlen(FLAGS) + 1)
		i++;
	if (i < (int)ft_strlen(FLAGS))
		spec->flags |= (int)ft_pow(2, i);
}

char				char_to_flag(char c)
{
	int				i;

	i = 0;
	while (FLAGS[i] != c && i < 6)
		i++;
	return ((int)ft_pow(2, i));
}

int					check_narg(const char *str)
{
	int				i;

	i = 0;
	while (++i < 6)
		if (str[i] == '$')
			return (1);
		else if (!ft_isdigit(str[i]))
			return (0);
	return (0);
}
