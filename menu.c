/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 20:03:59 by jjacobso          #+#    #+#             */
/*   Updated: 2019/05/21 16:18:49 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			print_bg(t_view *view, int bg_clr, int clr)
{
	int				i;
	int				offset;

	if (!OPTIONS.use_image)
		offset = view->ww - MENU.w;
	else
		offset = 0;
	print_line(view, COORD(offset, 0, 0, 0, clr),
			COORD(offset, MENU.h, 0, 0, clr));
	print_line(view, COORD(MENU.w - 1 + offset, 0, 0, 0, clr),
			COORD(MENU.w - 1 + offset, MENU.h, 0, 0, clr));
	i = 1;
	while (++i < MENU.w)
		print_line(view, COORD(MENU.w - i + offset, 0, 0, 0, bg_clr),
			COORD(MENU.w - i + offset, MENU.h, 0, 0, bg_clr));
	print_line(view, COORD(offset, MENU.h - 1, 0, 0, clr),
			COORD(MENU.w - 1 + offset, MENU.h - 1, 0, 0, clr));
	print_line(view, COORD(offset, 1, 0, 0, clr),
			COORD(MENU.w + offset, 1, 0, 0, clr));
	i = 0;
	while (++i < 30)
		print_line(view, COORD(offset, 34 * i, 0, 0, clr),
			COORD(MENU.w + offset, 34 * i, 0, 0, clr));
}

static void			menu_line(t_view *view, int line, char *s, char *w)
{
	char			*b;
	char			*b1;

	b = 0;
	b1 = 0;
	s = ft_strjoin(s,
				b = nspaces((MENU.w / 10 - (ft_strlen(s) + ft_strlen(w) + 2))));
	ft_memdel((void**)&b);
	mlx_string_put(view->id, view->win, view->ww - MENU.w + 15,
										17 * (line * 2) + 5, rgb(255, 145, 0),
										(b = ft_strjoin(s, w)));
	ft_memdel((void**)&b);
	ft_memdel((void**)&b1);
	ft_memdel((void**)&s);
}

static void			print_nums(t_view *view)
{
	menu_line_with_num_and_procent(view, ROTATIO_SPEED,
						"Rotation speed:", PROPS.rotation_speed);
	menu_line_with_num(view, PITCH, "Pitch:", (int)(PROPS.alpha * 180 / M_PI));
	menu_line_with_num(view, YAW, "Yaw:", (int)(PROPS.beta * 180 / M_PI));
	menu_line_with_num_and_procent(view, Z_MOD,
						"Global z coordinate modifier:", PROPS.z_modifier);
	menu_line_with_num_and_procent(view, SCALE,
						"Scale:", (int)(PROPS.fscale * 100 + 0.5));
	menu_line_with_num_and_procent(view, BRIGHTNESS,
						"Brightness of line:", (int)(PROPS.brightness + 100));
	menu_line_with_num_and_procent(view, LIGHT_BRIGHTNESS,
						"Brightness of light:", 100 - LAMP.light_brightness);
	menu_line_with_num_and_procent(view, DARKNESS_BORDER, "Darkness border:",
						PROPS.darkness_border);
	menu_line_with_num(view, WHEEL_SPEED,
						"Mouse wheel speed modifier:", IO.wheel_speed);
	menu_line_with_num(view, PERSP_MOD,
						"Perspective modifier:", PROPS.perspective_modifier);
	menu_line_with_clr(view, BACKGROUND, "Background color:", PROPS.bg_clr);
	menu_line_with_clr(view, L_COLOR, "Line color:", PROPS.line_clr);
	menu_line_with_coord(view, LAMP_POS, "Lamp coordinates:", LAMP.dot);
}

static void			print_switches(t_view *view)
{
	menu_line(view, LINE_TYPE, "Line type:",
		OPTIONS.line_mode == SMOOTH ? "smooth Wu's line" : "Wu's line");
	menu_line(view, USE_SHADER, "Draw mode:",
		OPTIONS.use_image ? "use image shader" : "dont use image shader");
	menu_line(view, MENU_BG, "Print menu background:",
		OPTIONS.print_menu_bg ? "yes" : "no");
	menu_line(view, ROTATION_SENS, "Rotation sensitivity:",
		OPTIONS.rotation_global_sens == DOUBLE_SENS ? "high" : "low");
	menu_line(view, PROJ_TYPE, "Projection:",
		PROPS.projection_type == CONIC ? "conic" : "plane");
	menu_line(view, PERSPECTIVE, "Perspective:",
		OPTIONS.perspective || PROPS.projection_type == CONIC ? "on" : "off");
	menu_line(view, DRAW_MODE, "Priority draw:",
		OPTIONS.priority_draw ? "on" : "off");
	menu_line(view, RST, "Reset", "(Press here or press 'r')");
	menu_line(view, INTERPOLATION, "Interpolation:",
		OPTIONS.interpolation ? "on" : "off");
}

void				print_menu(t_view *view)
{
	int				saved_option;

	OPTIONS.menu_draw_mode = 1;
	saved_option = OPTIONS.line_mode;
	OPTIONS.line_mode = UGLY;
	if (OPTIONS.print_menu_bg)
		print_bg(view, rgb(37, 39, 64), rgb(25, 86, 108));
	OPTIONS.line_mode = saved_option;
	OPTIONS.menu_draw_mode = 0;
	if (OPTIONS.use_image)
	{
		mlx_put_image_to_window(view->id, view->win, view->image.id, 0, 0);
		mlx_put_image_to_window(view->id, view->win, view->menu.id,
															view->ww - 400, 0);
	}
	print_switches(view);
	print_nums(view);
}
