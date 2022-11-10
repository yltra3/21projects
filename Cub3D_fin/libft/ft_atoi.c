/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loctopus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:25:26 by loctopus          #+#    #+#             */
/*   Updated: 2021/10/21 13:58:54 by loctopus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int				minus;
	unsigned long	result;

	minus = 1;
	result = 0;
	while ((*str == ' ') || (*str == '\t') || (*str == '\n')
		|| (*str == '\v') || (*str == '\f') || (*str == '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + ((int)*str - '0');
		str++;
	}
	if (result > 9223372036854775807 && minus > 0)
		return (-1);
	if (result > 9223372036854775807 && minus < 0)
		return (0);
	return ((int)result * minus);
}
