/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	not_wall(t_data *data, double row, double col)
{
	if (data->field[(int)row][(int)col] != '0')
		return (0);
	else if (data->field[(int)(row + 0.11)][(int)(col + 0.11)] != '0')
		return (0);
	else if (data->field[(int)(row + 0.11)][(int)(col)] != 48)
		return (0);
	else if (data->field[(int)(row)][(int)(col + 0.11)] != 48)
		return (0);
	else if (data->field[(int)(row - 0.11)][(int)(col - 0.11)] != 48)
		return (0);
	else if (data->field[(int)(row - 0.11)][(int)(col)] != 48)
		return (0);
	else if (data->field[(int)(row)][(int)(col - 0.11)] != 48)
		return (0);
	return (1);
}

void	change_plr_pos(t_data *data, double row, double col)
{
	if (not_wall(data, row, col))
	{
		data->movement.posx = row;
		data->movement.posy = col;
	}
}

void	move_forward(t_data *data, int flag, double *x, double *y)
{
	*x += flag * data->movement.dirx * (data->movement.movespeed);
	*y += flag * data->movement.diry * (data->movement.movespeed);
}

void	move_side(t_data *data, int flag, double *x, double *y)
{
	*y -= flag * data->movement.dirx * (data->movement.movespeed);
	*x += flag * data->movement.diry * (data->movement.movespeed);
}
