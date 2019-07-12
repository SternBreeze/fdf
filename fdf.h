/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobso <jjacobso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:43:46 by jjacobso          #+#    #+#             */
/*   Updated: 2019/05/21 16:21:06 by jjacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"

# define COORD(x, y, z, w, clr)	(t_coord){x, y, z, w, clr}
# define C(x, y, z)				(t_coord){x, y, z, 0, 0}
# define PAIR(x, y) 			(t_pair){x, y}
# define RECT(x, y, z, w)		(t_rect){x, y, z, w}
# define LINE(x, y)				(t_line){x, y, x, y}

# define K						30.0f

# define KEY_ESC				53
# define KEY_ENTER				36
# define KEY_LMK				1
# define KEY_RMK				2
# define KEY_R					15
# define KEY_MOUSE_UP			5
# define KEY_MOUSE_DOWN			4
# define KEY_W					13
# define KEY_S					1
# define KEY_H					4
# define KEY_M					46

# define KEY_1					18
# define KEY_2					19
# define KEY_3					20
# define KEY_4					21
# define KEY_5					23
# define KEY_6					22
# define KEY_7					26
# define KEY_8					28
# define KEY_9					25
# define KEY_0					29

# define LINE_CLR				1
# define BG_CLR					2

# define LAMP_COORD				3

# define WRONG_NUM				1
# define WRONG_INPUT			2

# define SMOOTH					1
# define UGLY					0

# define INT_SENS				1
# define DOUBLE_SENS			0

# define CONIC					1
# define ISO					0

# define FIRST_LOAD				1

# define LINE_TYPE				0
# define USE_SHADER				1
# define MENU_BG				2
# define INTERPOLATION			4
# define PROJ_TYPE				5
# define PERSPECTIVE			6
# define DRAW_MODE				7
# define Z_MOD					9
# define PERSP_MOD				10
# define WHEEL_SPEED			12
# define ROTATIO_SPEED			13
# define ROTATION_SENS			14
# define BACKGROUND				16
# define L_COLOR				17
# define LIGHT_BRIGHTNESS		18
# define BRIGHTNESS				19
# define LAMP_POS				21
# define DARKNESS_BORDER		23
# define PITCH					25
# define YAW					26
# define SCALE					27
# define RST					29

# define X(v)					v[0]
# define Y(v)					v[1]
# define Z(v)					v[2]
# define DOT(x,y)				view->map.dot[x][y]
# define PROJECTION(x,y)		view->map.projection[x][y]
# define MOUSE					view->mouse
# define OPTIONS				view->options
# define IMAGE					view->image
# define MENU					view->menu
# define PROPS					view->props
# define MAP					view->map
# define IO						view->io
# define LAMP					view->lamp

# define TO_RADIANS(x)			(x * M_PI / 180)
# define TO_DEGREES(x)			(x * 180 / M_PI)
# define XOR(x, y)				((x + y) % 2)

typedef struct					s_coord
{
	double						x;
	double						y;
	double						z;
	double						w;
	int							clr;
}								t_coord;

typedef struct					s_tetra
{
	int							x;
	int							y;
	int							z;
	int							w;
}								t_tetra;

typedef struct					s_pair
{
	double						x;
	double						y;
}								t_pair;

typedef struct					s_line
{
	t_coord						s;
	t_coord						e;
	t_coord						not_clipped_s;
	t_coord						not_clipped_e;
}								t_line;

typedef struct					s_rect
{
	t_coord						a;
	t_coord						b;
	t_coord						c;
	t_coord						d;
}								t_rect;

typedef struct					s_mouse
{
	int							x;
	int							y;
	int							lmk_pressed;
	int							rmk_pressed;
}								t_mouse;

typedef struct					s_image
{
	void						*id;
	char						*data;
	int							bpp;
	int							line_size;
	int							endian;
	int							maxw;
	int							maxh;
	int							w;
	int							h;

}								t_image;

typedef struct					s_options
{
	char						rotation_global_sens;
	char						use_image;
	char						open_menu;
	char						line_mode;
	char						menu_draw_mode;
	char						print_menu_bg;
	char						priority_draw;
	char						interpolation;
	char						perspective;
}								t_options;

typedef struct					s_props
{
	double						fscale;
	double						alpha;
	double						beta;
	double						gamma;
	int							rotation_speed;
	int							z_modifier;
	int							perspective_modifier;
	int							brightness;
	char						projection_type;
	int							bg_clr;
	int							line_clr;
	int							darkness_border;
}								t_props;

typedef struct					s_map
{
	t_coord						center;
	t_pair						offset;
	t_pair						last_offset;
	int							max_x;
	int							max_y;
	int							max_z;
	int							min_z;
	t_coord						**dot;
	t_coord						**projection;
}								t_map;

typedef struct					s_io
{
	int							input;
	int							saved_clr;
	t_coord						saved_coord;
	char						read_mode;
	char						to_read;
	char						read_err;
	int							wheel_speed;
	char						print_loading;
}								t_io;

typedef struct					s_lamp
{
	int							light_brightness;
	t_coord						projection;
	t_coord						dot;
}								t_lamp;

typedef struct					s_view
{
	void						*id;
	void						*win;
	t_map						map;
	t_mouse						mouse;
	t_image						image;
	t_image						menu;
	t_props						props;
	int							ww;
	int							wh;
	t_options					options;
	t_io						io;
	t_lamp						lamp;
	t_queue						*draw_queue;
	t_rect						clip_space;
}								t_view;
/*
**								service.c
*/
void							close_program(t_view *view);
void							error(char *s);
t_view							get_view();
/*
**								hooks.c
*/
int								exit_hook(t_view *view);
int								motion_hook(int x, int y, t_view *view);
int								mouse_press_hook(int key, int x, int y,
													t_view *view);
int								mouse_release_hook(int key, int x, int y,
													t_view *view);
int								key_press_hook(int key, t_view *view);
/*
**								parse.c:
*/
void							read_map(t_view *view, const char *file);

/*
**								draw.c
*/
void							print_info(t_view *view);
void							print_map(t_view *view);
t_coord							translate(t_view *view, t_coord c);
/*
**								projection.c
*/
void							project(t_view *view);
/*
**								image.c
*/
void							image_init(void *id, t_image *image, int ww,
													int wh);
void							pixel_put(t_view *view, double x, double y,
													int clr);
void							image_clear(t_view *view, t_image img);
/*
**								menu.c
*/
void							print_menu(t_view *view);
/*
**								priority_draw.c
*/
t_list							*get_z_lvls(t_view *view);
void							fill_draw_queue(t_view *view);
void							priority_line_draw(t_view *view);
/*
**								hook_service.c
*/
void							set_hooks(t_view *view);
void							lock_angle(double *angle, double min,
													double max);
void							set_angles(t_view *view, int x, int y);
void							set_clr(t_view *view);
int								get_line_number(int y, int wh);
/*
**								io_service.c
*/
int								io_is_reading(t_view *view);
void							io_set_coord(t_view *view);
int								io_read_clr(t_view *view, int key);
int								io_read_coord(t_view *view, int key);
/*
**								io.c
*/
int								io_read_coord_prepare(t_view *view, int x);
int								io_read_clr_prepare(t_view *view, int x,
													int clr_type, int clr);
int								io_read(t_view *view, int key);
/*
**								map.c
*/
int								map_reset(t_view *view);
t_coord							dot_center_coord(t_view *view);
void							coord_reset(t_coord *c);
double							dist3d(t_coord a, t_coord b);
double							dist2d(t_coord a, t_coord b);
/*
**								menu_hooks.c
*/
void							menu_lmc_handle(t_view *view, int x, int line);
void							menu_wheel_handle(t_view *view, int key,
													int line);
void							menu_mouse_hook(t_view *view, int key, int x,
													int y);
/*
**								color.c
*/
int								str_to_clr(char *s);
int								rgb(int r, int g, int b);
void							set_line_color(t_view *view);
/*
**								light.c
*/
void							apply_light(t_view *view);
int								darker(int clr, double k);
int								brighter(int clr, double k);
/*
**								menu_output.c
*/
void							menu_line_with_coord(t_view *view, int line,
													char *s, t_coord c);
void							menu_line_with_clr(t_view *view, int line,
													char *s, int clr);
void							menu_line_with_num(t_view *view, int line,
													char *s, int num);
void							menu_line_with_num_and_procent(t_view *view,
													int line, char *s, int num);
/*
**								menu_output_service.c
*/
char							*nspaces(int n);
char							*clr_to_line(int clr);
char							*coord_to_line(t_coord c);
void							rgb_print(t_view *view, int line, int clr,
													char *s);
/*
**								tetra.c
*/
void							*copy_tetra(void *tetra);
t_tetra							*tetra_mas(t_tetra t);
/*
**								print_line.c:
*/
void							line_reverse(t_line *line);
void							print_line(t_view *view, t_coord s,
													t_coord e);
void							print_smooth_line(t_view *view, t_line l);
/*
**								print_smooth_line.c
*/
void							print_smooth_yline(t_view *view, t_line l);
void							print_smooth_xline(t_view *view, t_line l);
int								intensity(int sclr, int eclr, double c,
													double z);
double							interpolation_coeff(t_view *view, t_line l,
													char c);
/*
**								clipper.c
*/
int								invisible(t_view *view, t_coord *s, t_coord *e);
/*
**								clipper_service.c
*/
int								intersect(t_coord a, t_coord b, t_coord c,
													t_coord d);
double							fy(double x, t_coord s, t_coord e);
double							fx(double y, t_coord s, t_coord e);

/*
**								projection_service.c
*/
void							print_loading(int max, int cur,
													char is_printing);
double							get_distance_to_cam(t_view *view);
void							rotate_around(t_coord *coord, double angle,
													double vecb[3]);
void							apply_conic(t_coord *project, t_coord dot,
													double max_dist, double y);
void							z_perspective(t_coord *coord, double h);

/*
**								scale.c
*/
void							auto_scale(t_view *view);
void							scale_adjust(t_view *view, int key);
#endif
