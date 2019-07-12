/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipper_service.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:08:46 by jjacobso          #+#    #+#             */
/*   Updated: 2019/05/20 21:16:24 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					on_segment(t_coord p, t_coord q, t_coord r)
{
	if (q.x <= fmax(p.x, r.x) && q.x >= fmin(p.x, r.x) &&
		q.y <= fmax(p.y, r.y) && q.y >= fmin(p.y, r.y))
		return (1);
	return (0);
}

int					orientation(t_coord p, t_coord q, t_coord r)
{
	double			res;

	res = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
	if (ABS(res) <= DBL_EPSILON)
		return (0);
	return ((res >= DBL_EPSILON) ? 1 : 2);
}

int					intersect(t_coord p1, t_coord q1, t_coord p2, t_coord q2)
{
	int				o1;
	int				o2;
	int				o3;
	int				o4;

	o1 = orientation(p1, q1, p2);
	o2 = orientation(p1, q1, q2);
	o3 = orientation(p2, q2, p1);
	o4 = orientation(p2, q2, q1);
	if (o1 != o2 && o3 != o4)
		return (1);
	if (o1 == 0 && on_segment(p1, p2, q1))
		return (1);
	if (o2 == 0 && on_segment(p1, q2, q1))
		return (1);
	if (o3 == 0 && on_segment(p2, p1, q2))
		return (1);
	if (o4 == 0 && on_segment(p2, q1, q2))
		return (1);
	return (0);
}

double				fy(double x, t_coord s, t_coord e)
{
	return ((x - s.x) * (e.y - s.y) / (e.x - s.x) + s.y);
}

double				fx(double y, t_coord s, t_coord e)
{
	return ((y - s.y) * (e.x - s.x) / (e.y - s.y) + s.x);
}
