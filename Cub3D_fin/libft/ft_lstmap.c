/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loctopus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:58:25 by loctopus          #+#    #+#             */
/*   Updated: 2021/10/21 14:31:26 by loctopus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*nelm;

	if (!lst || !f)
		return (NULL);
	nelm = ft_lstnew(f(lst->content));
	if (!nelm)
		return (NULL);
	nlst = nelm;
	lst = lst->next;
	while (lst)
	{
		nelm = ft_lstnew(f(lst->content));
		if (!nelm)
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&nlst, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&nlst, nelm);
	}
	return (nlst);
}
