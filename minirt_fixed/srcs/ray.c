/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_ray	create_ray(t_third origin, t_third direction)
{
	t_ray	result;

	result.origin = origin;
	result.direction = direction;
	return (result);
}

t_camera	pick_camera(t_scene *scene)
{
	t_list	*runner;
	int		i;

	i = 0;
	runner = scene->cameras;
	while (i < scene->selected_camera && runner != NULL)
	{
		i++;
		runner = runner->next;
	}
	return (*(t_camera *)runner->content);
}

t_third	get_direction(int x, int y, t_scene *scene, t_camera camera)
{
	double	fov_coeff;
	double	aspect_ratio;
	double	p_x;
	double	p_y;

	fov_coeff = tan((double)camera.fov / 2 * M_PI / 180);
	aspect_ratio = (double)scene->width / (double)scene->height;
	p_x = (2 * (x + 0.5) / (double)scene->width - 1) * aspect_ratio * fov_coeff;
	p_y = (1 - 2 * (y + 0.5) / (double)scene->height) * fov_coeff;
	return (create_v3(p_x, p_y, 1));
}

t_ray	ray_to_pixel(int x, int y, t_scene *scene)
{
	t_third		origin;
	t_third		direction;
	t_matrix	c2w;
	t_camera	camera;

	camera = pick_camera(scene);
	c2w = direction_view(camera.origin, camera.direction);
	origin = mult_matrix(create_v3(0, 0, 0), c2w);
	direction = get_direction(x, y, scene, camera);
	direction = mult_matrix(direction, c2w);
	direction = substract(direction, origin);
	normalize_vector(&direction);
	return (create_ray(origin, direction));
}
