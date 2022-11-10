/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_1(t_print_data *game, t_data *data, int x)
{
	game->camerax = 2 * x / (double)data->movement.w - 1;
	game->raydirx = data->movement.dirx + data->movement.planex * game->camerax;
	game->raydiry = data->movement.diry + data->movement.planey * game->camerax;
	game->mapx = (int)(data->movement.posx);
	game->mapy = (int)(data->movement.posy);
	game->deltadistx = fabs(1 / game->raydirx);
	game->deltadisty = fabs(1 / game->raydiry);
	game->hit = 0;
}

void	calc_2(t_print_data *game, t_data *data)
{
	if (game->raydirx < 0)
	{
		game->stepx = -1;
		game->sidedistx = (data->movement.posx - game->mapx) * game->deltadistx;
	}
	else
	{
		game->stepx = 1;
		game->sidedistx = (game->mapx + 1.0 - data->movement.posx)
			* game->deltadistx;
	}
	if (game->raydiry < 0)
	{
		game->stepy = -1;
		game->sidedisty = (data->movement.posy - game->mapy) * game->deltadisty;
	}
	else
	{
		game->stepy = 1;
		game->sidedisty = (game->mapy + 1.0 - data->movement.posy)
			* game->deltadisty;
	}
}

void	calc_3(t_print_data *game, t_data *data)
{
	while (game->hit == 0)
	{
		if (game->sidedistx < game->sidedisty)
		{
			game->sidedistx += game->deltadistx;
			game->mapx += game->stepx;
			game->side = 0;
		}
		else
		{
			game->sidedisty += game->deltadisty;
			game->mapy += game->stepy;
			game->side = 1;
		}
		if (data->field[game->mapx][game->mapy] == '1')
			game->hit = 1;
	}
}

void	calc_4(t_print_data *game, t_data *data)
{
	if (game->side == 0)
		game->perpwalldist = (game->mapx - data->movement.posx
				+ (1 - game->stepx) / 2) / game->raydirx;
	else
		game->perpwalldist = (game->mapy - data->movement.posy
				+ (1 - game->stepy) / 2) / game->raydiry;
	game->lineheight = (int)(data->movement.h / game->perpwalldist);
	game->drawstart = -game->lineheight / 2 + data->movement.h / 2;
	if (game->drawstart < 0)
		game->drawstart = 0;
	game->drawend = game->lineheight / 2 + data->movement.h / 2;
	if (game->drawend >= data->movement.h)
		game->drawend = data->movement.h - 1;
	if (game->side == 0)
		game->wallx = data->movement.posy + game->perpwalldist * game->raydiry;
	else
		game->wallx = data->movement.posx + game->perpwalldist * game->raydirx;
}

void	calc_5(t_print_data *game, t_data *data)
{
	game->wallx = game->wallx - (int)(game->wallx);
	game->numtext = numoftext(game->side, game->stepy, game->stepx);
	game->texx = (int)(game->wallx * (double)
			(data->images[game->numtext].sprites_width));
	if (game->side == 0 && game->raydirx > 0)
		game->texx = data->images[game->numtext].sprites_width - game->texx - 1;
	if (game->side == 1 && game->raydiry < 0)
		game->texx = data->images[game->numtext].sprites_width - game->texx - 1;
	game->step = 1.0 * data->images[0].sprites_height / game->lineheight;
	game->texpos = (game->drawstart - data->movement.h / 2 + \
	game->lineheight / 2) * game->step;
}
