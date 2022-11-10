/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_inter	new_inter(t_third hit_point, t_third hit_normal,
					t_object *closest_object, t_ray sent)
{
	t_inter	inter;

	inter.hit_point = hit_point;
	inter.hit_normal = hit_normal;
	inter.closest_object = closest_object;
	inter.sent = sent;
	return (inter);
}

int	intersect(t_ray sent, t_object *object, double *t)
{
	if (object->type == SPHERE)
		return (intersect_sphere(sent, *(t_sphere *)object->ptr, t));
	else if (object->type == PLANE)
		return (intersect_plane(sent, *(t_plane *)object->ptr, t));
	else if (object->type == TRIANGLE)
		return (intersect_triangle(sent, *(t_triangle *)object->ptr, t));
	else if (object->type == SQUARE)
		return (intersect_square(sent, *(t_square *)object->ptr, t));
	else
		return (intersect_cylinder(sent, *(t_cylinder *)object->ptr, t));
}

int	intersect_with_all(t_list *objects, t_ray sent,
						t_object **closest_object, double *t_min)
{
	t_list		*runner;
	t_object	*this_object;
	double		t;

	*closest_object = NULL;
	runner = objects;
	*t_min = HUGE_VAL;
	while (runner != NULL)
	{
		this_object = runner->content;
		if (intersect(sent, this_object, &t))
		{
			if (t < *t_min)
			{
				*closest_object = this_object;
				*t_min = t;
			}
		}
		runner = runner->next;
	}
	if (*closest_object != NULL)
		return (1);
	else
		return (0);
}
