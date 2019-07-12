/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:40:04 by jjacobso          #+#    #+#             */
/*   Updated: 2019/05/20 20:55:41 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			lamp_project(t_view *view)
{
	LAMP.projection.x = LAMP.dot.x * PROPS.fscale;
	LAMP.projection.y = LAMP.dot.y * PROPS.fscale;
	LAMP.projection.z = LAMP.dot.z * ((double)PROPS.z_modifier / 100)
																* PROPS.fscale;
}

static void			conic_project(t_view *view)
{
	int				i;
	int				j;
	double			r;
	double			y;

	MAP.center = dot_center_coord(view);
	y = -((MAP.max_y * K + MAP.center.y) * PROPS.fscale
							* (1 + (double)(PROPS.perspective_modifier) / 100));
	(IO.print_loading) ? ft_printf(GRN"\nMap projecting:\n"RESET) : 0;
	i = -1;
	while (++i < MAP.max_y)
	{
		j = -1;
		while (++j < MAP.max_x)
		{
			PROJECTION(i, j).x = (DOT(i, j).x - MAP.center.x) * PROPS.fscale;
			PROJECTION(i, j).y = (DOT(i, j).y - MAP.center.y) * PROPS.fscale;
			PROJECTION(i, j).z = DOT(i, j).z * ((double)PROPS.z_modifier / 100)
																* PROPS.fscale;
			(j == 0) ? r = dist3d(PROJECTION(i, 0), C(0, y, 0)) : 0;
			PROJECTION(i, j).w = DOT(i, j).w;
			apply_conic(&PROJECTION(i, j), PROJECTION(i, j), r, y);
		}
		print_loading(MAP.max_y, i + 1, IO.print_loading);
	}
}

static void			iso_project(t_view *view)
{
	int				i;
	int				j;
	double			y;
	double			z_mod;

	z_mod = (double)PROPS.z_modifier / 100;
	MAP.center = dot_center_coord(view);
	y = -(MAP.max_y * K * PROPS.fscale)
							* (1 + (double)(PROPS.perspective_modifier) / 100);
	i = -1;
	(IO.print_loading) ? ft_printf(GRN"\nMap projecting:\n"RESET) : 0;
	while (++i < MAP.max_y)
	{
		j = -1;
		while (++j < MAP.max_x)
		{
			PROJECTION(i, j).x = (DOT(i, j).x - MAP.center.x) * PROPS.fscale;
			PROJECTION(i, j).y = (DOT(i, j).y - MAP.center.y) * PROPS.fscale;
			PROJECTION(i, j).z = DOT(i, j).z * z_mod * PROPS.fscale;
			PROJECTION(i, j).w = DOT(i, j).w;
			if (OPTIONS.perspective)
				PROJECTION(i, j).x *= ABS(ft_frange(PROJECTION(i, j).y, y) / y);
		}
		print_loading(MAP.max_y, i + 1, IO.print_loading);
	}
}

void				project(t_view *view)
{
	int			i;
	int			j;
	double		h;

	PROPS.projection_type == CONIC ? conic_project(view) : iso_project(view);
	lamp_project(view);
	h = get_distance_to_cam(view);
	coord_reset(&MAP.center);
	(IO.print_loading) ? ft_printf(GRN"\nMap rendering:\n"RESET) : 0;
	i = -1;
	while (++i < MAP.max_y)
	{
		j = -1;
		while (++j < MAP.max_x)
		{
			rotate_around(&PROJECTION(i, j), PROPS.beta, (double[3]){1, 0, 0});
			rotate_around(&PROJECTION(i, j), PROPS.alpha, (double[3]){0, 1, 0});
			z_perspective(&PROJECTION(i, j), h);
			MAP.center.x += PROJECTION(i, j).x / (MAP.max_y * MAP.max_x);
			MAP.center.y += PROJECTION(i, j).y / (MAP.max_y * MAP.max_x);
		}
		print_loading(MAP.max_y, i + 1, IO.print_loading);
	}
	rotate_around(&LAMP.projection, PROPS.beta, (double[3]){1, 0, 0});
	rotate_around(&LAMP.projection, PROPS.alpha, (double[3]){0, 1, 0});
}
