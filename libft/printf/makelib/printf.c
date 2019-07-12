/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 10:51:15 by jjacobso          #+#    #+#             */
/*   Updated: 2019/04/04 18:32:04 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			print_defective_spec(const char **fmt, t_spec *spec, int *len)
{
	int			l;

	l = 1;
	if (check_flag(spec->flags, MINUS))
	{
		ft_putchar(**fmt);
		padding(&l, spec, (check_flag(spec->flags, ZERO)) ? ('0') : (' '));
	}
	else
	{
		padding(&l, spec, (check_flag(spec->flags, ZERO)) ? ('0') : (' '));
		ft_putchar(**fmt);
	}
	++*fmt;
	*len += l;
}

int				get_spec(va_list *ap, t_spec *spec, const char **fmt)
{
	while (**fmt)
		if (spec->narg && **fmt == '%')
			return (0);
		else if (ISFLAG(**fmt))
			(!check_flag(spec->flags, char_to_flag(**fmt))) ?
					(set_flag(spec, *(*fmt)++)) : ((void)(++*fmt));
		else if (ISWIDTH(**fmt) || check_narg(*fmt))
			(check_narg(*fmt)) ? get_narg(fmt, spec) : get_width(ap, fmt, spec);
		else if (ISPREC(**fmt))
			get_prec(ap, fmt, spec);
		else if (ISSIZE(**fmt))
			(**fmt > spec->size) ? (get_size(fmt, spec)) : ((void)(++*fmt));
		else if (ISTYPE(**fmt) || (**fmt == '%'))
		{
			spec->type = ft_strchr("CSDOU", **fmt) ? ft_tolower(**fmt) : **fmt;
			spec->size = ft_strchr("CSDOU", **fmt) ? 'l' : spec->size;
			++*fmt;
			return (1);
		}
		else
			return (0);
	return (0);
}

int				print_arg(va_list *ap, t_spec *spec, const char **fmt, int *len)
{
	if (get_spec(ap, spec, fmt))
	{
		if (spec->mod == 0 && spec->narg)
			spec->mod = 1;
		else if (spec->mod == 0)
			spec->mod = -1;
		else if (spec->narg && **fmt == '%')
			EXITIF(spec->narg <= 0 && spec->mod == 1);
		if (spec->type == 'c' || spec->type == '%')
			*len += print_char(ap, spec);
		else if (spec->type == 's')
			*len += print_string(ap, spec);
		else if (spec->type == 'p')
			*len += print_pointer(ap, spec);
		else if (ft_strchr("dDioOuUxXfFeEgG", spec->type))
			*len += print_number(ap, spec);
	}
	else if (spec->width)
		print_defective_spec(fmt, spec, len);
	return (1);
}

int				ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			len;
	t_spec		spec;

	EXITIF(!fmt);
	len = 0;
	spec.mod = 0;
	va_start(ap, fmt);
	while (*fmt)
		if (*fmt != '%')
			len += ft_putchar(*fmt++);
		else if (*fmt == '%')
		{
			++fmt;
			if (spec.mod == 1)
			{
				va_end(ap);
				va_start(ap, fmt);
			}
			spec_clear(&spec);
			EXITIF(!print_arg(&ap, &spec, &fmt, &len));
		}
	va_end(ap);
	return (len);
}
