/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 18:43:07 by jjacobso          #+#    #+#             */
/*   Updated: 2019/05/16 20:14:35 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					darker(int clr, double k)
{
	int r;
	int g;
	int b;

	r = (clr & 0xFF0000) >> 16;
	g = (clr & 0xFF00) >> 8;
	b = (clr & 0xFF);
	r = (int)(r - r * k);
	g = (int)(g - g * k);
	b = (int)(b - b * k);
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	return (rgb(r, g, b));
}

int					brighter(int clr, double k)
{
	int				r;
	int				g;
	int				b;
	int				max;

	r = (clr & 0xFF0000) >> 16;
	g = (clr & 0xFF00) >> 8;
	b = (clr & 0xFF);
	max = ft_max(r, ft_max(g, b));
	if (max != r)
		r = (int)(r + (255 - ((max == 255) ? 64 : max)) * k);
	if (max != g)
		g = (int)(g + (255 - ((max == 255) ? 64 : max)) * k);
	if (max != b)
		b = (int)(b + (255 - ((max == 255) ? 64 : max)) * k);
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return (rgb(r, g, b));
}

static double		get_max_dist_to_lamp(t_view *view)
{
	double			d;
	double			maxd;
	int				i;
	int				j;

	maxd = dist3d(LAMP.projection, PROJECTION(0, 0));
	i = 0;
	while (i < MAP.max_y)
	{
		j = 0;
		while (j < MAP.max_x)
		{
			d = dist3d(LAMP.projection, PROJECTION(i, j));
			if (maxd < d)
				maxd = d;
			j++;
		}
		i++;
	}
	d = maxd;
	if (d == 0)
		d = 1;
	return (d);
}

void				apply_light(t_view *view)
{
	double			maxd;
	int				i;
	int				j;
	double			k;

	maxd = get_max_dist_to_lamp(view);
	i = 0;
	while (i < MAP.max_y)
	{
		j = 0;
		while (j < MAP.max_x)
		{
			k = sqrt(dist3d(LAMP.projection, PROJECTION(i, j)) / maxd);
			if (LAMP.light_brightness == 100)
				PROJECTION(i, j).clr = 0;
			else
				PROJECTION(i, j).clr = darker(PROJECTION(i, j).clr,
							(pow((double)LAMP.light_brightness / 54, 2)) * k);
			j++;
		}
		i++;
	}
}
