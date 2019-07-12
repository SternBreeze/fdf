/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:48:19 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/27 19:07:25 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int						print_sign(char *sign)
{
	if (sign)
		ft_putstr(sign);
	return (1);
}

void					ptr_body_print(t_spec *spec, int ptrlen, char *s)
{
	ft_putstr("0x");
	if (spec->prec != -1 && ptrlen < spec->prec)
		ft_putnchar('0', spec->prec - ptrlen);
	ft_putnstr(s, ptrlen);
}

int						print_pointer(va_list *ap, t_spec *spec)
{
	char				*s;
	size_t				ptr;
	int					len;
	int					ptrlen;

	while (spec->narg-- > 1)
		(void)va_arg(*ap, int);
	ptr = va_arg(*ap, size_t);
	s = ft_itoabase(ptr, 16);
	ptrlen = (ptr == 0 && spec->prec == 0) ? 0 : ft_strlen(s);
	if (check_flag(spec->flags, ZERO) && ptrlen < spec->width)
		spec->prec = ft_max(spec->width - 2, spec->prec);
	len = ft_max(ptrlen, spec->prec) + 2;
	if (check_flag(spec->flags, MINUS))
	{
		ptr_body_print(spec, ptrlen, s);
		padding(&len, spec, ' ');
	}
	else
	{
		padding(&len, spec, ' ');
		ptr_body_print(spec, ptrlen, s);
	}
	ft_memdel((void **)&s);
	return (len);
}

int						print_number(va_list *ap, t_spec *spec)
{
	char				*n;
	int					len;
	char				*sign;

	sign = NULL;
	while (spec->narg-- > 1)
		(void)va_arg(*ap, int);
	ft_strchr("fFeEgG", spec->type) ? (n = getdouble(ap, spec, &sign)) :
									(n = getnum(ap, spec, &sign));
	EXITIF(!n);
	len = ft_strlen(n) + ft_strlen(sign);
	if (check_flag(spec->flags, MINUS))
		(void)(print_sign(sign) + ft_putstr(n) + padding(&len, spec, ' '));
	else if (check_flag(spec->flags, ZERO) && spec->prec == -1)
		(void)(print_sign(sign) + padding(&len, spec, '0') + ft_putstr(n));
	else
		(void)(padding(&len, spec, ' ') + print_sign(sign) + ft_putstr(n));
	ft_nfree(2, &sign, &n);
	return (len);
}
