/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 17:10:01 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/27 16:29:39 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int						sign_num(char *s)
{
	int					i;
	int					dot;

	i = 0;
	dot = 0;
	while (s && (*s == '0' || *s == '.'))
		if (*s++ == '.')
			dot = 1;
	while (s[i])
		if (s[i] == '.')
		{
			s++;
			dot = 1;
		}
		else if (s[i] == '0')
		{
			if (dot)
				i++;
			else
				s++;
		}
		else
			i++;
	return (i);
}

int						get_adjusted_exp(long double f, t_spec *spec, int prec)
{
	char				*res;
	int					exp;

	exp = 0;
	if ((int)(f = get_exp(f, &exp)) > 4)
	{
		res = ft_ftoa(&f, prec, check_flag(spec->flags, HASH));
		exp += fadjust(&res, 0);
		free(res);
	}
	return (exp);
}

long double				get_exp(long double f, int *exp)
{
	*exp = 0;
	while (f != 0 && ft_fabs(f) < 1)
	{
		f *= 10;
		--*exp;
	}
	while (f >= 10)
	{
		f /= 10;
		++*exp;
	}
	return (f);
}

char					*set_int_part(long double *f, char *s, int intlen)
{
	int					c;

	while (1)
	{
		intlen--;
		c = ft_fdiv(*f, intlen);
		*s++ = "0123456789abcdef"[c];
		*f = *f - (long double)c * ft_fpow(10, intlen);
		if (*f < 1)
		{
			while (intlen > 0)
			{
				*s++ = '0';
				intlen--;
			}
			break ;
		}
	}
	return (s);
}

char					*ft_ftoa(long double *f, int prec, int dot)
{
	char				*res;
	char				*i;
	int					intlen;

	intlen = ft_flen(*f);
	if (!(res = ft_strnew(intlen + prec + 1 + 6)))
		return (NULL);
	i = set_int_part(f, res, intlen);
	if (dot || prec > 0)
		*i++ = '.';
	while (prec-- > 0)
	{
		*f *= 10;
		*i++ = "0123456789abcdef"[(int)*f % 10];
		*f = *f - (long double)ft_fdiv(*f, 0);
	}
	*f *= 10;
	return (res);
}
