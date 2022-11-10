/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_checker_help.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	skip_symbols(char *str, int *i, char symbol)
{
	while (str[*i] == symbol)
		*i = *i + 1;
}

int	check_line_r_x(t_flags *flags, char *line, int *i)
{
	while (line[*i])
	{
		if (line[*i] >= '0' && line[*i] <= '9')
		{
			flags->r.x = flags->r.x * 10 + (line[*i] - 48);
			if (flags->r.x > flags->r_max.x)
			{
				error_msg("large flags");
				return (0);
			}
		}
		else if (line[*i] == ' ')
			break ;
		else
			error_msg("Not digit");
		*i = *i + 1;
	}
	return (1);
}

int	check_line_r_y(t_flags *flags, char *line, int *i)
{
	while (line[*i])
	{
		if (line[*i] >= '0' && line[*i] <= '9')
		{
			flags->r.y = flags->r.y * 10 + (line[*i] - 48);
			if (flags->r.y > flags->r_max.y)
			{
				error_msg("large flag");
				return (0);
			}
		}
		else if (line[*i] == ' ')
			break ;
		else
			error_msg("not digit");
		*i = *i + 1;
	}
	return (1);
}

int	check_line_r(t_flags *flags, char *line)
{
	int	i;

	i = 2;
	flags->flag_r++;
	while (line[i] == ' ')
		i++;
	if (check_line_r_x(flags, line, &i) == 0)
		return (0);
	if (line[i] != ' ')
		error_msg("No space");
	i++;
	skip_symbols(line, &i, ' ');
	if (check_line_r_y(flags, line, &i) == 0)
		return (0);
	if (flags->r.x < flags->r_min.x)
		error_msg("small flag");
	if (flags->r.y < flags->r_min.y)
		error_msg("small flag");
	while (line[i])
	{
		if (line[i] != ' ')
			error_msg("extra char");
		i++;
	}
	return (1);
}
