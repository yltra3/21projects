/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_third	mult_matrix(t_third p, t_matrix m)
{
	t_third	res;

	res.x = p.x * m.d[0][0] + p.y * m.d[1][0] + p.z * m.d[2][0] + m.d[3][0];
	res.y = p.x * m.d[0][1] + p.y * m.d[1][1] + p.z * m.d[2][1] + m.d[3][1];
	res.z = p.x * m.d[0][2] + p.y * m.d[1][2] + p.z * m.d[2][2] + m.d[3][2];
	return (res);
}

t_matrix	direction_view(t_third origin, t_third cam_vector)
{
	t_matrix	m;
	t_third		random;
	t_third		right;
	t_third		up;

	random = create_v3(0, 1, 0);
	normalize_vector(&random);
	right = cross_product(random, cam_vector);
	normalize_vector(&right);
	up = cross_product(cam_vector, right);
	normalize_vector(&up);
	m.d[0][0] = right.x;
	m.d[0][1] = right.y;
	m.d[0][2] = right.z;
	m.d[1][0] = up.x;
	m.d[1][1] = up.y;
	m.d[1][2] = up.z;
	m.d[2][0] = cam_vector.x;
	m.d[2][1] = cam_vector.y;
	m.d[2][2] = cam_vector.z;
	m.d[3][0] = origin.x;
	m.d[3][1] = origin.y;
	m.d[3][2] = origin.z;
	return (m);
}

int	main(int ac, char **av)
{
	if (ac < 2 || ac > 3)
		return (42);
	else
	{
		if (ac == 2)
			mini_rt(av[1], 0);
		else if (ft_strncmp(av[2], "--save", ft_strlen(av[2])) == 0)
			mini_rt(av[1], 1);
	}
	return (0);
}
