/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	normalize_vector(t_third *vector)
{
	double	len;

	len = sqrt(vector->x * vector->x + vector->y
			* vector->y + vector->z * vector->z);
	vector->x /= len;
	vector->y /= len;
	vector->z /= len;
}

t_third	create_v3(double x, double y, double z)
{
	t_third	result;

	result.x = x;
	result.y = y;
	result.z = z;
	return (result);
}

double	vector_len(t_third vector)
{
	return (sqrt(vector.x * vector.x + vector.y * vector.y
			+vector.z * vector.z));
}

double	dot_product(t_third a, t_third b)
{
	double	sum;

	sum = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	return (sum);
}
