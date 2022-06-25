/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:43:20 by clornel           #+#    #+#             */
/*   Updated: 2022/01/15 11:43:21 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	steps_stack_a(t_swap *swap)
{
	int	i;
	int	j;
	int	temp_size;

	i = -1;
	j = 0;
	temp_size = ft_lstsize(swap->a);
	swap->temp = swap->a;
	while (j < temp_size / 2 + temp_size % 2)
	{
		swap->temp->steps = ++i;
		j++;
		swap->temp->indicator = 1;
		swap->temp = swap->temp->next;
	}
	if (temp_size % 2 == 0)
		i++;
	while (swap->temp)
	{
		swap->temp->steps = i--;
		swap->temp->indicator = 0;
		swap->temp = swap->temp->next;
	}	
}

void	number_steps(t_swap *swap)
{
	int	i;
	int	j;
	int	temp_size;

	i = -1;
	j = 0;
	steps_stack_a(swap);
	temp_size = ft_lstsize(swap->b);
	swap->temp = swap->b;
	while (j < temp_size / 2 + temp_size % 2)
	{
		swap->temp->steps = ++i;
		j++;
		swap->temp->indicator = 1;
		swap->temp = swap->temp->next;
	}
	if (temp_size % 2 == 0)
		i++;
	while (swap->temp)
	{
		swap->temp->steps = i--;
		swap->temp->indicator = 0;
		swap->temp = swap->temp->next;
	}
}
