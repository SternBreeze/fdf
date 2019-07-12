/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_adjust.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 16:15:11 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/27 16:29:17 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void					cut(char *str, int dot)
{
	char				*s;

	s = str + ft_strlen(str) - 1;
	while (*s == '0')
		*s-- = '\0';
	if (*s == '.' && !dot)
		*s-- = '\0';
}

void					pound(char *s, int prec)
{
	int					dot;
	int					i;

	i = 0;
	dot = 0;
	while (s[i])
		if (s[i] == '.')
		{
			s++;
			if (i)
				dot = 1;
		}
		else if (s[i] == '0')
		{
			if (dot || i)
				i++;
			else
				s++;
		}
		else
			i++;
	while (i < prec)
		s[i++] = '0';
	s[i] = '\0';
}

void					super_hard_adjust(char **s, t_spec *spec, int prec,
																		int mod)
{
	int					i;
	int					del;
	char				*res;

	i = 0;
	del = 0;
	res = *s;
	while (sign_num(res) > prec)
	{
		while (res[i] == '0' || res[i] == '.')
			i++;
		del = res[((i) ? (ft_min(prec, sign_num(res)) + i)
							: (ft_max(prec, sign_num(res))))];
		res[((i) ? (ft_min(prec, sign_num(res)) + i)
							: (ft_max(prec, sign_num(res))))] = '\0';
		if (del >= '5')
			fadjust(&res, mod);
		cut(res, check_flag(spec->flags, HASH));
	}
	*s = res;
}

int						hard_adjust(char **str, char *s, int mod)
{
	s--;
	while (s >= *str && *s >= '9')
		*s-- = '0';
	if (s < *str && mod)
	{
		if (!(s = ft_strdup("1"))
			|| !(*str = ft_strmerge(2, &s, str)))
			exit(0);
	}
	else if (s < *str)
		*(s + 1) = '1';
	else
		(*s)++;
	return (1);
}

int						fadjust(char **str, int mod)
{
	char				*s;

	s = *str + ft_strlen(*str);
	while (--s >= *str)
		if (*s == '.' && s[-1] == '9')
			return (hard_adjust(str, s, mod));
		else if (*s == '9' && s == *str)
		{
			*s = '0';
			return (hard_adjust(str, s, mod));
		}
		else if (*s >= '9')
			*s = '0';
		else if (*s != '.')
		{
			(*s)++;
			return (0);
		}
	return (0);
}
