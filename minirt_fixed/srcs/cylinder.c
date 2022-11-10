/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_cylinder	*new_cylinder(t_third p, t_third normal,
							double radius, double height)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	cylinder->p = p;
	cylinder->normal = normal;
	cylinder->radius = radius;
	cylinder->height = height;
	return (cylinder);
}

t_third	get_cylinder_normal(t_third point, t_cylinder cylinder)
{
	t_third	ctp;
	t_third	normal;

	ctp = substract(point, cylinder.p);
	normal = substract(ctp, v3_multiply(cylinder.normal,
				dot_product(cylinder.normal, ctp)));
	normalize_vector(&normal);
	return (normal);
}

void	check_t(double *t, t_cylinder cylinder, t_ray ray)
{
	t_third	q;
	t_third	p2;

	p2 = v3_add(cylinder.p, v3_multiply(cylinder.normal,
				cylinder.height));
	q = v3_add(ray.origin, v3_multiply(ray.direction, *t));
	if (dot_product(cylinder.normal, substract(q,
				cylinder.p)) <= 0)
		*t = -1;
	if (dot_product(cylinder.normal, substract(q, p2)) >= 0)
		*t = -1;
}

int	cyl_get_roots(double *t0, double *t1, t_cylinder cylinder, t_ray ray)
{
	t_third	a_sqrt;
	t_third	right;
	double	a;
	double	b;
	double	c;

	a_sqrt = substract(ray.direction, v3_multiply(cylinder.normal,
				dot_product(ray.direction, cylinder.normal)));
	a = dot_product(a_sqrt, a_sqrt);
	right = substract(substract(ray.origin, cylinder.p),
			v3_multiply(cylinder.normal,
				dot_product(substract(ray.origin, cylinder.p),
					cylinder.normal)));
	b = 2 * dot_product(a_sqrt, right);
	c = dot_product(right, right) - (cylinder.radius * cylinder.radius);
	if (!solve_quadratic(new_qparams(a, b, c), t0, t1))
		return (0);
	return (1);
}

int	intersect_cylinder(t_ray ray, t_cylinder cylinder, double *t)
{
	double	t0;
	double	t1;

	if (!cyl_get_roots(&t0, &t1, cylinder, ray))
		return (0);
	if (t0 > 0)
		check_t(&t0, cylinder, ray);
	if (t1 > 0)
		check_t(&t1, cylinder, ray);
	if (t0 < 0 && t1 < 0)
		return (0);
	inseq_cyl(t, &t0, &t1);
	return (1);
}
