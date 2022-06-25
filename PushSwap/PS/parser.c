/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clornel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 11:34:07 by clornel           #+#    #+#             */
/*   Updated: 2022/01/14 11:34:08 by clornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	*ft_free(char **split, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(split[i]);
		++i;
	}
	free(split);
	return (NULL);
}

static void	check_arg(char *argv, t_swap *swap)
{
	int	i;

	i = 0;
	if (!argv[i])
		error_exit(swap);
	while (is_space(argv[i]))
		i++;
	if ((argv[i] == '-' || argv[i] == '+') && argv[i + 1])
		i++;
	while (argv[i])
	{
		if (argv[i] >= '0' && argv[i] <= '9')
			i++;
		else
			error_exit(swap);
	}
}

static void	check_split_arg(char **argv, t_swap *swap)
{
	int	i;
	int	l;

	i = 0;
	while (argv[i])
	{
		l = 0;
		while (is_space(argv[i][l]))
			l++;
		if ((argv[i][l] == '-' || argv[i][l] == '+') && argv[i][l + 1])
			l++;
		while (argv[i][l])
		{
			if (argv[i][l] >= '0' && argv[i][l] <= '9')
				l++;
			else
				error_exit(swap);
		}
		++i;
	}
}

static void	lonely_parse(t_swap *swap, char *argv)
{
	int		i;
	char	**str;

	i = 0;
	str = ft_split(argv, ' ');
	if (!str)
		error_exit(swap);
	check_split_arg(str, swap);
	while (str[i])
	{
		swap->temp = swap->a;
		while (swap->temp)
		{
			if (ft_atoi(str[i]) == swap->temp->num)
				error_exit(swap);
			swap->temp = swap->temp->next;
		}
		swap->temp = lst_new(ft_atoi(str[i]));
		ft_lstadd_back(&swap->a, swap->temp);
		++i;
	}
	ft_free(str, i);
}

void	parser(t_swap *swap, int argc, char **argv)
{
	int	i;

	i = 1;
	while (--argc)
	{
		if (ft_strchr(argv[i], ' '))
			lonely_parse(swap, argv[i++]);
		else
		{
			check_arg(argv[i], swap);
			swap->temp = swap->a;
			while (swap->temp)
			{
				if (ft_atoi(argv[i]) == swap->temp->num)
					error_exit(swap);
				swap->temp = swap->temp->next;
			}
			swap->temp = lst_new(ft_atoi(argv[i++]));
			ft_lstadd_back(&swap->a, swap->temp);
		}
	}
}
