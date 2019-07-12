/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:00:19 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/27 16:30:45 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void					setexp(char **str, int prec, int e)
{
	char				*i;
	char				*res;
	char				*s;

	res = ft_strnew(ft_strlen(*str) + 1 + 5);
	i = res;
	s = *str;
	prec += 2;
	while (*s && prec--)
		*i++ = *s++;
	*i++ = 'e';
	if (e < 0)
	{
		*i++ = '-';
		e *= -1;
	}
	else
		*i++ = '+';
	if (e < 10)
		*i++ = '0';
	(!e) ? ft_strcat(i, "0") : ft_strnbrcat(i, e);
	free(*str);
	*str = res;
}

char					*get_expg_type(long double f, t_spec *spec, int prec)
{
	int					exp;
	char				*res;

	f = get_exp(f, &exp);
	res = ft_ftoa(&f, prec, check_flag(spec->flags, HASH));
	if ((int)f > 4 && sign_num(res) < prec && res[ft_strlen(res) - 1] != '0')
		exp += fadjust(&res, 0);
	cut(res, check_flag(spec->flags, HASH));
	if (sign_num(res) > prec)
	{
		exp += fadjust(&res, 0);
		cut(res, check_flag(spec->flags, HASH));
	}
	super_hard_adjust(&res, spec, prec, 0);
	if (check_flag(spec->flags, HASH))
		pound(res, prec);
	setexp(&res, prec, exp);
	return (res);
}

char					*get_g_type(long double f, t_spec *spec, int prec,
																		int exp)
{
	char				*res;
	long double			copyf;

	copyf = f;
	if (exp < -4 || exp >= prec)
		res = get_expg_type(f, spec, prec);
	else
	{
		res = ft_ftoa(&f, ft_flen(f) ? prec : LDBL_DIG,
												check_flag(spec->flags, HASH));
		if ((int)f > 4 && sign_num(res) < prec
											&& res[ft_strlen(res) - 1] != '0')
			fadjust(&res, 1);
		cut(res, check_flag(spec->flags, HASH));
		if (sign_num(res) > prec)
		{
			fadjust(&res, 1);
			cut(res, check_flag(spec->flags, HASH));
		}
		super_hard_adjust(&res, spec, prec, 1);
		if (check_flag(spec->flags, HASH) && copyf != 0)
			pound(res, prec);
	}
	return (res);
}

char					*float_to_string(long double f, t_spec *spec, int prec)
{
	char				*res;
	int					exp;

	if (ft_tolower(spec->type) == 'g')
	{
		exp = get_adjusted_exp(f, spec, prec);
		res = get_g_type(f, spec, prec, exp);
	}
	else if (ft_tolower(spec->type) == 'e')
	{
		f = get_exp(f, &exp);
		res = ft_ftoa(&f, prec, check_flag(spec->flags, HASH));
		if ((int)f > 4)
			exp += fadjust(&res, 0);
		setexp(&res, prec, exp);
	}
	else
	{
		res = ft_ftoa(&f, prec, check_flag(spec->flags, HASH));
		if ((int)f > 4)
			fadjust(&res, 1);
	}
	return (((ft_strchr("EGF", spec->type))) ? ft_strupper(res) : res);
}

char					*getdouble(va_list *ap, t_spec *spec, char **sign)
{
	long double			f;
	int					prec;

	prec = (spec->prec == -1) ? (6)
			: (ft_max(spec->prec, ft_tolower(spec->type) == 'g'));
	if (spec->size == 'L')
		f = va_arg(*ap, long double);
	else
		f = (long double)va_arg(*ap, double);
	if (f != f)
		return (ft_strdup("nan"));
	if (f < 0 || 1 / f == -INFINITY)
	{
		*sign = ft_strdup("-");
		f *= -1;
	}
	else if (check_flag(spec->flags, PLUS))
		*sign = ft_strdup("+");
	else if (check_flag(spec->flags, SPACE))
		*sign = ft_strdup(" ");
	if (f > LDBL_MAX)
		return (ft_strdup("inf"));
	return (float_to_string(f, spec, prec));
}
