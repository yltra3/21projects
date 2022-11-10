/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	read_to_mem(t_memory *memory, int fd)
{
	int			received;
	char		*resized;

	resized = "start";
	if (memory->str == NULL || memory->fd != fd)
	{
		memory->position = 0;
		memory->length = 0;
		memory->str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (memory->str == NULL)
			return (-1);
	}
	else
		resized = resize(memory);
	memory->fd = fd;
	received = read(fd, memory->str + memory->length, BUFFER_SIZE);
	if (received == -1 || !resized)
	{
		free(memory->str);
		memory->str = NULL;
		return (-1);
	}
	(memory->str)[memory->length + received] = '\0';
	return (received);
}

int	copy_to_line(t_memory *memory, char **line)
{
	int	i;
	int	line_size;

	if (find_nl(*memory) == -1)
		line_size = ft_strlen(&(memory->str[memory->position]));
	else
		line_size = find_nl(*memory);
	*line = malloc(sizeof(char) * (line_size + 1));
	if (*line == NULL)
		return (-1);
	i = 0;
	while (i < line_size)
		(*line)[i++] = memory->str[memory->position++];
	memory->position++;
	(*line)[i] = '\0';
	return (line_size);
}

int	get_next_line(int fd, char **line)
{
	int				received;
	static t_memory	memory;
	int				line_size;

	if (!line || BUFFER_SIZE == 0 || fd < 0)
		return (-1);
	received = read_to_mem(&memory, fd);
	if (received == -1)
		return (-1);
	while (received >= BUFFER_SIZE && (find_nl(memory) == -1))
	{
		received = read_to_mem(&memory, fd);
		if (received == -1)
			return (-1);
	}
	line_size = copy_to_line(&memory, line);
	if (line_size == -1)
		return (-1);
	if (received < BUFFER_SIZE && line_size >= ft_strlen(memory.str))
		return (ft_gnl_hell(&memory.str));
	else if (received == -1)
		return (-1);
	else
		return (1);
}
