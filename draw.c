/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:48:15 by jjacobso          #+#    #+#             */
/*   Updated: 2019/05/20 21:24:48 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord				translate(t_view *view, t_coord c)
{
	c.x = (c.x + (IMAGE.w / 2 - MAP.center.x) + MAP.offset.x);
	c.y = (c.y + (IMAGE.h / 2 - MAP.center.y) + MAP.offset.y);
	return (c);
}

static void			default_line_draw(t_view *view)
{
	int				i;
	int				j;

	if (IO.print_loading)
		ft_printf(GRN"\nMap drawing:\n"RESET);
	i = -1;
	while (++i < MAP.max_y)
	{
		j = -1;
		while (++j < MAP.max_x)
		{
			if (j + 1 < MAP.max_x)
				print_line(view, translate(view, PROJECTION(i, j)),
									translate(view, PROJECTION(i, j + 1)));
			if (i + 1 < MAP.max_y)
				print_line(view, translate(view, PROJECTION(i, j)),
									translate(view, PROJECTION(i + 1, j)));
		}
		print_loading(MAP.max_y, i + 1, IO.print_loading);
	}
}

void				print_info(t_view *view)
{
	if (IO.read_err == WRONG_INPUT)
		mlx_string_put(view->id, view->win, 5, -1, rgb(203, 15, 15),
			"Waiting for numbers input(numpad not supported; Enter to stop)");
	else if (IO.read_err == WRONG_NUM)
		mlx_string_put(view->id, view->win, 5, -1, rgb(203, 15, 15),
			"Wrong input, try again");
	else if (!OPTIONS.open_menu)
		mlx_string_put(view->id, view->win, 5, -1, rgb(227, 227, 227),
			"Press 'm' to open/close menu");
	else
		mlx_string_put(view->id, view->win, 5, -1, rgb(227, 227, 227),
			"Spin the mouse wheel to change the numbers and use the left mouse \
			button to the rest(to change color/coord click on rgb/xyz \
			component)");
}

void				print_map(t_view *view)
{
	mlx_clear_window(view->id, view->win);
	image_clear(view, view->image);
	image_clear(view, view->menu);
	if (!OPTIONS.use_image)
		mlx_put_image_to_window(view->id, view->win, view->image.id, 0, 0);
	if (!OPTIONS.priority_draw)
		default_line_draw(view);
	else
		priority_line_draw(view);
	if (OPTIONS.open_menu)
		print_menu(view);
	else if (OPTIONS.use_image)
		mlx_put_image_to_window(view->id, view->win, view->image.id, 0, 0);
	print_info(view);
	if (IO.print_loading == FIRST_LOAD)
		IO.print_loading = 0;
}
