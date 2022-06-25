/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solong_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 21:40:08 by clornel           #+#    #+#             */
/*   Updated: 2022/04/16 21:40:10 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_vars *vars)
{
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	ft_free_data(vars);
	exit (0);
}

int	ft_keys(int key, t_vars *vars)
{
	if (key == 53)
		ft_close(vars);
	if (key == W_KEY || key == S_KEY || key == D_KEY || key == A_KEY)
		ft_step(vars, key, vars->gmap);
	return (1);
}
