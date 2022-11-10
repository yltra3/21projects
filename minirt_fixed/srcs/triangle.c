/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_triangle	*new_triangle(t_third a, t_third b, t_third c)
{
	t_triangle	*triangle;

	triangle = malloc(sizeof(t_triangle));
	triangle->a = a;
	triangle->b = b;
	triangle->c = c;
	return (triangle);
}

t_third	get_triangle_normal(t_triangle triangle)
{
	t_third	a;
	t_third	b;
	t_third	n;

	a = substract(triangle.b, triangle.a);
	b = substract(triangle.c, triangle.a);
	n = cross_product(a, b);
	normalize_vector(&n);
	return (n);
}

int	check_edges(t_triangle triangle, t_third p, t_third n)
{
	t_third	c;
	t_third	edge;
	t_third	vp;

	edge = substract(triangle.b, triangle.a);
	vp = substract(p, triangle.a);
	c = cross_product(edge, vp);
	if (dot_product(n, c) < 0)
		return (0);
	edge = substract(triangle.c, triangle.b);
	vp = substract(p, triangle.b);
	c = cross_product(edge, vp);
	if (dot_product(n, c) < 0)
		return (0);
	edge = substract(triangle.a, triangle.c);
	vp = substract(p, triangle.c);
	c = cross_product(edge, vp);
	if (dot_product(n, c) < 0)
		return (0);
	return (1);
}

int	intersect_triangle(t_ray ray, t_triangle triangle, double *t)
{
	t_third	a;
	t_third	b;
	t_third	n;
	double	angle;
	t_third	p;

	a = substract(triangle.b, triangle.a);
	b = substract(triangle.c, triangle.a);
	n = cross_product(a, b);
	normalize_vector(&n);
	angle = dot_product(n, ray.direction);
	if (fabs(angle) < 1e-6)
		return (0);
	*t = (dot_product(n, substract(triangle.a, ray.origin)) / angle);
	if (*t < 0)
		return (0);
	p = v3_add(ray.origin, v3_multiply(ray.direction, *t));
	return (check_edges(triangle, p, n));
}
