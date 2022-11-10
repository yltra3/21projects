/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loctopus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:46:17 by loctopus          #+#    #+#             */
/*   Updated: 2021/10/21 10:53:30 by loctopus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buf;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		buf = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = buf;
	}
}
