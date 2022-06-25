/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controllers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:37:03 by clornel           #+#    #+#             */
/*   Updated: 2022/04/16 21:37:51 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_change_pos(t_vars *vars, size_t *pos, void *img, int fl)
{
	vars->gmap->field[vars->p_y][vars->p_x] = NONE;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->none,
		vars->p_x * PIC_SIZE, vars->p_y * PIC_SIZE);
	if (fl == 1)
		*pos = *pos + 1;
	else if (fl == -1)
		*pos = *pos - 1;
	if (vars->gmap->field[vars->p_y][vars->p_x] == ENEMY)
		exit(printf("Game Over, you lose =(\n"));
	vars->gmap->field[vars->p_y][vars->p_x] = HERO;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->none,
		vars->p_x * PIC_SIZE, vars->p_y * PIC_SIZE);
	mlx_put_image_to_window(vars->mlx, vars->win, img,
		vars->p_x * PIC_SIZE, vars->p_y * PIC_SIZE);
}

static int	ft_check_new_pos(t_gmap *gmap, size_t x, size_t y)
{
	if (gmap->field[y][x] == WALL)
		return (1);
	if (gmap->field[y][x] == EXIT && gmap->earn_coins >= gmap->coin)
	{
		gmap->moves += 1;
		printf("Movements done %zu\nYou WIN!!!\n", gmap->moves);
		ft_close(gmap->data);
	}
	if (gmap->field[y][x] == EXIT && gmap->earn_coins != gmap->coin)
		return (1);
	if (gmap->field[y][x] == COIN)
		gmap->earn_coins += 1;
	gmap->moves += 1;
	printf("Movements done %zu\n", gmap->moves);
	ft_info_draw(gmap->data, gmap);
	return (0);
}

void	ft_info_draw(t_vars *vars, t_gmap *gmap)
{
	char	*msg;

	if (!vars->bonus)
		return ;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->empty,
		PIC_SIZE / 3, PIC_SIZE / 16);
	msg = ft_strjoin_m("MOVES: ", ft_itoa(gmap->moves), 2);
	mlx_string_put(vars->mlx, vars->win, PIC_SIZE / 2, PIC_SIZE / 4,
		0xFFAAAA, msg);
	free(msg);
	msg = ft_strjoin_m("COINS: ", ft_itoa(gmap->earn_coins), 2);
	mlx_string_put(vars->mlx, vars->win, PIC_SIZE / 2, PIC_SIZE / 2,
		0xFFAAAA, msg);
	free(msg);
}

void	ft_step(t_vars *vars, int key, t_gmap *gmap)
{
	if (key == W_KEY && vars->p_y != 0
		&& !ft_check_new_pos(gmap, vars->p_x, vars->p_y - 1))
		ft_change_pos(vars, &vars->p_y, vars->img->hero_up, -1);
	if (key == S_KEY && vars->p_y != gmap->height - 1
		&& !ft_check_new_pos(gmap, vars->p_x, vars->p_y + 1))
		ft_change_pos(vars, &vars->p_y, vars->img->hero, 1);
	if (key == A_KEY && vars->p_x != 0
		&& !ft_check_new_pos(gmap, vars->p_x - 1, vars->p_y))
		ft_change_pos(vars, &vars->p_x, vars->img->hero_l, -1);
	if (key == D_KEY && vars->p_x != gmap->width - 1
		&& !ft_check_new_pos(gmap, vars->p_x + 1, vars->p_y))
		ft_change_pos(vars, &vars->p_x, vars->img->hero_r, 1);
}
