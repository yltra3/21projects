/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_plr_ew(t_data *data, int i, int j)
{
	if (data->field[i][j] == 'E')
	{
		data->movement.dirx = 0;
		data->movement.diry = 1;
		data->movement.planex = 0.66;
		data->movement.planey = 0;
	}
	else if (data->field[i][j] == 'W')
	{
		data->movement.dirx = 0;
		data->movement.diry = -1.0;
		data->movement.planex = -0.66;
		data->movement.planey = 0;
	}
}

void	init_plr_ns(t_data *data, int i, int j)
{
	if (data->field[i][j] == 'N')
	{
		data->movement.dirx = -1.0;
		data->movement.diry = 0;
		data->movement.planex = 0;
		data->movement.planey = 0.66;
	}
	else if (data->field[i][j] == 'S')
	{
		data->movement.dirx = 1.0;
		data->movement.diry = 0;
		data->movement.planex = 0;
		data->movement.planey = -0.66;
	}
	else
		init_plr_ew(data, i, j);
}

void	init_plr(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->line_count)
	{
		j = 0;
		while (j < data->column_count)
		{
			if (data->field[i][j] == 'E' || data->field[i][j] == 'N' || \
				data->field[i][j] == 'W' || data->field[i][j] == 'S')
			{
				data->movement.posx = i + 0.5;
				data->movement.posy = j + 0.5;
				init_plr_ns(data, i, j);
			}
			j++;
		}
		i++;
	}
	data->movement.w = data->flags.r.x;
	data->movement.h = data->flags.r.y;
	data->movement.movespeed = 0.055;
	data->movement.rotspeed = 0.035;
}
