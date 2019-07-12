/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 20:54:24 by jjacobso          #+#    #+#             */
/*   Updated: 2019/04/23 17:05:08 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>
# include <math.h>
# include "list.h"
# include "get_next_line.h"
# include "stack.h"
# include "queue.h"
# include "ft_math.h"
# include "../printf/printf.h"

# define SIGN(x)	((x > 0) ? 1 : -1)

/*
**					libft/math/
*/
int					ft_finrange(double x, double s, double e);
long double			fpart(long double x);
int					ft_range(int x, int y);
float				ft_frange(float x, float y);
int					ft_inrange(int x, int s, int e);
int					ft_mid(int a, int b, int c);
size_t				ft_digs(int i);
long double			ft_fpow(long double base, long double ex);
int					ft_fdiv(long double f, int len);
int					ft_nlen(intmax_t n, int base);
int					ft_flen(long double f);
long double			ft_fabs(long double f);
int					ft_max(int a, int b);
int					ft_min(int a, int b);
int					ft_min3(int a, int b, int c);
int					ft_sqrt(int n);
unsigned long long	ft_pow(int a, int b);
/*
** 					libft/mem/
*/
void				*ft_intset(void *dest, int c, size_t len);
int					**ft_mas(int x, int y, int c);
void				*ft_int_get_mass(int m);
int					ft_nfree(int n, ...);
int					ft_free_content(char **m);
int					ft_freemas(char ***mas, int ret);
void				ft_clear_int(int *mas, int size);
int					ft_int_free(void **b, int ret);
void				*ft_malloc(size_t size);
int					ft_free(void *ptr);
void				*ft_frealloc(void *ptr, size_t size, size_t newsize);
void				*ft_realloc(void *ptr, size_t size);
char				*ft_ptr_free(void **b);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t len);
void				*ft_memchr(const void *src, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t len);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *dest, int c, size_t len);

/*
** 					libft/print/
*/
int					ft_putnwstr(wchar_t *s, int n);
int					ft_putnchar(char c, int n);
int					ft_putnstr(char const *s, int n);
int					ft_putchar(char c);
int					ft_putwchar(wchar_t c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
int					ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
/*
**					libft/str
*/
int					ft_atoibase(char *s, int mbase);
int					ft_isnum(char *s);
size_t				ft_words(char **s);
int					ft_strwlen(wchar_t *s);
char				*ft_strnchr(const char *src, int c, int n);
char				*ft_strmerge(int num, ...);
char				*ft_strnbrcat(char *str, int n);
int					ft_wcharlen(wchar_t c);
char				*ft_ftoa(long double *f, int prec, int dot);
char				*ft_itoabase(uintmax_t num, int mbase);
char				ft_strsearch(const char *src, const char *needles);
char				*ft_strnfjoin(char **str1, char const *str2, int len);
char				*ft_strndup(const char *src, int len);
size_t				ft_strlento(const char *s, char c);
char				*ft_strfjoin(char **str1, const char *str2);
intmax_t			ft_atoi(const char *str);
void				ft_bzero(void *s, size_t len);
int					ft_isspace(char c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
char				*ft_strcat(char *str1, const char *str2);
char				*ft_strchr(const char *src, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *src);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f) (char *));
void				ft_striteri(char *s, void (*f) (unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t len);
size_t				ft_strlen(const char *str);
char				*ft_strmap(char const *s, char (*f) (char));
char				*ft_strmapi(char const *s, char (*f) (unsigned int, char));
char				*ft_strncat(char *str1, const char *str2, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *stack,
					const char *needle, size_t len);
char				*ft_strrchr(const char *src, int c);
char				**ft_strsplit(char const *src, char c);
char				*ft_strstr(const char *stack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *src);
char				ft_tolower(char c);
char				ft_toupper(char c);
char				*ft_strupper(char *s);
char				*ft_strlower(char *s);
/*
**					libft/vec
*/
void				unit_vec3(double v[3], double x, double y, double z);
#endif
