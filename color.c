/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 20:12:39 by jjacobso          #+#    #+#             */
/*   Updated: 2019/05/21 21:42:10 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			is_hex_clr(char *s)
{
	int				i;

	if (!s)
		return (0);
	i = 0;
	while (i < 6)
	{
		if (!s[i] || !(ft_isdigit(s[i]) || ft_isalpha(s[i])))
			return (0);
		i++;
	}
	return (1);
}

int					str_to_clr(char *s)
{
	if (!s)
		return (0);
	if (s[0] == '0' && s[1] == 'x')
		s += 2;
	else
		error("Invalid map");
	if (!is_hex_clr(s))
		error("Invalid map");
	return (ft_atoibase(s, 16));
}

int					rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

static double		get_lvl(t_list *z, double border, int w, int size)
{
	int				i;
	double			res;

	i = 1;
	while (z)
	{
		if (w == *(int *)z->data)
		{
			res = (double)i / size;
			if (res < border)
				return (border);
			return (res);
		}
		z = z->next;
		i++;
	}
	ft_printf("ERROR\n");
	exit(-1);
}

void				set_line_color(t_view *view)
{
	t_list		*z;
	int			i;
	int			j;
	int			size;

	z = get_z_lvls(view);
	size = l_size(z);
	i = -1;
	while (++i < MAP.max_y && (j = -1))
		while (++j < MAP.max_x)
		{
			if (PROPS.brightness < 0)
				PROJECTION(i, j).clr = darker(DOT(i, j).clr ? DOT(i, j).clr
					: PROPS.line_clr, ((double)ABS(PROPS.brightness)) / 100);
			else
				PROJECTION(i, j).clr = brighter(DOT(i, j).clr ? DOT(i, j).clr
					: PROPS.line_clr, (double)PROPS.brightness / 100);
			PROJECTION(i, j).clr = intensity(PROJECTION(i, j).clr, 0,
					OPTIONS.interpolation ?
					get_lvl(z, (double)PROPS.darkness_border / 100,
						DOT(i, j).w, size) : 1, 0);
		}
	l_destroy(&z);
}
