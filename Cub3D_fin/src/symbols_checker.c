/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbols_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_name_of_path(int *start, int *end, char *line)
{
	int	i;

	while (line[*start] == ' ')
		*start = *start + 1;
	i = *start;
	while (line[i])
	{
		if (line[i] == ' ')
		{
			*end = i - 1;
			while (line[i] == ' ')
				i++;
			if (line[i] && line[i] != ' ')
				error_msg("Texture failure!");
			line[*end + 1] = '\0';
			break ;
		}
		i++;
	}
	if (*end == -1)
		*end = i - 1;
	return (1);
}

int	check_xpm_path(int *flag, int *xpm_image, char *line, char **way)
{
	int	start;
	int	end;
	int	len;

	*flag = *flag + 1;
	start = 3;
	end = -1;
	if (check_name_of_path(&start, &end, line) == 0)
		return (0);
	if (line[end - 3] != '.' || line[end - 2] != 'x' || \
		line[end - 1] != 'p' || line[end] != 'm')
		error_msg("Incorrect format of file");
	line = line + start;
	*xpm_image = check_open_file(line);
	close (*xpm_image);
	if (*xpm_image == 0)
		return (0);
	len = ft_strlen(line);
	(*way) = malloc(sizeof(char) * (len + 1));
	ft_copy_line(line, way, len);
	return (1);
}

int	check_config_line(t_flags *flags, char *line)
{
	if (ft_strlen(line) < 7 && ft_strlen(line) != 0)
		error_msg("invalid line in map_config");
	else if (ft_strlen(line) == 0)
		return (1);
	else if (ft_strncmp(line, "R ", 2) == 0)
		return (check_line_r(flags, line));
	else if (ft_strncmp(line, "NO ", 3) == 0)
		return (check_xpm_path(&flags->flag_no, &flags->no,
				line, &flags->n_side));
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (check_xpm_path(&flags->flag_so, &flags->so,
				line, &flags->s_side));
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (check_xpm_path(&flags->flag_we, &flags->we,
				line, &flags->w_side));
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (check_xpm_path(&flags->flag_ea, &flags->ea,
				line, &flags->e_side));
	else if (ft_strncmp(line, "F  ", 2) == 0)
		return (check_line_color(&flags->flag_f, &flags->f, line));
	else if (ft_strncmp(line, "C  ", 2) == 0)
		return (check_line_color(&flags->flag_c, &flags->c, line));
	else
		error_msg("Invalid config!");
	return (1);
}

int	check_valid_symbols(t_flags *flags, int fd)
{
	char	*line;
	int		r;

	r = 21;
	while (r)
	{
		r = get_next_line(fd, &line);
		flags->count_line++;
		if (check_config_line(flags, line) == 0)
			return (0);
		if (check_all_flags(*flags) == 1)
		{
			free(line);
			return (1);
		}
		if (check_double_flags(*flags) == 0)
			return (0);
		free(line);
	}
	if (check_all_flags(*flags) == 0)
		error_msg("No config in file!");
	return (1);
}
