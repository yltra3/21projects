/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_plane	*new_plane(t_third p0, t_third normal)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	plane->p0 = p0;
	plane->normal = normal;
	return (plane);
}

t_third	get_plane_normal(t_plane plane)
{
	t_third	ret;

	ret = plane.normal;
	return (ret);
}

int	intersect_plane(t_ray ray, t_plane plane, double *t)
{
	double	denom;
	t_third	p0l0;

	denom = dot_product(plane.normal, ray.direction);
	if (fabs(denom) > 1e-6)
	{
		p0l0 = substract(plane.p0, ray.origin);
		*t = dot_product(p0l0, plane.normal) / denom;
		return (*t >= 0);
	}
	return (0);
}
