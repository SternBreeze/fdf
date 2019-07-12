/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:30:35 by jjacobso          #+#    #+#             */
/*   Updated: 2019/05/21 17:28:03 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				close_program(t_view *view)
{
	int				i;

	mlx_destroy_image(view->id, IMAGE.id);
	mlx_destroy_image(view->id, MENU.id);
	mlx_destroy_window(view->id, view->win);
	i = -1;
	while (++i < MAP.max_y)
	{
		ft_memdel((void**)&MAP.projection[i]);
		ft_memdel((void**)&MAP.dot[i]);
	}
	ft_memdel((void**)&MAP.projection);
	ft_memdel((void**)&MAP.dot);
	q_destroy(&view->draw_queue);
}

void				error(char *s)
{
	ft_printf("\n%s\n", s);
	exit(-1);
}

t_view				get_view(void)
{
	t_view		view;

	ft_bzero((void*)&view, sizeof(t_view));
	if (!(view.id = mlx_init()))
		error("Cannot establish connection with graphic server");
	image_init(view.id, &view.image, (view.ww = 2048),
		(view.wh = 1024));
	image_init(view.id, &view.menu, 400, view.wh);
	if (!(view.win = mlx_new_window(view.id, view.ww, view.wh, "fdf project")))
		error("Cannot open window");
	view.options.line_mode = UGLY;
	view.options.use_image = 1;
	view.options.print_menu_bg = 1;
	view.props.fscale = 1;
	view.props.rotation_speed = 100;
	view.props.z_modifier = 100;
	view.options.interpolation = 1;
	view.props.perspective_modifier = 100;
	view.props.line_clr = rgb(207, 101, 42);
	view.io.wheel_speed = 4;
	view.clip_space = RECT(C(10, 10, 0), C(view.ww - 10, 10, 0),
		C(view.ww - 10, view.wh - 10, 0), C(10, view.wh - 10, 0));
	view.props.darkness_border = 30;
	view.io.print_loading = FIRST_LOAD;
	return (view);
}
