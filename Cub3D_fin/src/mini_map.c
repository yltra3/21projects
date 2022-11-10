/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	square_print(t_data *data, t_coord start, t_coord size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size.x)
	{
		j = 0;
		while (j < size.y)
		{
			my_mlx_pixel_put(&data->my_mlx, start.x + i, start.y + j, color);
			j++;
		}
		i++;
	}
}

void	stop_mini_map(	t_data *data, t_coord coord_player, \
								t_coord start, t_coord size)
{
	if (data->mini_map.mode == 0)
	{
		if (data->field[coord_player.x][coord_player.y] == '1')
			square_print(data, start, size, data->mini_map.color_wall);
		else if (data->field[coord_player.x][coord_player.y] == '0')
			square_print(data, start, size, data->mini_map.color_empty);
	}
	else if (data->mini_map.mode == 1)
	{
		if (data->field[coord_player.x][coord_player.y] == '1')
			square_print(data, start, size, data->mini_map.color_wall);
	}
	else if (data->mini_map.mode == 2)
	{
		if (data->field[coord_player.x][coord_player.y] == '0')
			square_print(data, start, size, data->mini_map.color_empty);
	}
}

void	mini_map_plr(t_data *data, int cell)
{
	t_coord	start;
	t_coord	size;

	start.x = (data->movement.posy - 0.5) * cell + cell / 4;
	start.y = (data->movement.posx - 0.5) * cell + cell / 4;
	size.x = cell / 2;
	size.y = cell / 2;
	square_print(data, start, size, data->mini_map.color_player);
}

void	coord(t_coord *a, int a_x, int a_y)
{
	a->x = a_x;
	a->y = a_y;
}

void	display_mini_map(t_data *data)
{
	t_coord	start;
	t_coord	size;
	t_coord	coord_player;
	int		i;
	int		j;

	i = -1;
	if (data->mini_map.size == 0)
		return ;
	data->mini_map.cell = min(data->flags.r.x / data->column_count
			/ data->mini_map.size,
			data->flags.r.y / data->line_count / data->mini_map.size);
	coord(&size, data->mini_map.cell, data->mini_map.cell);
	while (++i < data->line_count)
	{
		j = 0;
		while (j < data->column_count)
		{
			coord(&start, j * data->mini_map.cell, i * data->mini_map.cell);
			coord(&coord_player, i, j);
			stop_mini_map(data, coord_player, start, size);
			j++;
		}
	}
	mini_map_plr(data, data->mini_map.cell);
}
