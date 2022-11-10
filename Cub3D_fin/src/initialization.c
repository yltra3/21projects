/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_coord(t_coord *coord)
{
	coord->x = 0;
	coord->y = 0;
}

void	init_color(t_color *color)
{
	color->r = 0;
	color->g = 0;
	color->b = 0;
}

void	init_flag(t_flags *flags)
{
	flags->count_line = 0;
	flags->flag_no = 0;
	flags->no = -1;
	flags->flag_so = 0;
	flags->so = -1;
	flags->flag_we = 0;
	flags->we = -1;
	flags->flag_ea = 0;
	flags->ea = -1;
	flags->flag_f = 0;
	init_color(&flags->f);
	flags->flag_c = 0;
	init_color(&flags->c);
	flags->flag_r = 0;
	init_coord(&flags->r);
	flags->r_min.x = 200;
	flags->r_min.y = 200;
	flags->r_max.x = 2000;
	flags->r_max.y = 2000;
}

void	init_data(t_data *data)
{
	data->fd = -1;
	data->line_count = 0;
	data->line_max = 50;
	data->column_count = 0;
	data->column_max = 50;
	init_flag(&data->flags);
}
