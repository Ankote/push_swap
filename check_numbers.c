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

int check_duplicate(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    while (av[i])
    {
        j = i + 1;
        while(av[j] && ac > 1)
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


int check_is_number(int ac, char **av)
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

int check_limits(int ac, char **av)
{
    int i;

    i = 1;
    while (av[i] && ac > 1)
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
        i ++;
    }
    return (1);
}

int check_numbers(int ac, char **av)
{
    if (!check_duplicate(ac, av))
        return (0);
    if(!check_is_number(ac, av))
        return (0);
    if (!check_limits(ac, av))
        return (0);
    return (1);
}