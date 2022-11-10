/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

void	parse_line(t_scene *scene, char **splitted)
{
	if (line_fields(splitted) == 0)
		return ;
	else if (line_fields(splitted) < 2)
		handle_error("Unknown element in the scene");
	if (ft_strncmp(splitted[0], "R", 1) == 0)
		parse_resolution(scene, splitted);
	else if (ft_strncmp(splitted[0], "A", 1) == 0)
		parse_ambient(scene, splitted);
	else if (ft_strncmp(splitted[0], "cy", 2) == 0)
		parse_cylinder(scene, splitted);
	else if (ft_strncmp(splitted[0], "c", 1) == 0)
		parse_camera(scene, splitted);
	else if (ft_strncmp(splitted[0], "l", 1) == 0)
		parse_light(scene, splitted);
	else if (ft_strncmp(splitted[0], "sp", 2) == 0)
		parse_sphere(scene, splitted);
	else if (ft_strncmp(splitted[0], "pl", 2) == 0)
		parse_plane(scene, splitted);
	else if (ft_strncmp(splitted[0], "sq", 2) == 0)
		parse_square(scene, splitted);
	else if (ft_strncmp(splitted[0], "tr", 2) == 0)
		parse_triangle(scene, splitted);
	else
		handle_error("Unknown element in the scene.");
}

void	init_scene(t_scene *scene)
{
	scene->cameras = NULL;
	scene->lights = NULL;
	scene->objects = NULL;
	scene->height = 0;
	scene->width = 0;
	scene->ambient_color.red = -1;
	scene->ambient_color.green = -1;
	scene->ambient_color.blue = -1;
}

t_scene	*parse_file(char *path)
{
	int		fd;
	char	*line;
	t_scene	*scene;
	char	**splitted;

	fd = open_file(path);
	if (fd == -1)
		return (0);
	scene = malloc(sizeof(t_scene));
	init_scene(scene);
	while (get_next_line(fd, &line) > 0)
	{
		splitted = ft_split(line, ' ');
		if (!check_line(line))
			handle_error("Forbidden symbol in the scene.");
		parse_line(scene, splitted);
		free(line);
	}
	splitted = ft_split(line, ' ');
	parse_line(scene, splitted);
	free(line);
	check_scene(scene);
	close(fd);
	return (scene);
}
