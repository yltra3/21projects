/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linku_starto.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:24:59 by clornel           #+#    #+#             */
/*   Updated: 2022/04/16 21:25:00 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_animations(t_vars *vars)
{
	int	i;
	int	j;

	vars->timer++;
	if (vars->timer % 10)
	{
		i = -1;
		while (vars->gmap->field[++i])
		{
			j = -1;
			while (vars->gmap->field[i][++j])
			{
				if (vars->gmap->field[i][j] == ENEMY)
				{
					mlx_put_image_to_window(vars->mlx, vars->win,
						vars->img->none, j * PIC_SIZE, i * PIC_SIZE);
					mlx_put_image_to_window(vars->mlx, vars->win,
						vars->img->enemy[vars->timer / 36 % 2],
						j * PIC_SIZE, i * PIC_SIZE);
				}
			}
		}
	}
	mlx_do_sync(vars->mlx);
	return (0);
}

static void	ft_img_put(size_t x, size_t y, t_vars *vars, t_img *img)
{
	if (vars->gmap->field[y][x] != '1' && vars->gmap->field[y][x] != ENEMY)
		mlx_put_image_to_window(vars->mlx, vars->win, img->none,
			x * PIC_SIZE, y * PIC_SIZE);
	if (vars->gmap->field[y][x] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, img->wall,
			x * PIC_SIZE, y * PIC_SIZE);
	else if (vars->gmap->field[y][x] == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, img->hero,
			x * PIC_SIZE, y * PIC_SIZE);
		vars->p_x = x;
		vars->p_y = y;
	}
	else if (vars->gmap->field[y][x] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, img->exit,
			x * PIC_SIZE, y * PIC_SIZE);
	else if (vars->gmap->field[y][x] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, img->coin,
			x * PIC_SIZE, y * PIC_SIZE);
	else if (vars->gmap->field[y][x] == 'K')
		mlx_loop_hook(vars->mlx, ft_animations, vars);
}

static void	ft_map_draw(t_vars *vars)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < vars->gmap->height)
	{
		x = 0;
		while (x < vars->gmap->width)
		{
			ft_img_put(x, y, vars, vars->img);
			x++;
		}
		y++;
	}
	ft_info_draw(vars, vars->gmap);
}

void	ft_linku_starto(t_vars *vars)
{
	ft_map_draw(vars);
	mlx_hook(vars->win, 2, 0, ft_keys, vars);
	mlx_hook(vars->win, 17, 0l, ft_close, vars);
	write(1, "Movements done 0\n", 18);
	mlx_loop(vars->mlx);
}
