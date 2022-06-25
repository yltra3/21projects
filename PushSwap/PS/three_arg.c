/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:56:15 by clornel           #+#    #+#             */
/*   Updated: 2022/01/14 15:56:17 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	algo(t_swap *swap)
{
	if (swap->a->num < swap->a->next->next->num
		&& swap->a->next->next->num < swap->a->next->num)
		sa(swap, 1);
	if (swap->a->num > swap->a->next->num
		&& swap->a->num < swap->a->next->next->num)
		sa(swap, 1);
	if (swap->a->num < swap->a->next->num
		&& swap->a->num > swap->a->next->next->num)
		rra(swap, 1);
	if (swap->a->next->next->num > swap->a->next->num
		&& swap->a->next->next->num < swap->a->num)
		ra(swap, 1);
	if (swap->a->next->num < swap->a->num
		&& swap->a->next->num > swap->a->next->next->num)
	{
		sa(swap, 1);
		rra(swap, 1);
	}
}

void	three_arg(t_swap *swap)
{
	if (ft_lstsize(swap->a) == 2)
	{
		if (swap->a->num > swap->a->next->num)
			sa(swap, 1);
	}
	else if (ft_lstsize(swap->a) == 3)
		algo(swap);
}
