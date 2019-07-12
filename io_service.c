/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_service.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:54:39 by jjacobso          #+#    #+#             */
/*   Updated: 2019/05/16 20:14:14 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				io_is_reading(t_view *view)
{
	return (IO.read_mode > 0);
}

void			io_set_coord(t_view *view)
{
	if (IO.to_read == 'x')
		LAMP.dot.x = IO.input;
	else if (IO.to_read == 'y')
		LAMP.dot.y = IO.input;
	else if (IO.to_read == 'z')
		LAMP.dot.z = IO.input;
	set_line_color(view);
	apply_light(view);
}

int				io_read_clr(t_view *view, int key)
{
	if (!ft_inrange(IO.input, 0, 255))
	{
		IO.read_err = WRONG_NUM;
		set_clr(view);
		print_map(view);
		IO.read_err = 0;
		IO.input = 0;
		IO.read_mode = 0;
		return (-1);
	}
	if (ft_nlen(IO.input, 10) == 3 || key == KEY_ENTER)
	{
		IO.read_err = 0;
		set_clr(view);
		print_map(view);
		IO.read_mode = 0;
		IO.input = 0;
		return (1);
	}
	set_clr(view);
	print_map(view);
	return (0);
}

int				io_read_coord(t_view *view, int key)
{
	if (!ft_inrange(IO.input, 0, 10000))
	{
		IO.read_err = WRONG_NUM;
		LAMP.dot = IO.saved_coord;
		print_map(view);
		IO.read_err = 0;
		IO.input = 0;
		IO.read_mode = 0;
		return (-1);
	}
	if (ft_nlen(IO.input, 10) == 5 || key == KEY_ENTER)
	{
		IO.read_err = 0;
		io_set_coord(view);
		project(view);
		print_map(view);
		IO.read_mode = 0;
		IO.input = 0;
		return (1);
	}
	io_set_coord(view);
	project(view);
	print_map(view);
	return (0);
}
