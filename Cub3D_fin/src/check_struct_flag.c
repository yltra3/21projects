/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_struct_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_all_flags(t_flags flags)
{
	if (flags.flag_r == 1
		&& flags.flag_no == 1
		&& flags.flag_so == 1
		&& flags.flag_we == 1
		&& flags.flag_ea == 1
		&& flags.flag_f == 1
		&& flags.flag_c == 1)
		return (1);
	return (0);
}

int	check_double_flags(t_flags flags)
{
	if (flags.flag_r > 1
		|| flags.flag_no > 1 || flags.flag_so > 1
		|| flags.flag_we > 1 || flags.flag_ea > 1
		|| flags.flag_f > 1 || flags.flag_c > 1)
		error_msg("Have a double config!");
	return (1);
}
