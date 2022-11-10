/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_color	int_to_color(int color)
{
	t_int_color	a;
	t_color		result;

	a.integer = color;
	result.red = a.comps[2];
	result.green = a.comps[1];
	result.blue = a.comps[0];
	return (result);
}

int	color_to_int(t_color color)
{
	t_int_color	a;

	a.comps[2] = color.red;
	a.comps[1] = color.green;
	a.comps[0] = color.blue;
	return (a.integer);
}
