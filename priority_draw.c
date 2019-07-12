/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   priority_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:38:57 by jjacobso          #+#    #+#             */
/*   Updated: 2019/05/21 21:56:18 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list				*get_z_lvls(t_view *view)
{
	t_list			*z_list;
	int				i;
	int				j;

	z_list = 0;
	i = 0;
	while (i < MAP.max_y)
	{
		j = 0;
		while (j < MAP.max_x)
		{
			if (!l_int_find(z_list, (int)DOT(i, j).w))
				ld_push_back(&z_list, ft_int_get_mass((int)DOT(i, j).w));
			j++;
		}
		i++;
	}
	l_int_sort(z_list);
	return (z_list);
}

static void			add_lvl_to_queue(t_view *view, t_queue *q, int k)
{
	int				i;
	int				j;

	i = -1;
	while (++i < MAP.max_y)
	{
		j = -1;
		while (++j < MAP.max_x)
			if (k == (int)DOT(i, j).z)
			{
				if (j + 1 < MAP.max_x && (int)DOT(i, j + 1).z == k)
					if (!q_push(q, tetra_mas((t_tetra){i, j, i, j + 1})))
						error("Malloc error");
				if (i + 1 < MAP.max_y && (int)DOT(i + 1, j).z == k)
					if (!q_push(q, tetra_mas((t_tetra){i, j, i + 1, j})))
						error("Malloc error");
				if (i - 1 >= 0 && (int)DOT(i - 1, j).z == k)
					if (!q_push(q, tetra_mas((t_tetra){i, j, i - 1, j})))
						error("Malloc error");
				if (j - 1 >= 0 && (int)DOT(i, j - 1).z == k)
					if (!q_push(q, tetra_mas((t_tetra){i, j, i, j - 1})))
						error("Malloc error");
			}
	}
}

static void			add_diag_to_queue(t_view *view, t_queue *q, int k)
{
	int				i;
	int				j;

	i = -1;
	while (++i < MAP.max_y)
	{
		j = -1;
		while (++j < MAP.max_x)
			if (k == (int)DOT(i, j).z)
			{
				if (j + 1 < MAP.max_x && (int)DOT(i, j + 1).z > k)
					if (!q_push(q, tetra_mas((t_tetra){i, j, i, j + 1})))
						error("Malloc error");
				if (i + 1 < MAP.max_y && (int)DOT(i + 1, j).z > k)
					if (!q_push(q, tetra_mas((t_tetra){i, j, i + 1, j})))
						error("Malloc error");
				if (i - 1 >= 0 && (int)DOT(i - 1, j).z > k)
					if (!q_push(q, tetra_mas((t_tetra){i, j, i - 1, j})))
						error("Malloc error");
				if (j - 1 >= 0 && (int)DOT(i, j - 1).z > k)
					if (!q_push(q, tetra_mas((t_tetra){i, j, i, j - 1})))
						error("Malloc error");
			}
	}
}

void				fill_draw_queue(t_view *view)
{
	t_list			*z;
	t_list			*t;

	if (!q_init(&view->draw_queue))
		error("Malloc error");
	z = get_z_lvls(view);
	t = z;
	while (t)
	{
		add_lvl_to_queue(view, view->draw_queue, *(int *)t->data * K);
		add_diag_to_queue(view, view->draw_queue, *(int *)t->data * K);
		t = t->next;
	}
	l_destroy(&z);
}

void				priority_line_draw(t_view *view)
{
	t_queue			*q;
	t_tetra			*c;

	if (!view->draw_queue)
		fill_draw_queue(view);
	if (!(q = q_copy(view->draw_queue, &copy_tetra)))
		error("Malloc error");
	if (XOR(ft_finrange(ABS(PROPS.alpha), TO_RADIANS(90), TO_RADIANS(270)),
			ft_finrange(ABS(PROPS.beta), TO_RADIANS(90), TO_RADIANS(270))))
		q_reverse(q);
	while (!q_is_empty(q))
	{
		c = (t_tetra *)q_pop(q);
		print_line(view, translate(view, PROJECTION(c->x, c->y)),
			translate(view, PROJECTION(c->z, c->w)));
		ft_memdel((void**)&c);
	}
	q_destroy(&q);
}
