/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cr_buf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_pixel	**create_buffer(int height, int width)
{
	t_pixel	**result;
	int		i;

	i = 0;
	result = malloc(sizeof(t_pixel *) * height);
	while (i < height)
	{
		result[i] = malloc(sizeof(t_pixel) * width);
		i++;
	}
	return (result);
}

void	free_buffer(t_pixel **buffer, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
}

t_pixel	pix_from_int(int color)
{
	t_color	tc;
	t_pixel	result;

	tc = int_to_color(color);
	result.b = tc.blue;
	result.g = tc.green;
	result.r = tc.red;
	return (result);
}
