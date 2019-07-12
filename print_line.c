/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 19:46:49 by jjacobso          #+#    #+#             */
/*   Updated: 2019/05/20 21:51:18 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			print_xline(t_view *view, t_line line)
{
	double			dx;
	double			dy;
	double			grad;
	double			y;

	dx = ft_frange(line.s.x, line.e.x);
	dy = ft_frange(line.s.y, line.e.y);
	grad = (double)dy / dx * (line.s.y > line.e.y ? -1 : 1);
	y = line.s.y;
	while (line.s.x < line.e.x)
	{
		pixel_put(view, line.s.x, y, intensity(line.s.clr, line.e.clr, 1,
			interpolation_coeff(view, line, 'x')));
		y += grad;
		line.s.x++;
	}
}

static void			print_yline(t_view *view, t_line line)
{
	double			dx;
	double			dy;
	double			grad;
	double			x;

	dx = ft_frange(line.s.x, line.e.x);
	dy = ft_frange(line.s.y, line.e.y);
	grad = dx / dy * (line.s.x > line.e.x ? -1 : 1);
	x = line.s.x;
	while (line.s.y < line.e.y)
	{
		pixel_put(view, x, line.s.y, intensity(line.s.clr, line.e.clr, 1,
			interpolation_coeff(view, line, 'y')));
		x += grad;
		line.s.y++;
	}
}

void				line_reverse(t_line *line)
{
	t_coord			b;

	b = line->s;
	line->s = line->e;
	line->e = b;
	b = line->not_clipped_s;
	line->not_clipped_s = line->not_clipped_e;
	line->not_clipped_e = b;
}

void				print_line(t_view *view, t_coord s, t_coord e)
{
	t_line			line;

	line = LINE(s, e);
	if (!OPTIONS.menu_draw_mode)
		if (invisible(view, &line.s, &line.e))
			return ;
	if (OPTIONS.line_mode == SMOOTH)
	{
		print_smooth_line(view, line);
		return ;
	}
	if (ft_frange(line.s.y, line.e.y) < ft_frange(line.s.x, line.e.x)
		|| ft_frange(line.s.y, line.e.y) == 0)
	{
		if (line.s.x > line.e.x)
			line_reverse(&line);
		print_xline(view, line);
	}
	else
	{
		if (line.s.y > line.e.y)
			line_reverse(&line);
		print_yline(view, line);
	}
}
