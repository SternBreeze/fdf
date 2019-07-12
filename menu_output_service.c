/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_output_service.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 19:05:09 by jjacobso          #+#    #+#             */
/*   Updated: 2019/04/22 19:23:48 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char			*nspaces(int n)
{
	char		*s;

	if (n < 0)
		error("Window too small to open menu");
	if (!(s = ft_strnew(n)))
		error("Malloc error");
	while (--n >= 0)
		s[n] = ' ';
	return (s);
}

char			*clr_to_line(int clr)
{
	char		*s;
	char		*w;
	int			r;
	int			g;
	int			b;

	r = (clr & 0xFF0000) >> 16;
	g = (clr & 0xFF00) >> 8;
	b = (clr & 0xFF);
	if (!(s = ft_strnew(ft_nlen(r, 10) + ft_nlen(g, 10) + ft_nlen(b, 10)
													+ ft_strlen("( , , )"))))
		error("Malloc error");
	s = ft_strcat(s, "(");
	s = ft_strcat(s,
		(w = ft_itoa(r)));
	ft_memdel((void **)&w);
	s = ft_strcat(s, ", ");
	s = ft_strcat(s,
		(w = ft_itoa(g)));
	ft_memdel((void **)&w);
	s = ft_strcat(s, ", ");
	s = ft_strcat(s,
		(w = ft_itoa(b)));
	ft_memdel((void **)&w);
	return ((s = ft_strcat(s, ")")));
}

char			*coord_to_line(t_coord c)
{
	char		*s;
	char		*w;

	if (!(s = ft_strnew(ft_nlen(c.x, 10) + ft_nlen(c.y, 10) + ft_nlen(c.z, 10)
													+ ft_strlen("( , , )"))))
		error("Malloc error");
	s = ft_strcat(s, "(");
	s = ft_strcat(s,
		(w = ft_itoa(c.x)));
	ft_memdel((void **)&w);
	s = ft_strcat(s, ", ");
	s = ft_strcat(s,
		(w = ft_itoa(c.y)));
	ft_memdel((void **)&w);
	s = ft_strcat(s, ", ");
	s = ft_strcat(s,
		(w = ft_itoa(c.z)));
	ft_memdel((void **)&w);
	s = ft_strcat(s, ")");
	return (s);
}

void			rgb_print(t_view *view, int line, int clr, char *s)
{
	if (OPTIONS.print_menu_bg)
	{
		mlx_string_put(view->id, view->win, view->ww - MENU.w + 15
								+ 10 * (ft_strlen(s)),
								17 * (line * 2) + 5, clr & 0xFF0000, "r");
		mlx_string_put(view->id, view->win, view->ww - MENU.w + 15
								+ 10 * (ft_strlen(s)) + 10,
								17 * (line * 2) + 5, clr & 0xFF00, "g");
		mlx_string_put(view->id, view->win, view->ww - MENU.w + 15
								+ 10 * (ft_strlen(s)) + 20,
								17 * (line * 2) + 5, clr & 0xFF, "b");
	}
	else
		mlx_string_put(view->id, view->win, view->ww - MENU.w + 15
								+ 10 * (ft_strlen(s)),
								17 * (line * 2) + 5, rgb(255, 145, 0), "rgb");
}
