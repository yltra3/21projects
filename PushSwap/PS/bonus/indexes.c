/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:02:23 by clornel           #+#    #+#             */
/*   Updated: 2022/01/14 17:02:24 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	sorting_index(int *index, int len)
{
	int	i;
	int	tmpswap;
	int	tmplen;

	tmplen = len;
	i = 0;
	while (len - 1)
	{
		if (index[i] > index[i + 1])
		{
			tmpswap = index[i];
			index[i] = index[i + 1];
			index[i + 1] = tmpswap;
			i = 0;
			len = tmplen;
		}
		else
		{
			++i;
			len--;
		}
	}
}

static void	indexing(int *index, t_swap *swap, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		swap->temp = swap->a;
		while (index[i] != swap->temp->num)
			swap->temp = swap->temp->next;
		swap->temp->index = i++;
	}
}

void	indexes(t_swap *swap)
{
	int	*index;
	int	i;
	int	len;

	len = ft_lstsize(swap->a);
	index = malloc(sizeof(int) * len);
	if (!index)
		error_exit(swap);
	swap->temp = swap->a;
	i = 0;
	while (swap->temp)
	{
		index[i++] = swap->temp->num;
		swap->temp = swap->temp->next;
	}
	sorting_index(index, len);
	indexing(index, swap, len);
	free(index);
}
