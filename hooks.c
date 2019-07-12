/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:30:00 by jjacobso          #+#    #+#             */
/*   Updated: 2019/05/22 15:43:35 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_press_hook(int key, t_view *view)
{
	if (key == KEY_ESC)
	{
		close_program(view);
		exit(0);
	}
	else if (io_is_reading(view))
		io_read(view, key);
	else if (key == KEY_R)
		map_reset(view);
	else if (key == KEY_M)
	{
		if (IMAGE.w < 400)
			return (ft_printf("Cannot open menu\n"));
		OPTIONS.open_menu = OPTIONS.open_menu == 0 ? 1 : 0;
		if (OPTIONS.open_menu)
		{
			print_menu(view);
			print_info(view);
		}
		else
			print_map(view);
	}
	return (1);
}

int			mouse_release_hook(int key, int x, int y, t_view *view)
{
	(void)x;
	(void)y;
	if (key == KEY_LMK && !MOUSE.rmk_pressed)
	{
		MOUSE.lmk_pressed = 0;
		MOUSE.x = 0;
		MOUSE.y = 0;
		MAP.last_offset.x = MAP.offset.x;
		MAP.last_offset.y = MAP.offset.y;
	}
	else if (key == KEY_RMK && !MOUSE.lmk_pressed)
	{
		MOUSE.rmk_pressed = 0;
		MOUSE.x = 0;
		MOUSE.y = 0;
	}
	return (1);
}

int			mouse_press_hook(int key, int x, int y, t_view *view)
{
	if (io_is_reading(view))
		IO.read_err = WRONG_INPUT;
	else if (OPTIONS.open_menu && ft_inrange(x, view->ww - MENU.w, view->ww))
		menu_mouse_hook(view, key, x, y);
	else if (key == KEY_LMK && !MOUSE.rmk_pressed)
	{
		MOUSE.x = x;
		MOUSE.y = y;
		MOUSE.lmk_pressed = 1;
	}
	else if (key == KEY_RMK && !MOUSE.lmk_pressed)
	{
		MOUSE.rmk_pressed = 1;
		MOUSE.x = x;
		MOUSE.y = y;
	}
	else if (key == KEY_MOUSE_UP || key == KEY_MOUSE_DOWN)
		scale_adjust(view, key);
	project(view);
	print_map(view);
	return (1);
}

int			motion_hook(int x, int y, t_view *view)
{
	if (MOUSE.lmk_pressed)
	{
		MAP.offset.x = MAP.last_offset.x + (x - MOUSE.x);
		MAP.offset.y = MAP.last_offset.y + (y - MOUSE.y);
		project(view);
		print_map(view);
	}
	else if (MOUSE.rmk_pressed)
	{
		set_angles(view, x, y);
		lock_angle(&PROPS.beta, -360, 360);
		lock_angle(&PROPS.alpha, -360, 360);
		project(view);
		print_map(view);
	}
	return (1);
}

int			exit_hook(t_view *view)
{
	ft_printf(CYN"\nBye Bye\n"RESET);
	close_program(view);
	exit(0);
}
