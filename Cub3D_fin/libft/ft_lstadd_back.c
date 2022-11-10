/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loctopus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:13:14 by loctopus          #+#    #+#             */
/*   Updated: 2021/10/21 14:00:03 by loctopus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*endl;

	if (lst)
	{
		if (*lst)
		{
			endl = ft_lstlast(*lst);
			endl->next = new;
		}
		else
			*lst = new;
	}
}
