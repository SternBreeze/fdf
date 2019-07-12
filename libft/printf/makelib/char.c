/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:30:18 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/24 19:57:51 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			print_char(va_list *ap, t_spec *spec)
{
	wint_t			c;
	int				len;

	len = 1;
	while (spec->narg-- > 1)
		(void)va_arg(*ap, int);
	if (spec->type == '%')
		c = '%';
	else if (spec->size == 'l')
	{
		c = va_arg(*ap, wint_t);
		len = ft_wcharlen(c);
	}
	else
		c = (wint_t)va_arg(*ap, int);
	if (check_flag(spec->flags, MINUS))
		(void)(((spec->size == 'l') ? (ft_putwchar(c)) : (ft_putchar(c)))
										+ padding(&len, spec, ' '));
	else if (check_flag(spec->flags, ZERO))
		(void)(padding(&len, spec, '0') +
				((spec->size == 'l') ? (ft_putwchar(c)) : (ft_putchar(c))));
	else
		(void)(padding(&len, spec, ' ') +
				((spec->size == 'l') ? (ft_putwchar(c)) : (ft_putchar(c))));
	return (len);
}

int			wchar_spec(wchar_t *s, int spec)
{
	int				len;

	len = 0;
	while (*s)
	{
		len += ft_wcharlen(*s);
		if (spec < len)
		{
			len -= ft_wcharlen(*s);
			break ;
		}
		s++;
	}
	return (len);
}

int			print_wstring(wchar_t *s, t_spec *spec)
{
	int				len;

	if (spec->prec < (int)ft_strwlen(s) && spec->prec != -1)
		len = wchar_spec(s, spec->prec);
	else if (s || (!s && spec->prec == 0))
		len = ft_strwlen(s);
	else
		len = ft_strlen("(null)");
	if (check_flag(spec->flags, MINUS))
	{
		(!s) ? (ft_putnstr("(null)", spec->prec))
												: (ft_putnwstr(s, spec->prec));
		padding(&len, spec, ' ');
	}
	else
	{
		padding(&len, spec, (check_flag(spec->flags, ZERO)) ? ('0') : (' '));
		(!s) ? (ft_putnstr("(null)", spec->prec))
												: (ft_putnwstr(s, spec->prec));
	}
	return (len);
}

int			print_string(va_list *ap, t_spec *spec)
{
	char			*s;
	int				len;

	while (spec->narg-- > 1)
		(void)va_arg(*ap, int);
	if (spec->size == 'l')
		return (print_wstring(va_arg(*ap, wchar_t *), spec));
	else
		s = va_arg(*ap, char *);
	if (spec->prec < (int)ft_strlen(s) && spec->prec != -1)
		len = spec->prec;
	else if (s || (!s && spec->prec == 0))
		len = ft_strlen(s);
	else
		len = ft_strlen("(null)");
	if (check_flag(spec->flags, MINUS))
		(void)(((!s) ? (ft_putnstr("(null)", spec->prec))
												: (ft_putnstr(s, spec->prec)))
		+ padding(&len, spec, ' '));
	else
		(void)(padding(&len, spec, check_flag(spec->flags, ZERO) ? '0' : ' ')
		+ ((!s) ? (ft_putnstr("(null)", spec->prec))
												: (ft_putnstr(s, spec->prec))));
	return (len);
}

int			padding(int *len, t_spec *spec, char c)
{
	while (*len < spec->width)
		*len += ft_putchar(c);
	return (*len);
}
