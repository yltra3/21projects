/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loctopus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:12:44 by loctopus          #+#    #+#             */
/*   Updated: 2021/10/21 14:13:37 by loctopus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;
	char	*nstr;
	size_t	i;
	size_t	len;

	if (!s1 || !set)
		return (0);
	first = 0;
	len = ft_strlen(s1);
	while (s1[first] && ft_strchr(set, s1[first]))
		first++;
	i = len - 1;
	last = 0;
	while (len > first && ft_strchr(set, s1[i--]))
		last++;
	nstr = (char *)malloc((len - first - last + 1) * sizeof(char));
	if (!nstr)
		return (0);
	i = 0;
	while (first < len - last)
		nstr[i++] = s1[first++];
	nstr[i] = '\0';
	return (nstr);
}
