/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:14:55 by clornel           #+#    #+#             */
/*   Updated: 2021/10/15 19:14:57 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lst_clear(t_alg **lst)
{
	t_alg	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			lst_free(*lst);
			(*lst) = tmp;
		}
	}
}
