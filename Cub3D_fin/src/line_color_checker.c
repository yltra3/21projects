/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_color_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_is_color(char *line, int i, t_color log_rgb)
{
	while (line[i])
	{
		if (line[i] != ' ')
			error_msg("Color failure!");
		i++;
	}
	if (log_rgb.r == 0 || log_rgb.g == 0 || log_rgb.b == 0)
	{
		error_msg("Color failure!");
		return (0);
	}
	return (1);
}

int	check_line_color_rgb(int *log, int *color, char *line, int *i)
{
	while (line[*i])
	{
		if (line[*i] >= '0' && line[*i] <= '9')
		{
			*log = 1;
			*color = *color * 10 + (line[*i] - 48);
			if (*color > 255)
				error_msg("Colors value failure!");
		}
		else if (line[*i] == ',')
			break ;
		else if (line[*i] == ' ')
			break ;
		else
		{
			error_msg("Colors value failure!");
			return (0);
		}
		*i = *i + 1;
	}
	if (line[*i] != '\0')
		*i = *i + 1;
	return (1);
}

int	check_line_color(int *flag, t_color *color, char *line)
{
	int		i;
	t_color	log_rgb;

	init_color(&log_rgb);
	*flag = *flag + 1;
	if (ft_strlen(line) < 7)
		error_msg("Color failure!");
	i = 2;
	while (line[i] == ' ')
		i++;
	if (check_line_color_rgb(&log_rgb.r, &color->r, line, &i) == 0)
		return (0);
	if (line[i - 1] == ' ')
		error_msg("Color failure!");
	if (check_line_color_rgb(&log_rgb.g, &color->g, line, &i) == 0)
		return (0);
	if (line[i - 1] == ' ')
		error_msg("Color failure!");
	if (check_line_color_rgb(&log_rgb.b, &color->b, line, &i) == 0)
		return (0);
	if (line[i - 1] == ',')
		error_msg("Color failure!");
	if (check_is_color(line, i, log_rgb) == 0)
		return (0);
	return (1);
}
