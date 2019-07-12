/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:14:54 by jjacobso          #+#    #+#             */
/*   Updated: 2019/05/21 21:56:06 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	adjust_z(t_view *view)
{
	int		*p;
	int		i;
	int		j;

	p = 0;
	if (MAP.min_z > 0)
		p = &MAP.min_z;
	else if (MAP.max_z < 0)
		p = &MAP.max_z;
	if (p)
	{
		i = -1;
		while (++i < MAP.max_y)
		{
			j = -1;
			while (++j < MAP.max_x)
			{
				DOT(i, j).z -= *p * K;
				DOT(i, j).w -= *p;
			}
		}
		*p -= *p;
	}
}

static int	n(char *s)
{
	int				lines;

	lines = 0;
	if (!s || !*s)
		return (0);
	while (*s)
		if (*s++ == '\n')
			lines++;
	return (lines);
}

static int	count_lines(const char *fn)
{
	int		lines;
	int		fd;
	int		readed;
	char	*b;

	lines = 0;
	if ((fd = open(fn, O_RDONLY)) < 0)
		error("Cannot open file");
	if (!(b = (char *)malloc(2001)))
		error("Malloc error");
	while ((readed = read(fd, b, 2000)) > 0)
	{
		b[readed] = '\0';
		lines += n(b);
	}
	if (readed < 0 || lines == 0)
		error("Invalid map");
	ft_memdel((void **)&b);
	close(fd);
	return (lines);
}

int			main(int argc, char const *argv[])
{
	t_view	view;
	int		i;

	if (argc != 2)
		return (ft_printf("usage: ./fdf map_name\n"));
	view = get_view();
	view.map.max_y = count_lines(argv[1]);
	read_map(&view, argv[1]);
	adjust_z(&view);
	auto_scale(&view);
	if (!(view.map.projection = (t_coord **)malloc(sizeof(t_coord *)
															* view.map.max_y)))
		error("Malloc error");
	i = -1;
	while (++i < view.map.max_y)
		if (!(view.map.projection[i] = (t_coord *)malloc(sizeof(t_coord)
															* view.map.max_x)))
			error("Malloc error");
	set_line_color(&view);
	project(&view);
	print_map(&view);
	set_hooks(&view);
	mlx_loop(view.id);
	return (0);
}
