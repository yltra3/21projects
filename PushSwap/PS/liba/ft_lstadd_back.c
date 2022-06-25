/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:13:23 by clornel           #+#    #+#             */
/*   Updated: 2021/10/15 19:13:25 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_back(t_alg **alst, t_alg *new)
{
	t_alg	*tmp;

	if (new == NULL)
		return ;
	else if (*alst == NULL || alst == NULL)
		*alst = new;
	else
	{
		tmp = lst_last(*alst);
		tmp->next = new;
	}
}
