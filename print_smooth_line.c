/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_smooth_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:19:40 by jjacobso          #+#    #+#             */
/*   Updated: 2019/05/20 21:52:31 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				intensity(int sclr, int eclr, double c, double z)
{
	int			r;
	int			g;
	int			b;

	r = (sclr & 0xFF0000) >> 16;
	g = (sclr & 0xFF00) >> 8;
	b = (sclr & 0xFF);
	r = (int)((r + (((eclr & 0xFF0000) >> 16) - r) * z) * c);
	g = (int)((g + (((eclr & 0xFF00) >> 8) - g) * z) * c);
	b = (int)((b + ((eclr & 0xFF) - b) * z) * c);
	return (rgb(r, g, b));
}

double			interpolation_coeff(t_view *view, t_line line, char c)
{
	if (!OPTIONS.interpolation)
		return (0.5);
	if (c == 'y')
		return (ft_frange(line.s.y, line.not_clipped_s.y)
			/ ft_frange(line.e.y, line.not_clipped_s.y));
	else
		return (ft_frange(line.s.x, line.not_clipped_s.x)
			/ ft_frange(line.e.x, line.not_clipped_s.x));
}

void			print_smooth_xline(t_view *view, t_line line)
{
	double		dx;
	double		dy;
	double		grad;
	double		y;

	dx = ft_frange(line.s.x, line.e.x);
	dy = ft_frange(line.s.y, line.e.y);
	grad = dy / dx * (line.s.y > line.e.y ? -1 : 1);
	y = line.s.y;
	while (line.s.x < line.e.x)
	{
		pixel_put(view, line.s.x, y,
			intensity(line.s.clr, line.e.clr,
				sqrt(1 - fpart(y)),
				interpolation_coeff(view, line, 'x')));
		pixel_put(view, line.s.x, y + 1,
			intensity(line.s.clr, line.e.clr,
				sqrt(fpart(y)),
				interpolation_coeff(view, line, 'x')));
		y += grad;
		line.s.x++;
	}
}

void			print_smooth_yline(t_view *view, t_line line)
{
	double		dx;
	double		dy;
	double		grad;
	double		x;

	dx = ft_frange(line.s.x, line.e.x);
	dy = ft_frange(line.s.y, line.e.y);
	grad = dx / dy * (line.s.x > line.e.x ? -1 : 1);
	x = line.s.x;
	while (line.s.y < line.e.y)
	{
		pixel_put(view, x, line.s.y,
			intensity(line.s.clr, line.e.clr,
				sqrt(1 - fpart(x)),
				interpolation_coeff(view, line, 'y')));
		pixel_put(view, x + 1, line.s.y,
			intensity(line.s.clr, line.e.clr,
				sqrt(fpart(x)),
				interpolation_coeff(view, line, 'y')));
		x += grad;
		line.s.y++;
	}
}

void			print_smooth_line(t_view *view, t_line line)
{
	if (ft_frange(line.s.y, line.e.y) < ft_frange(line.s.x, line.e.x) ||
		ft_frange(line.s.y, line.e.y) == 0)
	{
		if (line.s.x > line.e.x)
			line_reverse(&line);
		print_smooth_xline(view, line);
	}
	else
	{
		if (line.s.y > line.e.y)
			line_reverse(&line);
		print_smooth_yline(view, line);
	}
}
