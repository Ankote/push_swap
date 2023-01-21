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

#include "push_swap.h"

int  *to_fill_table(int ac, char **av)
{
	int *tb;
	int i;
    int j;

	i = 0;
    j = 1;
	tb = malloc(ac - 1);
	while (i < ac - 1)
		tb[i++] = ft_atoi(av[j++]);
	return (tb);
}

int check_duplicate(int ac, char **av)
{
    int i;
    int j;
    int *tb;

    tb = to_fill_table(ac, av);
    i = 0;
    while (i < ac - 1)
    {
        j = i + 1;
        while(j < ac - 1)
        {
            if (tb[i] == tb[j])
            {
                ft_putendl_fd("ERROR!\nthere is number duplicated!.", 1);
                return (free (tb), 0);
            }
            j++;
        }
        i++;
    }
    return (free (tb), 1);
}


int chech_is_number(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    while (i < ac)
    {
        j = 0;
        while (av[i][j])
        {
            if (!ft_isdigit(av[i][j]) && av[i][j] != '-' && av[i][j] != '+')
            {
                ft_putendl_fd("ERROR!\nyou can put only numbers!.", 1);
                return (0);
            }
            if (ft_isdigit(av[i][j]) && av[i][j + 1] && !ft_isdigit(av[i][j + 1]))
            {
                ft_putendl_fd("ERROR!\nyou can put only numbers!.", 1);
                return (0);
            }
            j ++;
        }
        i ++;
    }
    return (1);
}