/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	replace_map_tmp(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->line_count)
	{
		j = 0;
		while (j < data->column_count)
		{
			if (data->field[i][j] == '*')
				data->field[i][j] = ' ';
			j++;
		}
		i++;
	}
}

void	map_maker(t_data *data, char *name)
{
	char	*line;
	int		i;
	int		r;
	int		count;

	count = 0;
	i = 1;
	r = 21;
	data->fd = open(name, O_RDONLY);
	while (count < data->flags.count_line)
	{
		count++;
		get_next_line(data->fd, &line);
		free(line);
	}
	while (r)
	{
		r = get_next_line(data->fd, &line);
		ft_memcpy(data->field[i], line, ft_strlen(line));
		i++;
		free(line);
	}
	close(data->fd);
}

void	border_maker(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->line_count)
	{
		data->field[i][0] = '!';
		data->field[i][data->column_count - 1] = '!';
		i++;
	}
	while (j < data->column_count)
	{
		data->field[0][j] = '!';
		data->field[data->line_count - 1][j] = '!';
		j++;
	}
}

int	map_memory_alloc(t_data *data)
{
	int	i;

	i = 0;
	data->field = malloc(sizeof(char *) * data->line_count);
	if (data->field == NULL)
		error_msg("Not memory!");
	while (i < data->line_count)
	{
		data->field[i] = malloc(data->column_count);
		if (data->field[i] == NULL)
			error_msg("Not memory!");
		i++;
	}
	return (1);
}

int	parse_map(t_data *data, char *name)
{
	int	i;
	int	j;

	data->line_count = data->line_count + 2;
	data->column_count = data->column_count + 2;
	if (map_memory_alloc(data) == 0)
		return (0);
	i = 0;
	while (i < data->line_count)
	{
		j = 0;
		while (j < data->column_count)
		{
			data->field[i][j] = '*';
			j++;
		}
		i++;
	}
	border_maker(data);
	map_maker(data, name);
	replace_map_tmp(data);
	return (1);
}
