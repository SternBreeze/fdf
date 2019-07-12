/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:40:38 by jjacobso          #+#    #+#             */
/*   Updated: 2019/05/16 20:13:48 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		read_num(int key, int *num)
{
	if (key == KEY_0)
		*num = *num * 10;
	else if (key == KEY_1)
		*num = *num * 10 + 1;
	else if (key == KEY_2)
		*num = *num * 10 + 2;
	else if (key == KEY_3)
		*num = *num * 10 + 3;
	else if (key == KEY_4)
		*num = *num * 10 + 4;
	else if (key == KEY_5)
		*num = *num * 10 + 5;
	else if (key == KEY_6)
		*num = *num * 10 + 6;
	else if (key == KEY_7)
		*num = *num * 10 + 7;
	else if (key == KEY_8)
		*num = *num * 10 + 8;
	else if (key == KEY_9)
		*num = *num * 10 + 9;
	else
		return (0);
	return (1);
}

int				io_read(t_view *view, int key)
{
	if (!read_num(key, &IO.input) && key != KEY_ENTER)
	{
		IO.read_err = WRONG_INPUT;
		print_map(view);
		IO.read_err = 0;
		return (0);
	}
	if (IO.read_mode == BG_CLR || IO.read_mode == LINE_CLR)
		io_read_clr(view, key);
	else if (IO.read_mode == LAMP_COORD)
	{
		io_read_coord(view, key);
	}
	return (1);
}

int				io_read_clr_prepare(t_view *view, int x, int clr_type, int clr)
{
	int	r;
	int	g;
	int	b;

	r = (clr & 0xFF0000) >> 16;
	g = (clr & 0xFF00) >> 8;
	b = (clr & 0xFF);
	b = ft_nlen(b, 10);
	g = ft_nlen(g, 10);
	r = ft_nlen(r, 10);
	IO.read_mode = clr_type;
	IO.saved_clr = clr;
	if (ft_inrange(x, view->ww - 10 * b - 15, view->ww - 15))
		IO.to_read = 'b';
	else if (ft_inrange(x,
						view->ww - 10 * (b + g + ft_strlen(", ")) - 15,
						view->ww - 10 * (b + ft_strlen(", ")) - 15))
		IO.to_read = 'g';
	else if (ft_inrange(x,
						view->ww - 10 * (r + b + g + 2 * ft_strlen(", ")) - 15,
						view->ww - 10 * (b + g + 2 * ft_strlen(", ")) - 15))
		IO.to_read = 'r';
	else
		IO.read_mode = 0;
	return (1);
}

int				io_read_coord_prepare(t_view *view, int x)
{
	int	r;
	int	g;
	int	b;

	r = ft_nlen(LAMP.dot.x, 10);
	g = ft_nlen(LAMP.dot.y, 10);
	b = ft_nlen(LAMP.dot.z, 10);
	IO.read_mode = LAMP_COORD;
	IO.saved_coord = LAMP.dot;
	if (ft_inrange(x, view->ww - 10 * b - 15, view->ww - 15))
		IO.to_read = 'z';
	else if (ft_inrange(x,
						view->ww - 10 * (b + g + ft_strlen(", ")) - 15,
						view->ww - 10 * (b + ft_strlen(", ")) - 15))
		IO.to_read = 'y';
	else if (ft_inrange(x,
						view->ww - 10 * (r + b + g + 2 * ft_strlen(", ")) - 15,
						view->ww - 10 * (b + g + 2 * ft_strlen(", ")) - 15))
		IO.to_read = 'x';
	else
		IO.read_mode = 0;
	return (1);
}
