/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 19:02:24 by jjacobso          #+#    #+#             */
/*   Updated: 2019/04/22 19:11:59 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			menu_line_with_coord(t_view *view, int line, char *s, t_coord c)
{
	char		*w;
	char		*b;

	b = 0;
	w = coord_to_line(c);
	s = ft_strjoin(s,
				b = nspaces((MENU.w / 10 - (ft_strlen(s) + ft_strlen(w) + 2))));
	mlx_string_put(view->id, view->win, view->ww - MENU.w + 15,
									17 * (line * 2) + 5, rgb(255, 145, 0), s);
	mlx_string_put(view->id, view->win, view->ww - MENU.w + 15
								+ 10 * ft_strlen(s),
								17 * (line * 2) + 5, rgb(255, 145, 0), w);
	ft_memdel((void **)&w);
	ft_memdel((void **)&b);
	ft_memdel((void **)&s);
}

void			menu_line_with_clr(t_view *view, int line, char *s, int clr)
{
	char		*w;
	char		*b;

	b = 0;
	w = clr_to_line(clr);
	s = ft_strjoin(s,
					b = nspaces((MENU.w / 10
					- (ft_strlen(s) + ft_strlen(w) + 2 + ft_strlen("rgb")))));
	mlx_string_put(view->id, view->win, view->ww - MENU.w + 15,
									17 * (line * 2) + 5, rgb(255, 145, 0), s);
	rgb_print(view, line, clr, s);
	mlx_string_put(view->id, view->win, view->ww - MENU.w + 15
								+ 10 * (ft_strlen(s) + ft_strlen("rgb")),
								17 * (line * 2) + 5, rgb(255, 145, 0), w);
	ft_memdel((void **)&w);
	ft_memdel((void **)&b);
	ft_memdel((void **)&s);
}

void			menu_line_with_num(t_view *view, int line, char *s, int num)
{
	char		*b;
	char		*b1;

	b = 0;
	b1 = 0;
	s = ft_strjoin(s,
									b = nspaces((MENU.w / 10
									- (ft_strlen(s) + ft_nlen(num, 10) + 2))));
	ft_memdel((void**)&b);
	mlx_string_put(view->id, view->win, view->ww - MENU.w + 15,
									17 * (line * 2) + 5, rgb(255, 145, 0),
									(b = ft_strjoin(s,
									(b1 = ft_itoa(num)))));
	ft_memdel((void**)&b);
	ft_memdel((void**)&b1);
	ft_memdel((void**)&s);
}

void			menu_line_with_num_and_procent(t_view *view, int line, char *s,
																		int num)
{
	char		*b;
	char		*b1;

	b = 0;
	b1 = 0;
	s = ft_strjoin(s,
									b = nspaces((MENU.w / 10
									- (ft_strlen(s) + ft_nlen(num, 10) + 3))));
	ft_memdel((void**)&b);
	mlx_string_put(view->id, view->win, view->ww - MENU.w + 15,
									17 * (line * 2) + 5, rgb(255, 145, 0),
									(b = ft_strjoin(s,
									(b1 = ft_itoa(num)))));
	mlx_string_put(view->id, view->win, view->ww - MENU.w + 15
			+ ft_strlen(b) * 10, 17 * (line * 2) + 5, rgb(255, 145, 0), "%");
	ft_memdel((void**)&b);
	ft_memdel((void**)&b1);
	ft_memdel((void**)&s);
}
