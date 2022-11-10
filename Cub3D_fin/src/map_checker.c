/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_symbol_in_map(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (3);
	else if (c == '0')
		return (2);
	else if (c == '1' || c == ' ' || c == '\n')
		return (1);
	else
		return (0);
}

int	check_line_in_map(t_data *data, char *line, int *plr)
{
	int	i;

	i = 0;
	data->line_count++;
	if (data->line_count > data->line_max)
		error_msg("Wrong map!");
	if ((int)ft_strlen(line) > data->column_count)
	{
		data->column_count = ft_strlen(line);
		if (data->column_count > data->column_max)
			error_msg("Wrong map!");
	}
	while (line[i])
	{
		if (check_symbol_in_map(line[i]) == 3)
			*plr = *plr + 1;
		if (check_symbol_in_map(line[i]) == 0)
		{
			error_msg("Wrong map!");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_map_helper(t_data *data, int *plr, char *line, int r)
{
	while (r)
	{
		if (ft_strlen(line) == 0)
			break ;
		if (check_line_in_map(data, line, plr) == 0)
			return (0);
		if (*plr > 1)
			error_msg("More player!");
		r = get_next_line(data->fd, &line);
		free(line);
	}
	if (ft_strlen(line) != 0)
	{
		if (check_line_in_map(data, line, plr) == 0)
			return (0);
	}
	while (r)
	{
		r = get_next_line(data->fd, &line);
		if (ft_strlen(line) != 0)
			error_msg("Wrong map!");
		free(line);
	}
	return (1);
}

int	check_map(t_data *data)
{
	char	*line;
	int		r;
	int		plr;

	r = 21;
	plr = 0;
	while (r)
	{
		r = get_next_line(data->fd, &line);
		if (ft_strlen(line) != 0)
			break ;
		free(line);
		data->flags.count_line++;
	}
	if (check_map_helper(data, &plr, line, r) == 0)
		return (0);
	if (ft_strlen(line) != 0)
		free(line);
	if (plr == 0)
		error_msg("Where is player?");
	if (data->line_count < 3 || data->column_count < 3)
		error_msg("Map very small!");
	return (1);
}
