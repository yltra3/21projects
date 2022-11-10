/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loctopus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:54:56 by loctopus          #+#    #+#             */
/*   Updated: 2021/10/21 14:35:05 by loctopus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_makestr(char *dst, char *src, int index)
{
	int	k;

	k = 0;
	while (index >= 0)
		dst[k++] = src[index--];
	dst[k] = '\0';
}

char	*ft_itoa(int n)
{
	int			i;
	char		buf[11];
	char		*result;
	long int	flag;

	i = 0;
	flag = n;
	if (n < 0)
		flag = flag * (-1);
	if (n == 0)
		buf[i++] = 48;
	while (flag > 0)
	{
		buf[i++] = (flag % 10) + 48;
		flag = flag / 10;
	}
	if (n < 0)
		buf[i++] = '-';
	result = (char *)malloc((i + 1) * sizeof(char));
	if (!result)
		return (0);
	i--;
	ft_makestr(result, buf, i);
	return (result);
}
