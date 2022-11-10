/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/10/15 18:33:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*resize(t_memory *memory)
{
	char	*result;
	int		i;
	int		y;
	int		current_length;

	current_length = ft_strlen(memory->str) - memory->position;
	memory->length = current_length;
	result = malloc(sizeof(char) * (BUFFER_SIZE + current_length + 1));
	if (!result)
		return (NULL);
	i = memory->position;
	y = 0;
	while (memory->str[i])
		result[y++] = memory->str[i++];
	result[y] = '\0';
	free(memory->str);
	memory->str = result;
	memory->position = 0;
	return (result);
}

int	find_nl(t_memory memory)
{
	int		i;
	char	*str;

	str = &memory.str[memory.position];
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
