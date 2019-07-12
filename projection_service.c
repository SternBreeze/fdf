/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_service.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:52:19 by jjacobso          #+#    #+#             */
/*   Updated: 2019/05/16 16:42:31 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double				get_distance_to_cam(t_view *view)
{
	double			res;

	res = ft_max(ABS(MAP.max_z), ABS(MAP.min_z))
		* ((double)PROPS.z_modifier / 100) * 2.0f * K * PROPS.fscale;
	if (res < ft_max(MAP.max_x, MAP.max_y) * 2.0f * K * PROPS.fscale)
		res += ft_max(MAP.max_x, MAP.max_y) * 2.0f * K * PROPS.fscale;
	return (res);
}

void				z_perspective(t_coord *coord, double h)
{
	double			z;
	double			k;

	z = coord->z;
	if (h - z == 0)
	{
		ft_printf("Something went wrong\n");
		z = 2 * h;
	}
	k = (h / (h - z));
	coord->x *= k;
	coord->y *= k;
}

void				print_loading(int max, int cur, char is_printing)
{
	int				i;
	int				k;

	if (!is_printing)
		return ;
	if (max <= 0)
		max = 1;
	k = (int)((100 * cur) / max);
	i = -1;
	ft_printf("\r");
	while (++i < k)
		ft_printf(BGRN" "RESET);
	ft_printf("%d%%", cur * 100 / max);
}

void				apply_conic(t_coord *project, t_coord dot, double max_dist,
																	double y)
{
	project->x *= ABS(dist2d(dot, C(0, y, 0)) / y);
	project->y += max_dist - dist2d(dot, C(0, y, 0));
	project->z += max_dist - ABS(dist3d(dot, C(0, y, 0)));
}

void				rotate_around(t_coord *coord, double angle, double vecb[3])
{
	t_coord			c;
	double			cosb;
	double			sinb;

	c = *coord;
	cosb = cos(angle);
	sinb = sin(angle);
	coord->x = c.x * (cosb + (1 - cosb) * X(vecb) * X(vecb)) +
					c.y * ((1 - cosb) * X(vecb) * Y(vecb) - sinb * Z(vecb)) +
					c.z * ((1 - cosb) * X(vecb) * Z(vecb) + sinb * Y(vecb));
	coord->y = c.x * ((1 - cosb) * X(vecb) * Y(vecb) + sinb * Z(vecb)) +
					c.y * (cosb + (1 - cosb) * Y(vecb) * Y(vecb)) +
					c.z * ((1 - cosb) * Y(vecb) * Z(vecb) - sinb * X(vecb));
	coord->z = c.x * ((1 - cosb) * Z(vecb) * X(vecb) - sinb * Y(vecb)) +
					c.y * ((1 - cosb) * Z(vecb) * Y(vecb) + sinb * X(vecb)) +
					c.z * (cosb + (1 - cosb) * Z(vecb) * Z(vecb));
}
