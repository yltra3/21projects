/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:53:52 by clornel           #+#    #+#             */
/*   Updated: 2022/04/13 20:53:54 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx_opengl/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

# define PIC_SIZE	64
# define WALL		'1'
# define NONE		'0'
# define HERO		'P'
# define EXIT		'E'
# define COIN		'C'
# define ENEMY		'K'
# define SYMBOLS	"10PECK"
# define W_KEY		13
# define A_KEY		0
# define S_KEY		1
# define D_KEY		2

typedef struct s_gmap
{
	size_t			width;
	size_t			height;
	size_t			hero;
	size_t			coin;
	size_t			earn_coins;
	size_t			moves;
	size_t			exits;
	size_t			i;
	size_t			j;
	int				max_width;
	int				max_height;
	char			**field;
	struct s_vars	*data;
}	t_gmap;

typedef struct s_img
{
	void			*wall;
	void			*empty;
	void			*hero;
	void			*hero_up;
	void			*hero_l;
	void			*hero_r;
	void			*coin;
	void			*enemy[3];
	void			*none;
	void			*exit;
	struct s_vars	*data;
}	t_img;

typedef struct s_vars
{
	size_t	p_x;
	size_t	p_y;
	size_t	res_x;
	size_t	res_y;
	size_t	timer;
	int		fl;
	int		bonus;
	void	*mlx;
	void	*win;
	void	*image;
	int		i;
	int		j;

	t_gmap	*gmap;
	t_img	*img;
}	t_vars;

void		ft_step(t_vars *vars, int key, t_gmap *gmap);
void		ft_info_draw(t_vars *vars, t_gmap *gmap);
void		ft_free_data(t_vars *vars);
void		ft_linku_starto(t_vars *vars);
void		ft_err_exit(char *s);
int			ft_parse_map(char **argv, t_gmap *gmap);
int			ft_close(t_vars *vars);
int			ft_keys(int key, t_vars *vars);

#endif