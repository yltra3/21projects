/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_copy_line(char *line, char **way, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		(*way)[i] = line[i];
		i++;
	}
	(*way)[i] = '\0';
}

int	min(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

int	rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bit_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	numoftext(int side, int stepY, int stepX)
{
	if (side == 1)
	{
		if (stepY == -1)
			return (WE);
		else
			return (EA);
	}
	else
	{
		if (stepX == -1)
			return (NO);
		else
			return (SO);
	}
}
