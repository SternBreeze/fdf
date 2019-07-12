/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:44:25 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/24 19:21:52 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			spec_clear(t_spec *spec)
{
	ft_bzero(spec, sizeof(t_spec) - sizeof(spec->mod));
	spec->prec = -1;
}

int				get_narg(const char **fmt, t_spec *spec)
{
	const char	*str;
	int			len;

	str = *fmt;
	len = 0;
	if (*str > '0' && *str <= '9')
	{
		while (str[len] != '$')
		{
			spec->narg += (str[len] - '0') + spec->narg * 10;
			len++;
		}
		EXITIF(len == 0);
		len++;
	}
	*fmt += len;
	return (1);
}

int				get_width(va_list *ap, const char **fmt, t_spec *spec)
{
	const char	*str;
	int			len;
	int			width;

	width = 0;
	len = 0;
	str = *fmt;
	if (*str == '*')
	{
		width = va_arg(*ap, int);
		if (width < 0)
			set_flag(spec, '-');
		len++;
		spec->width = ABS(width);
	}
	else
	{
		while (ft_isdigit(str[len]))
			width = width * 10 + str[len++] - '0';
		spec->width = width;
	}
	*fmt += len;
	return (1);
}

int				get_prec(va_list *ap, const char **fmt, t_spec *spec)
{
	const char	*str;
	int			len;
	int			prec;

	(*fmt)++;
	len = 0;
	str = *fmt;
	prec = 0;
	if (*str == '*')
	{
		prec = va_arg(*ap, int);
		if (prec < 0)
			prec = -1;
		len++;
	}
	else if (ft_isdigit(*str))
		while (ft_isdigit(str[len]))
			prec = prec * 10 + str[len++] - '0';
	spec->prec = prec;
	*fmt += len;
	return (1);
}

int				get_size(const char **fmt, t_spec *spec)
{
	const char	*str;

	str = *fmt;
	if (ft_strnstr(str, "ll", 2))
	{
		spec->size = LL;
		*fmt += 2;
	}
	else if (ft_strnstr(str, "hh", 2))
	{
		spec->size = HH;
		*fmt += 2;
	}
	else if (ISSIZE(*str))
	{
		spec->size = *str;
		++*fmt;
	}
	return (1);
}
