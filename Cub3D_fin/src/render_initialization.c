/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_initialization.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_buttom_struct(t_button_flag *button_f)
{
	button_f->w_stat = 0;
	button_f->s_stat = 0;
	button_f->d_stat = 0;
	button_f->a_stat = 0;
	button_f->right_stat = 0;
	button_f->left_stat = 0;
}

void	init_mini_map(t_data *data)
{
	data->mini_map.color_wall = 8421504;
	data->mini_map.color_empty = 16777215;
	data->mini_map.color_player = 16711680;
	data->mini_map.size = 4;
	data->mini_map.mode = 2;
}

void	init_img_help(t_data *data)
{
	data->images[2].wall = mlx_xpm_file_to_image(data->my_mlx.mlx,
			data->flags.w_side, &data->images[2].sprites_width,
			&data->images[2].sprites_height);
	if (data->images[2].wall == NULL)
		error_msg("xpm error");
	data->images[2].data = (int *)mlx_get_data_addr(data->images[2].wall,
			&data->images[2].bpp,
			&data->images[2].size_line, &data->images[2].endlan);
	data->images[3].wall = mlx_xpm_file_to_image(data->my_mlx.mlx, \
		data->flags.e_side, &data->images[3].sprites_width, \
		&data->images[3].sprites_height);
	if (data->images[3].wall == NULL)
		error_msg("xpm error");
	data->images[3].data = (int *)mlx_get_data_addr(data->images[3].wall,
			&data->images[3].bpp,
			&data->images[3].size_line, &data->images[3].endlan);
}

void	init_img(t_data *data)
{
	data->field[(int)data->movement.posx][(int)data->movement.posy] = '0';
	data->images = malloc(sizeof(t_images) * 4);
	if (data->images == NULL)
		error_msg("malloc error");
	data->images[0].wall = mlx_xpm_file_to_image(data->my_mlx.mlx, \
		data->flags.n_side, &data->images[0].sprites_width, \
		&data->images[0].sprites_height);
	if (data->images[0].wall == NULL)
		error_msg("xpm error");
	data->images[0].data = (int *)mlx_get_data_addr(data->images[0].wall, \
		&data->images[0].bpp,
			&data->images[0].size_line, &data->images[0].endlan);
	data->images[1].wall = mlx_xpm_file_to_image(data->my_mlx.mlx, \
		data->flags.s_side, &data->images[1].sprites_width, \
		&data->images[1].sprites_height);
	if (data->images[1].wall == NULL)
		error_msg("xpm error");
	data->images[1].data = (int *)mlx_get_data_addr(data->images[1].wall, \
		&data->images[1].bpp, &data->images[1].size_line,
			&data->images[1].endlan);
	init_img_help(data);
}
