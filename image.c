/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:53:14 by jjacobso          #+#    #+#             */
/*   Updated: 2019/04/19 17:53:03 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		pixel_put(t_view *view, double fx, double fy, int clr)
{
	int		x;
	int		y;

	x = (int)fx;
	y = (int)fy;
	if (!OPTIONS.use_image)
	{
		if ((x < 0 || x > view->ww - 1 || y < 0 || y > view->wh - 1))
			return ;
		mlx_pixel_put(view->id, view->win, x, y, clr);
	}
	else if (!OPTIONS.menu_draw_mode)
	{
		if (x < 0 || x > IMAGE.w - 1 || y < 0 || y > IMAGE.h - 1)
			return ;
		*(int *)(view->image.data
			+ (x * view->image.bpp / 8) + (view->image.line_size * y)) = clr;
	}
	else
	{
		if (x < 0 || x > MENU.w - 1 || y < 0 || y > MENU.h - 1)
			return ;
		*(int *)(view->menu.data
			+ (x * view->menu.bpp / 8) + (view->menu.line_size * y)) = clr;
	}
}

void		image_clear(t_view *view, t_image img)
{
	img.data = ft_intset(img.data, PROPS.bg_clr, img.maxw * img.maxh);
}

void		image_init(void *id, t_image *image, int ww, int wh)
{
	image->w = ww;
	image->h = wh;
	image->maxw = ww;
	image->maxh = wh;
	if (!(image->id = mlx_new_image(id, image->w, image->h)))
		error("Mlx img init error");
	if (!(image->data = mlx_get_data_addr(image->id, &image->bpp,
									&image->line_size, &image->endian)))
		error("Mlx img init error");
}
