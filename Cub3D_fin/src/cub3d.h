/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* LIBS */
# include "../minilibx_macos/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

/* DEFINES */
# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

/* STRUCTS */

typedef struct s_coord
{
	int		x;
	int		y;
	float	x_f;
	float	y_f;
}			t_coord;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}		t_color;

typedef struct s_flags
{
	int		count_line;
	int		flag_no;
	int		flag_so;
	int		flag_we;
	int		flag_ea;
	int		flag_s;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		s;
	char	*n_side;
	char	*s_side;
	char	*w_side;
	char	*e_side;
	int		flag_f;
	int		flag_c;
	t_color	f;
	t_color	c;
	int		flag_r;
	t_coord	r;
	t_coord	r_min;
	t_coord	r_max;
}			t_flags;

typedef struct s_movement
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	movespeed;
	double	rotspeed;
	int		w;
	int		h;
}			t_movement;

typedef struct s_images
{
	int		sprites_width;
	int		sprites_height;
	int		size_line;
	int		endlan;
	int		bpp;
	void	*wall;
	int		*data;
}			t_images;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		img_width;
	int		img_height;
	char	*addr;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
}			t_mlx;

typedef struct s_button_flag
{
	int	w_stat;
	int	s_stat;
	int	d_stat;
	int	a_stat;
	int	right_stat;
	int	left_stat;
}		t_button_flag;

typedef struct s_map
{
	int	color_wall;
	int	color_empty;
	int	color_player;
	int	size;
	int	mode;
	int	cell;
}		t_map;

typedef struct s_print_data
{
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
	double	wallx;
	int		numtext;
	double	step;
	double	texpos;
	int		texx;
}t_print_data;

typedef struct s_data
{
	int				fd;
	char			**field;
	int				line_count;
	int				line_max;
	int				column_count;
	int				column_max;
	int				f;
	int				c;
	t_flags			flags;
	t_mlx			my_mlx;
	t_button_flag	button_f;
	t_images		*images;
	t_map			mini_map;
	t_movement		movement;
}				t_data;

/* FUNCTIONS */

/* cub3d.c */
void	error_msg(char *msg);

/* initialization.c */
void	init_data(t_data *data);
void	init_flag(t_flags *flags);
void	init_color(t_color *color);
void	init_coord(t_coord *coord);

/* file_checker.c */
void	check_valid_arg(int argc, char **argv);
int		check_open_file(char *map_file);

/* symbols_checker.c */
int		check_valid_symbols(t_flags *flags, int fd);
int		check_config_line(t_flags *flags, char *line);
int		check_xpm_path(int *flag, int *xpm_image, char *line, char **way);
int		check_name_of_path(int *start, int *end, char *line);
void	skip_symbols(char *str, int *i, char symbol);
int		check_line_r_x(t_flags *flags, char *line, int *i);
int		check_line_r_y(t_flags *flags, char *line, int *i);
int		check_line_r(t_flags *flags, char *line);

/* line_color_checker.c */
int		check_line_color(int *flag, t_color *color, char *line);
int		check_line_color_rgb(int *log, int *color, char *line, int *i);
int		check_is_color(char *line, int i, t_color log_rgb);

/* check_struct_flag.c */
int		check_all_flags(t_flags flags);
int		check_double_flags(t_flags flags);

/* map_checker.c */
int		check_map(t_data *data);
int		check_map_helper(t_data *data, int *plr, char *line, int r);
int		check_line_in_map(t_data *data, char *line, int *plr);
int		check_symbol_in_map(char c);

/* map_parser.c */
int		parse_map(t_data *data, char *name);
int		map_memory_alloc(t_data *data);
void	border_maker(t_data *data);
void	map_maker(t_data *data, char *name);
void	replace_map_tmp(t_data *data);

/* border_checker.c */
int		check_map_border(t_data data);
int		check_border_help(t_data data, int i, int j);

/* render.c */
int		give_me_graphics(t_data *data);
int		show_must_go_on(t_data *data);
void	go_render(t_print_data *game, t_data *data, int x);
int		init_my_mlx(t_data *data);

/* render_initialization.c */
void	init_img(t_data *data);
void	init_img_help(t_data *data);
void	init_mini_map(t_data *data);
void	init_buttom_struct(t_button_flag *button_f);

/* calculate.c */
void	calc_1(t_print_data *game, t_data *data, int x);
void	calc_2(t_print_data *game, t_data *data);
void	calc_3(t_print_data *game, t_data *data);
void	calc_4(t_print_data *game, t_data *data);
void	calc_5(t_print_data *game, t_data *data);

/* init_player.c */
void	init_plr(t_data *data);
void	init_plr_ns(t_data *data, int i, int j);
void	init_plr_ew(t_data *data, int i, int j);

/* mini_map.c */
void	display_mini_map(t_data *data);
void	coord(t_coord *a, int a_x, int a_y);
void	mini_map_plr(t_data *data, int cell);
void	stop_mini_map(	t_data *data, t_coord coord_player, \
								t_coord start, t_coord size);
void	square_print(t_data *data, t_coord start, t_coord size, int color);

/* move.c */
void	move_side(t_data *data, int flag, double *x, double *y);
void	move_forward(t_data *data, int flag, double *x, double *y);
void	change_plr_pos(t_data *data, double row, double col);
int		not_wall(t_data *data, double row, double col);

/* key.c */
int		key_press(int keycode, t_data *data);
void	key_press_take(int keycode, t_data *data);
void	key_minimap(int keycode, t_data *data);
void	key_press_r(t_data *data);
void	key_press_l(t_data *data);
void	ft_key_press(t_data *data);

/*key_help.c*/
int		key_close(int keycode, t_data *data);
int		key_repress(int keycode, t_data *data);

/* utils.c */
void	ft_copy_line(char *line, char **way, int len);
int		min(int x, int y);
int		rgb(int t, int r, int g, int b);
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
int		numoftext(int side, int stepY, int stepX);

#endif
