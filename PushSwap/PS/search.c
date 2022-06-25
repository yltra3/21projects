/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 12:31:56 by clornel           #+#    #+#             */
/*   Updated: 2022/01/15 12:31:57 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search(t_swap *swap, int index)
{
	int	i;

	i = 1;
	while (swap->temp)
	{
		if (swap->temp->index == index + i)
		{
			i++;
			swap->temp = swap->b;
		}
		else
			swap->temp = swap->temp->next;
	}
	return (i);
}
