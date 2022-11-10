/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_repress(int keycode, t_data *data)
{
	if (keycode == KEY_W && data->button_f.w_stat == 1)
		data->button_f.w_stat = 0;
	else if (keycode == KEY_S && data->button_f.s_stat == 1)
		data->button_f.s_stat = 0;
	else if (keycode == KEY_D && data->button_f.d_stat == 1)
		data->button_f.d_stat = 0;
	else if (keycode == KEY_A && data->button_f.a_stat == 1)
		data->button_f.a_stat = 0;
	else if (keycode == KEY_RIGHT && data->button_f.right_stat == 1)
		data->button_f.right_stat = 0;
	else if (keycode == KEY_LEFT && data->button_f.left_stat == 1)
		data->button_f.left_stat = 0;
	return (1);
}

int	key_close(int keycode, t_data *data)
{
	(void)data;
	(void)keycode;
	printf("exit\n");
	exit (0);
}

void	ft_key_press(t_data *data)
{
	key_press_r(data);
	key_press_l(data);
}
