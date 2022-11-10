/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_my_mlx(t_data *data)
{
	data->my_mlx.mlx = mlx_init();
	if (data->my_mlx.mlx == NULL)
	{
		error_msg("mlx error");
		return (0);
	}
	data->my_mlx.win = mlx_new_window(data->my_mlx.mlx,
			data->flags.r.x, data->flags.r.y, "Our cubik");
	if (data->my_mlx.win == NULL)
		error_msg("");
	data->my_mlx.img = mlx_new_image(data->my_mlx.mlx,
			data->flags.r.x, data->flags.r.y);
	if (data->my_mlx.img == NULL)
		error_msg("mlx error");
	data->my_mlx.addr = mlx_get_data_addr(data->my_mlx.img,
			&data->my_mlx.bit_per_pixel,
			&data->my_mlx.line_length, &data->my_mlx.endian);
	init_buttom_struct(&data->button_f);
	init_plr(data);
	data->f = rgb(1, data->flags.f.r, data->flags.f.g, data->flags.f.b);
	data->c = rgb(1, data->flags.c.r, data->flags.c.g, data->flags.c.b);
	return (1);
}

void	go_render(t_print_data *game, t_data *data, int x)
{
	int	w;
	int	texy;

	w = 0;
	while (w < data->flags.r.y)
	{
		if (w >= game->drawstart && w <= game->drawend)
		{
			texy = (int)game->texpos
				& (data->images[game->numtext].sprites_height - 1);
			game->texpos += game->step;
			my_mlx_pixel_put(&data->my_mlx, x, w,
				data->images[game->numtext].data[texy
				* data->images[game->numtext].sprites_height + game->texx]);
		}
		else if (w < game->drawstart)
			my_mlx_pixel_put(&data->my_mlx, x, w, data->c);
		else if (w > game->drawend)
			my_mlx_pixel_put(&data->my_mlx, x, w, data->f);
		w++;
	}
}

int	show_must_go_on(t_data *data)
{
	t_print_data	game;
	int				x;

	x = 0;
	while (x < data->movement.w)
	{
		calc_1(&game, data, x);
		calc_2(&game, data);
		calc_3(&game, data);
		calc_4(&game, data);
		calc_5(&game, data);
		go_render(&game, data, x);
		x++;
	}
	display_mini_map(data);
	mlx_put_image_to_window(data->my_mlx.mlx,
		data->my_mlx.win, data->my_mlx.img, 0, 0);
	return (0);
}

int	give_me_graphics(t_data *data)
{
	if (init_my_mlx(data) == 0)
		return (0);
	init_img(data);
	init_mini_map(data);
	show_must_go_on(data);
	mlx_hook(data->my_mlx.win, 2, 1L << 2, key_press, data);
	mlx_hook(data->my_mlx.win, 3, 1L << 3, key_repress, data);
	mlx_hook(data->my_mlx.win, 17, 1L << 2, key_close, data);
	mlx_loop(data->my_mlx.mlx);
	return (1);
}
