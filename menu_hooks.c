/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:46:42 by jjacobso          #+#    #+#             */
/*   Updated: 2019/05/20 21:49:45 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		adjust(int *parameter, int change, int min, int max)
{
	if (*parameter + change <= min)
		*parameter = min;
	else if (*parameter + change >= max)
		*parameter = max;
	else
		*parameter += change;
}

void			color_re_set_hooks(t_view *view, int key, int x, int line)
{
	if (key == KEY_LMK && line == INTERPOLATION)
		OPTIONS.interpolation = OPTIONS.interpolation == 1 ? 0 : 1;
	else if (line == LIGHT_BRIGHTNESS && key == KEY_MOUSE_UP)
		adjust(&LAMP.light_brightness, -IO.wheel_speed, 0, 100);
	else if (line == LIGHT_BRIGHTNESS && key == KEY_MOUSE_DOWN)
		adjust(&LAMP.light_brightness, IO.wheel_speed, 0, 100);
	else if (line == BRIGHTNESS && key == KEY_MOUSE_UP)
		adjust(&PROPS.brightness, IO.wheel_speed, -100, 100);
	else if (line == BRIGHTNESS && key == KEY_MOUSE_DOWN)
		adjust(&PROPS.brightness, -IO.wheel_speed, -100, 100);
	else if (line == DARKNESS_BORDER && key == KEY_MOUSE_UP)
		adjust(&PROPS.darkness_border, -IO.wheel_speed, 0, 100);
	else if (line == DARKNESS_BORDER && key == KEY_MOUSE_DOWN)
		adjust(&PROPS.darkness_border, IO.wheel_speed, 0, 100);
	else if (line == L_COLOR)
		io_read_clr_prepare(view, x, LINE_CLR, PROPS.line_clr);
	else if (line == LAMP_POS)
		io_read_coord_prepare(view, x);
	set_line_color(view);
	apply_light(view);
}

void			menu_mouse_hook(t_view *view, int key, int x, int y)
{
	int			line;

	line = get_line_number(y, view->wh);
	if (line == BRIGHTNESS || line == L_COLOR || line == DARKNESS_BORDER ||
		line == LIGHT_BRIGHTNESS || line == INTERPOLATION || line == LAMP_POS)
		color_re_set_hooks(view, key, x, line);
	else if (key == KEY_LMK)
		menu_lmc_handle(view, x, line);
	else if (key == KEY_MOUSE_UP || key == KEY_MOUSE_DOWN)
		menu_wheel_handle(view, key, line);
}

void			menu_lmc_handle(t_view *view, int x, int line)
{
	if (line == LINE_TYPE)
		OPTIONS.line_mode = OPTIONS.line_mode == SMOOTH ? UGLY : SMOOTH;
	else if (line == USE_SHADER)
		OPTIONS.use_image = OPTIONS.use_image == 1 ? 0 : 1;
	else if (line == MENU_BG)
		OPTIONS.print_menu_bg = OPTIONS.print_menu_bg == 1 ? 0 : 1;
	else if (line == ROTATION_SENS)
		OPTIONS.rotation_global_sens =
			OPTIONS.rotation_global_sens == INT_SENS ? DOUBLE_SENS : INT_SENS;
	else if (line == DRAW_MODE)
		OPTIONS.priority_draw = OPTIONS.priority_draw == 1 ? 0 : 1;
	else if (line == RST)
		map_reset(view);
	else if (line == PROJ_TYPE)
		PROPS.projection_type = PROPS.projection_type == ISO ? CONIC : ISO;
	else if (line == PERSPECTIVE)
		OPTIONS.perspective = OPTIONS.perspective == 1 ? 0 : 1;
	else if (line == BACKGROUND)
		io_read_clr_prepare(view, x, BG_CLR, PROPS.bg_clr);
}

void			menu_wheel_handle(t_view *view, int key, int line)
{
	if (line == ROTATIO_SPEED && key == KEY_MOUSE_UP)
		adjust(&PROPS.rotation_speed, IO.wheel_speed, 0, 200);
	else if (line == ROTATIO_SPEED && key == KEY_MOUSE_DOWN)
		adjust(&PROPS.rotation_speed, -IO.wheel_speed, 0, 200);
	else if (line == Z_MOD && key == KEY_MOUSE_UP)
		adjust(&PROPS.z_modifier, IO.wheel_speed, 0, 200);
	else if (line == Z_MOD && key == KEY_MOUSE_DOWN)
		adjust(&PROPS.z_modifier, -IO.wheel_speed, 0, 200);
	else if (line == PERSP_MOD && key == KEY_MOUSE_UP)
		adjust(&PROPS.perspective_modifier, IO.wheel_speed, 0, 200);
	else if (line == PERSP_MOD && key == KEY_MOUSE_DOWN)
		adjust(&PROPS.perspective_modifier, -IO.wheel_speed, 0, 200);
	else if (line == WHEEL_SPEED && key == KEY_MOUSE_UP)
		adjust(&IO.wheel_speed, 1, 1, 10);
	else if (line == WHEEL_SPEED && key == KEY_MOUSE_DOWN)
		adjust(&IO.wheel_speed, -1, 1, 10);
}
