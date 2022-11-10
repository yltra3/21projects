/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    key.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_press_l(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	if (data->button_f.left_stat == 1 && data->button_f.right_stat == 0)
	{
		olddirx = data->movement.dirx;
		data->movement.dirx = data->movement.dirx * cos(data->movement.rotspeed)
			- data->movement.diry * sin(data->movement.rotspeed);
		data->movement.diry = olddirx * sin(data->movement.rotspeed)
			+ data->movement.diry * cos(data->movement.rotspeed);
		oldplanex = data->movement.planex;
		data->movement.planex = data->movement.planex
			* cos(data->movement.rotspeed)
			- data->movement.planey * sin(data->movement.rotspeed);
		data->movement.planey = oldplanex * sin(data->movement.rotspeed)
			+ data->movement.planey * cos(data->movement.rotspeed);
	}
}

void	key_press_r(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	if (data->button_f.right_stat == 1 && data->button_f.left_stat == 0)
	{
		olddirx = data->movement.dirx;
		data->movement.dirx = data->movement.dirx
			* cos(-data->movement.rotspeed)
			- data->movement.diry * sin(-data->movement.rotspeed);
		data->movement.diry = olddirx * sin(-data->movement.rotspeed)
			+ data->movement.diry * cos(-data->movement.rotspeed);
		oldplanex = data->movement.planex;
		data->movement.planex = data->movement.planex
			* cos(-data->movement.rotspeed)
			- data->movement.planey * sin(-data->movement.rotspeed);
		data->movement.planey = oldplanex * sin(-data->movement.rotspeed)
			+ data->movement.planey * cos(-data->movement.rotspeed);
	}
}

void	key_minimap(int keycode, t_data *data)
{
	if (keycode == 46)
	{
		if (data->mini_map.size == 4)
			data->mini_map.size = 0;
		else
			data->mini_map.size++;
	}
	else if (keycode == 3)
	{
		if (data->mini_map.mode == 2)
			data->mini_map.mode = 0;
		else
			data->mini_map.mode++;
	}
}

void	key_press_take(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		printf("Exit\n");
		mlx_destroy_window(data->my_mlx.mlx, data->my_mlx.win);
		exit (0);
	}
	else if (keycode == KEY_W && data->button_f.w_stat == 0)
		data->button_f.w_stat = 1;
	else if (keycode == KEY_S && data->button_f.s_stat == 0)
		data->button_f.s_stat = 1;
	else if (keycode == KEY_D && data->button_f.d_stat == 0)
		data->button_f.d_stat = 1;
	else if (keycode == KEY_A && data->button_f.a_stat == 0)
		data->button_f.a_stat = 1;
	else if (keycode == KEY_RIGHT && data->button_f.right_stat == 0)
		data->button_f.right_stat = 1;
	else if (keycode == KEY_LEFT && data->button_f.left_stat == 0)
		data->button_f.left_stat = 1;
	else
		key_minimap(keycode, data);
}

int	key_press(int keycode, t_data *data)
{
	double	testposx;
	double	testposy;

	mlx_destroy_image(data->my_mlx.mlx, data->my_mlx.img);
	data->my_mlx.img = mlx_new_image(data->my_mlx.mlx,
			data->flags.r.x, data->flags.r.y);
	if (data->my_mlx.img == NULL)
		error_msg("mlx error");
	data->my_mlx.addr = mlx_get_data_addr(data->my_mlx.img, &data-> \
		my_mlx.bit_per_pixel, &data->my_mlx.line_length, &data->my_mlx.endian);
	testposx = data->movement.posx;
	testposy = data->movement.posy;
	key_press_take(keycode, data);
	if (data->button_f.w_stat == 1 && data->button_f.s_stat == 0)
		move_forward(data, 1, &testposx, &testposy);
	else if (data->button_f.s_stat == 1 && data->button_f.w_stat == 0)
		move_forward(data, -1, &testposx, &testposy);
	if (data->button_f.d_stat == 1 && data->button_f.a_stat == 0)
		move_side(data, 1, &testposx, &testposy);
	else if (data->button_f.a_stat == 1 && data->button_f.d_stat == 0)
		move_side(data, -1, &testposx, &testposy);
	ft_key_press(data);
	change_plr_pos(data, testposx, testposy);
	show_must_go_on(data);
	return (1);
}
