/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 10:54:55 by jjacobso          #+#    #+#             */
/*   Updated: 2019/01/27 16:30:51 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"
# include "colors.h"
# include <float.h>
# include <wchar.h>
# include <stdint.h>
# include <math.h>

# define FLAGS			"#0-+ b"
# define TYPES			"cCsSpdDioOuUxXfFeEgG"
# define SIZES			"lhLzj"
# define EXITIF(x)		if (x) return (0)
# define ISFLAG(x)		ft_strchr(FLAGS, x) != NULL
# define ISTYPE(x)		ft_strchr(TYPES, x) != NULL
# define ISSIZE(x)		ft_strchr(SIZES, x) != NULL
# define ISWIDTH(x)		ft_isdigit(x) || x == '*'
# define ISPREC(x)		x == '.'
# define LL				1
# define HH				2
# define HASH			(1 << 0)
# define ZERO			(1 << 1)
# define MINUS			(1 << 2)
# define PLUS			(1 << 3)
# define SPACE			(1 << 4)
# define BIN			(1 << 5)

typedef struct			s_spec
{
	char				prec;
	int					flags;
	int					narg;
	int					width;
	char				size;
	char				type;
	int					mod;
}						t_spec;

/*
** 						printf.c
*/
int						ft_printf(const char *fmt, ...);
int						get_spec(va_list *ap, t_spec *spec, const char **fmt);
int						print_arg
						(va_list *ap, t_spec *spec, const char **fmt, int *len);
void					print_defective_spec
						(const char **fmt, t_spec *spec, int *len);
/*
** 						spec.c
*/
int						get_narg(const char **fmt, t_spec *spec);
void					spec_clear(t_spec *spec);
int						get_width(va_list *ap, const char **fmt, t_spec *spec);
int						get_prec(va_list *ap, const char **fmt, t_spec *spec);
int						get_size(const char **fmt, t_spec *spec);
/*
** 						flags.c
*/
int						check_flag(char flags, char flag);

void					set_flag(t_spec *spec, char c);
char					char_to_flag(char c);
int						check_narg(const char *str);
/*
** 						int.c
*/
int						getbase(t_spec *spec);
uintmax_t				get_signed_int(va_list *ap, t_spec *spec, char **sign);
uintmax_t				get_unsigned_int(va_list *ap, t_spec *spec);
int						set_int_prec
						(t_spec *spec, char **s, uintmax_t n, char **sign);
char					*getnum(va_list *ap, t_spec *spec, char **sign);
/*
** 						print_int.c
*/
int						print_sign(char *sign);
void					ptr_body_print(t_spec *spec, int ptrlen, char *s);
int						print_pointer(va_list *ap, t_spec *spec);
int						print_number(va_list *ap, t_spec *spec);
/*
** 						char.c
*/
int						print_char(va_list *ap, t_spec *spec);
int						wchar_spec(wchar_t *s, int spec);
int						print_wstring(wchar_t *s, t_spec *spec);
int						print_string(va_list *ap, t_spec *spec);
int						padding(int *len, t_spec *spec, char c);
/*
** 						float.c
*/
void					setexp(char **str, int prec, int e);
char					*get_expg_type(long double f, t_spec *spec, int prec);
char					*get_g_type(long double f, t_spec *spec, int prec,
						int exp);
char					*float_to_string(long double f, t_spec *spec, int prec);
char					*getdouble(va_list *ap, t_spec *spec, char **sign);
/*
**						float_adjust.c
*/
void					cut(char *str, int dot);
void					pound(char *s, int prec);
void					super_hard_adjust(char **s, t_spec *spec, int prec,
						int mod);
int						hard_adjust(char **str, char *s, int mod);
int						fadjust(char **str, int mod);
/*
** 						float2.c
*/
int						sign_num(char *s);
int						get_adjusted_exp(long double f, t_spec *spec, int prec);
long double				get_exp(long double f, int *exp);
char					*set_int_part(long double *f, char *s, int intlen);
char					*ft_ftoa(long double *f, int prec, int dot);
#endif
