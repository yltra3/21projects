/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_border_help(t_data data, int i, int j)
{
	if (data.field[i + 1][j] == ' ' || data.field[i - 1][j] == ' '
		|| data.field[i][j + 1] == ' ' || data.field[i][j - 1] == ' ' )
	{
		error_msg("Wrong map! Sorry!");
		return (0);
	}
	if (data.field[i + 1][j] == '!' || data.field[i - 1][j] == '!'
		|| data.field[i][j + 1] == '!' || data.field[i][j - 1] == '!' )
		error_msg("Wrong map! Sorry!");
	if (data.field[i + 1][j + 1] == ' ' || data.field[i - 1][j + 1] == ' '
		|| data.field[i - 1][j - 1] == ' ' || data.field[i + 1][j - 1] == ' ' )
		error_msg("Wrong map! Sorry!");
	if (data.field[i + 1][j + 1] == '!' || data.field[i - 1][j + 1] == '!'
		|| data.field[i - 1][j - 1] == '!' || data.field[i + 1][j - 1] == '!' )
		error_msg("Wrong map! Sorry!");
	return (1);
}

int	check_map_border(t_data data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data.line_count)
	{
		j = 0;
		while (j < data.column_count)
		{
			if (check_symbol_in_map(data.field[i][j]) >= 2)
			{
				if (check_border_help(data, i, j) == 0)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
