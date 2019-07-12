/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 14:38:24 by jjacobso          #+#    #+#             */
/*   Updated: 2019/05/21 16:59:33 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			get_coord(t_view *view, char **str, int i, int j)
{
	char			**s;
	int				z;

	s = str;
	if (!ft_isnum(*s))
		error("Invalid map");
	if ((z = ft_atoi(*s)) > MAP.max_z)
		MAP.max_z = z;
	if (z < MAP.min_z)
		MAP.min_z = z;
	s++;
	view->map.dot[j][i] = COORD(i * K, j * K, z * K, z, str_to_clr(*s));
	ft_freemas(&str, 0);
}

static void			line_to_coords(t_view *view, char *line, int j)
{
	char			**s;
	int				i;
	int				words;

	i = 0;
	s = ft_strsplit(line, ' ');
	words = ft_words(s);
	if (j == 0)
		MAP.max_x = words;
	else if (words != MAP.max_x)
		error("Invalid map");
	if (!(MAP.dot[j] = (t_coord *)malloc(sizeof(t_coord) * words)))
		error("Malloc error");
	while (s && s[i])
	{
		get_coord(view, ft_strsplit(s[i], ','), i, j);
		i++;
	}
	ft_freemas(&s, 0);
}

static void			read_lines(t_view *view, t_list **lines, int fd)
{
	char			*line;
	char			readed;
	int				j;

	j = 0;
	if (IO.print_loading)
		ft_printf(GRN"\nMap reading:\n"RESET);
	while ((readed = get_next_line(fd, &line)) > 0)
	{
		ld_push_back(lines, line);
		print_loading(MAP.max_y, ++j, IO.print_loading);
	}
	if (readed < 0 || j == 0)
		error("Invalid map");
}

void				read_map(t_view *view, const char *file)
{
	t_list			*lines;
	t_list			*t;
	int				fd;
	int				j;

	lines = 0;
	if ((fd = open(file, O_RDONLY)) < 0)
		error("Cannot open file");
	read_lines(view, &lines, fd);
	close(fd);
	if (!(view->map.dot = (t_coord **)malloc(sizeof(t_coord *) * MAP.max_y)))
		error("Malloc error");
	t = lines;
	j = 0;
	MAP.max_z = ft_atoi((char *)t->data);
	MAP.min_z = MAP.max_z;
	while (t)
	{
		line_to_coords(view, (char *)t->data, j++);
		t = t->next;
	}
	l_destroy(&lines);
	MAP.center = dot_center_coord(view);
	if (MAP.max_x <= 1 && MAP.max_y <= 1)
		error("Invalid map");
}
