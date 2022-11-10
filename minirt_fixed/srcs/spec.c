/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double	spec_coeff(t_light light, t_inter inter)
{
	t_third		light_ray;
	t_third		reflectance_vector;
	t_third		back_view_ray;
	double		result;

	light_ray = substract(light.p0, inter.hit_point);
	normalize_vector(&light_ray);
	reflectance_vector = v3_add(light_ray,
			v3_multiply(v3_multiply(
					inter.hit_normal,
					dot_product(light_ray,
						inter.hit_normal)), -2));
	back_view_ray = substract(inter.hit_point, inter.sent.origin);
	normalize_vector(&back_view_ray);
	result = fmax(dot_product(reflectance_vector, back_view_ray), 0);
	result = pow(result, 10);
	return (result);
}

t_color2	specular(t_light light, t_inter inter)
{
	t_color2	specular;
	t_color2	highlight;
	double		metalness;
	double		coeff;

	metalness = 0.1;
	highlight.red = 1;
	highlight.green = 1;
	highlight.blue = 1;
	highlight = color2_coeff(highlight, (1 - metalness));
	specular = color2_add(
			color2_coeff(inter.closest_object->color, metalness),
			highlight);
	coeff = spec_coeff(light, inter);
	return (color2_coeff(specular, coeff));
}
