/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:53:07 by clornel           #+#    #+#             */
/*   Updated: 2022/04/13 20:53:09 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_err_exit(char *s)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_putstr(s);
	exit(1);
}

void	ft_get_xpm(void *mlx, void **img, char *file)
{
	int	size[2];

	*img = mlx_xpm_file_to_image(mlx, file, &size[0], &size[1]);
	if (!*img)
		ft_err_exit(ft_strjoin("xpm file read error", file));
	if (size[0] != PIC_SIZE || size[0] != size[1])
		ft_err_exit(ft_strjoin("xpm size error", file));
}

void	ft_init_structs(t_vars *vars)
{
	t_img	*img;

	vars->fl = 0;
	vars->image = NULL;
	img = malloc(sizeof(t_img));
	if (!img)
		ft_err_exit("malloc error");
	ft_get_xpm(vars->mlx, &img->hero, "./xpm/hero.xpm");
	ft_get_xpm(vars->mlx, &img->hero_up, "./xpm/up.xpm");
	ft_get_xpm(vars->mlx, &img->hero_l, "./xpm/left.xpm");
	ft_get_xpm(vars->mlx, &img->hero_r, "./xpm/right.xpm");
	ft_get_xpm(vars->mlx, &img->wall, "./xpm/wall.xpm");
	ft_get_xpm(vars->mlx, &img->none, "./xpm/none.xpm");
	ft_get_xpm(vars->mlx, &img->exit, "./xpm/exit.xpm");
	ft_get_xpm(vars->mlx, &img->coin, "./xpm/coin.xpm");
	ft_get_xpm(vars->mlx, &img->enemy[0], "./xpm/enemy0.xpm");
	ft_get_xpm(vars->mlx, &img->enemy[1], "./xpm/enemy1.xpm");
	img->empty = mlx_new_image(vars->mlx, PIC_SIZE * 1.66, PIC_SIZE / 2);
	vars->img = img;
}

void	ft_free_data(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->gmap && vars->gmap->field)
	{
		while (vars->gmap->field[i])
		{
			free(vars->gmap->field[i]);
			i++;
		}
		free(vars->gmap->field);
	}
	if (vars->img)
		free(vars->img);
}

int	main(int argc, char **argv)
{
	t_gmap	gmap;
	t_vars	vars;

	if (argc != 2)
		ft_err_exit("arguments count issue");
	gmap.data = &vars;
	vars.gmap = &gmap;
	vars.bonus = 0;
	if (!ft_parse_map(argv, &gmap))
		ft_err_exit("map issue");
	vars.mlx = mlx_init();
	if (!vars.mlx)
		ft_err_exit("can't initialize mlx");
	vars.res_x = gmap.width * PIC_SIZE;
	vars.res_y = gmap.height * PIC_SIZE;
	vars.win = mlx_new_window(vars.mlx, vars.res_x, vars.res_y, "so_long");
	if (!vars.win)
		ft_err_exit("can't create game window");
	ft_init_structs(&vars);
	ft_linku_starto(&vars);
	ft_free_data(&vars);
	return (0);
}
