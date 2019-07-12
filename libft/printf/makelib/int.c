/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:25:08 by jjacobso          #+#    #+#             */
/*   Updated: 2019/07/12 17:32:57 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int				getbase(t_spec *spec)
{
	if (check_flag(spec->flags, BIN))
	{
		if (ft_strchr("oOxX", spec->type))
			exit(0);
		return (2);
	}
	if (spec->type == 'o' || spec->type == 'O')
		return (8);
	if (spec->type == 'x' || spec->type == 'X')
		return (16);
	return (10);
}

uintmax_t		get_signed_int(va_list *ap, t_spec *spec, char **sign)
{
	intmax_t	n;

	if (spec->size == 'j')
		n = va_arg(*ap, intmax_t);
	else if (spec->size == 'l' || spec->size == 'h')
		n = (spec->size == 'l') ? (intmax_t)va_arg(*ap, long)
								: (intmax_t)(short)va_arg(*ap, int);
	else if (spec->size == LL || spec->size == HH)
		n = (spec->size == LL) ? (intmax_t)va_arg(*ap, long long)
								: (intmax_t)(char)va_arg(*ap, int);
	else
		n = (spec->size == 'z') ? (intmax_t)va_arg(*ap, size_t)
								: (intmax_t)va_arg(*ap, int);
	if (n < 0)
	{
		EXITIF(!(*sign = ft_strdup("-")));
		return ((uintmax_t)(-n));
	}
	else if (check_flag(spec->flags, PLUS))
	{
		EXITIF(!(*sign = ft_strdup("+")));
	}
	else if (check_flag(spec->flags, SPACE))
		EXITIF(!(*sign = ft_strdup(" ")));
	return ((uintmax_t)n);
}

int				set_int_prec(t_spec *spec, char **s, uintmax_t n, char **sign)
{
	int			nlen;
	char		*i;

	nlen = ft_nlen(n, getbase(spec));
	EXITIF(!(*s = ft_strnew(ft_max(nlen, spec->prec))));
	if (check_flag(spec->flags, HASH) && n > 0)
	{
		if (spec->type == 'x')
		{
			EXITIF(!(*sign = ft_strdup("0x")));
		}
		else if (spec->type == 'X')
		{
			EXITIF(!(*sign = ft_strdup("0X")));
		}
		else if (spec->type == 'o' && nlen >= spec->prec)
			EXITIF(!(*sign = ft_strdup("0")));
	}
	i = *s;
	while (nlen < spec->prec)
	{
		*i++ = '0';
		nlen++;
	}
	return (1);
}

uintmax_t		get_unsigned_int(va_list *ap, t_spec *spec)
{
	if (spec->size == 'l')
		return ((uintmax_t)va_arg(*ap, unsigned long));
	else if (spec->size == LL)
		return ((uintmax_t)va_arg(*ap, unsigned long long));
	else if (spec->size == 'h')
		return ((uintmax_t)(unsigned short)va_arg(*ap, unsigned int));
	else if (spec->size == HH)
		return ((uintmax_t)(unsigned char)va_arg(*ap, unsigned int));
	else if (spec->size == 'z')
		return ((uintmax_t)va_arg(*ap, size_t));
	else if (spec->size == 'j')
		return (va_arg(*ap, uintmax_t));
	return ((uintmax_t)va_arg(*ap, unsigned int));
}

char			*getnum(va_list *ap, t_spec *spec, char **sign)
{
	uintmax_t	n;
	char		*res;
	char		*buf;

	if (spec->type == 'd' || spec->type == 'i')
		n = get_signed_int(ap, spec, sign);
	else
		n = get_unsigned_int(ap, spec);
	if (n == 0 && spec->prec == 0)
	{
		if (spec->type == 'o' && check_flag(spec->flags, HASH))
		{
			EXITIF(!(res = ft_strdup("0")));
		}
		else
			EXITIF(!(res = ft_strdup("")));
		return (res);
	}
	EXITIF(!(set_int_prec(spec, &res, n, sign)));
	EXITIF(!(buf = ft_itoabase(n, getbase(spec))));
	buf = (spec->type == 'X') ? ft_strupper(buf) : buf;
	EXITIF(!(res = ft_strmerge(2, &res, &buf)));
	return (res);
}
