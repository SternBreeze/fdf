/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 21:11:29 by jjacobso          #+#    #+#             */
/*   Updated: 2019/05/20 21:11:40 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	compare(double x, double y, char sign)
{
	if (sign == '>')
		return (x >= y);
	if (sign == '<')
		return (x <= y);
	return (0);
}

void		clip_x(t_coord *s, t_coord *e, double x, char sign)
{
	if (compare(s->x, x, sign))
	{
		s->y = floor(fy(x, *s, *e));
		s->x = x;
	}
	if (compare(e->x, x, sign))
	{
		e->y = floor(fy(x, *s, *e));
		e->x = x;
	}
}

void		clip_y(t_coord *s, t_coord *e, double y, char sign)
{
	if (compare(s->y, y, sign))
	{
		s->x = floor(fx(y, *s, *e));
		s->y = y;
	}
	if (compare(e->y, y, sign))
	{
		e->x = floor(fx(y, *s, *e));
		e->y = y;
	}
}

int			clip_line(t_view *view, t_coord *s, t_coord *e)
{
	int		clipped;

	clipped = 1;
	if (intersect(view->clip_space.a, view->clip_space.b, *s, *e))
	{
		clip_y(s, e, view->clip_space.a.y, '<');
		clipped = 0;
	}
	if (intersect(view->clip_space.b, view->clip_space.c, *s, *e))
	{
		clip_x(s, e, view->clip_space.b.x, '>');
		clipped = 0;
	}
	if (intersect(view->clip_space.c, view->clip_space.d, *s, *e))
	{
		clip_y(s, e, view->clip_space.c.y, '>');
		clipped = 0;
	}
	if (intersect(view->clip_space.d, view->clip_space.a, *s, *e))
	{
		clip_x(s, e, view->clip_space.d.x, '<');
		clipped = 0;
	}
	return (clipped);
}

int			invisible(t_view *view, t_coord *s, t_coord *e)
{
	if ((!ft_finrange(s->x, view->clip_space.a.x, view->clip_space.c.x)
		|| !ft_finrange(s->y, view->clip_space.a.y, view->clip_space.c.y))
	&& (!ft_finrange(e->x, view->clip_space.a.x, view->clip_space.c.x)
		|| !ft_finrange(e->y, view->clip_space.a.y, view->clip_space.c.y)))
		return (clip_line(view, s, e));
	clip_line(view, s, e);
	return (0);
}
