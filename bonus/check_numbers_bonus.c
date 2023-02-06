/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 04:29:02 by aankote           #+#    #+#             */
/*   Updated: 2023/01/15 04:29:05 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker_bonus.h"

int	check_duplicate(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				ft_putendl_fd("ERROR!\nthere is number duplicated!.", 1);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_is_number(char **av, int i, int j)
{
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != '-' && av[i][j] != '+')
			{
				ft_putendl_fd("ERROR!\nyou can put only numbers!.", 1);
				return (0);
			}
			if (ft_isdigit(av[i][j]) && av[i][j + 1] && !ft_isdigit(av[i][j
					+ 1]))
			{
				ft_putendl_fd("ERROR!\nyou can put only numbers!.", 1);
				return (0);
			}
			if ((av[i][j] == '-' || av[i][j] == '+') && (!av[i][j + 1]
					|| !ft_isdigit(av[i][j + 1])))
			{
				ft_putendl_fd("ERROR!\nyou can put only numbers!.", 1);
				return (0);
			}
		}
	}
	return (1);
}

int	check_limits(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_atoi(av[i]) > INT_MAX)
		{
			ft_putendl_fd("ERROR!\nExceeded the upper limit!", 1);
			return (0);
		}
		if (ft_atoi(av[i]) < INT_MIN)
		{
			ft_putendl_fd("ERROR!\nExceeded the lower limit!", 1);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_n(char **av)
{
	int	i;
	int	j;
	int	check;

	i = 1;
	while (av[i])
	{
		check = 0;
		j = -1;
		while (av[i][++j])
		{
			if (av[i][j])
			{
				if (ft_isdigit(av[i][j]))
					check = 1;
			}
		}
		if (!check)
		{
			ft_putendl_fd("ERROR!\nyou can put only numbers!.", 1);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_numbers(char **av)
{
	if (!check_is_number(av, -1, -1))
		return (0);
	if (!check_limits(av))
		return (0);
	if (!check_duplicate(av))
		return (0);
	return (1);
}
