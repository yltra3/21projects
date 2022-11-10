/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_square	*new_square(t_third center, t_third normal, double length)
{
	t_square	*square;

	square = malloc(sizeof(t_square));
	square->center = center;
	square->normal = normal;
	square->length = length;
	return (square);
}

t_third	get_square_normal(t_square square)
{
	t_third	ret;

	ret = square.normal;
	return (ret);
}

int	intersect_square(t_ray ray, t_square square, double *t)
{
	double	denom;
	t_third	hit_point;
	t_third	p0l0;

	denom = dot_product(square.normal, ray.direction);
	if (fabs(denom) > 1e-6)
	{
		p0l0 = substract(square.center, ray.origin);
		*t = dot_product(p0l0, square.normal) / denom;
		hit_point = v3_add(ray.origin, v3_multiply(ray.direction, *t));
		if (*t >= 0)
		{
			if (fabs(hit_point.x - square.center.x) > (square.length / 2))
				return (0);
			if (fabs(hit_point.y - square.center.y) > (square.length / 2))
				return (0);
			if (fabs(hit_point.z - square.center.z) > (square.length / 2))
				return (0);
			else
				return (1);
		}
		else
			return (0);
	}
	return (0);
}
