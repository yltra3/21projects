/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:37:11 by clornel           #+#    #+#             */
/*   Updated: 2022/01/14 17:37:12 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_a(t_swap *swap)
{
	int	next_i;

	next_i = swap->temp->next_index;
	swap->temp = swap->a;
	while (swap->temp->index != next_i)
		swap->temp = swap->temp->next;
	if (swap->temp->indicator == 1)
	{
		while (swap->a->index != next_i)
			ra(swap, 1);
	}
	else
	{
		while (swap->a->index != next_i)
			rra(swap, 1);
	}
}

static void	comparison(t_swap *swap, t_alg *temp_num, int index, int flag)
{
	swap->init.temp_steps = swap->init.temp_steps + swap->temp->steps;
	if (swap->temp->indicator == temp_num->indicator)
	{
		if (swap->temp->steps > temp_num->steps)
			swap->init.temp_steps -= temp_num->steps;
		else
			swap->init.temp_steps -= swap->temp->steps;
	}
	if (swap->init.first_step > swap->init.temp_steps
		|| swap->init.first_step == -1)
	{
		swap->init.first_step = swap->init.temp_steps;
		swap->init.first_i = index;
		swap->init.indicator = flag;
	}
}

static void	prepare_stack(t_swap *swap)
{
	int		i;
	int		index;
	int		flag;
	t_alg	*temp_alg;

	swap->init.first_i = 0;
	swap->init.first_step = -1;
	swap->temp = swap->b;
	temp_alg = swap->b;
	while (swap->temp)
	{
		swap->init.temp_steps = swap->temp->steps;
		index = swap->temp->index;
		flag = swap->temp->indicator;
		swap->temp = swap->b;
		i = search(swap, index);
		temp_alg->next_index = index + i;
		swap->temp = swap->a;
		while (index + i != swap->temp->index)
			swap->temp = swap->temp->next;
		comparison(swap, temp_alg, index, flag);
		temp_alg = temp_alg->next;
		swap->temp = temp_alg;
	}
}

static void	push_b(t_swap *swap)
{
	int	size_a;
	int	temp_size;

	size_a = ft_lstsize(swap->a);
	temp_size = size_a;
	swap->temp = swap->a;
	while (temp_size > 3)
	{
		if (swap->temp->index != size_a - 1 && swap->temp->index != size_a - 2
			&& swap->temp->index != size_a - 3)
		{
			pb(swap, 1);
			swap->temp = swap->a;
			temp_size--;
		}
		else
		{
			ra(swap, 1);
			swap->temp = swap->a;
		}
	}
}

void	algorithm(t_swap *swap)
{
	int	size_b;

	push_b(swap);
	three_arg(swap);
	size_b = ft_lstsize(swap->b);
	while (size_b)
	{
		number_steps(swap);
		prepare_stack(swap);
		swap_st(swap);
		swap->temp = swap->b;
		while (swap->temp->index != swap->init.first_i)
		{
			if (swap->init.indicator == 1)
				rb(swap, 1);
			else
				rrb(swap, 1);
			swap->temp = swap->b;
		}
		swap->temp = swap->b;
		push_a(swap);
		pa(swap, 1);
		size_b--;
	}
}
