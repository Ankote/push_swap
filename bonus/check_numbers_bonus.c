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

#include "checker.h"

int  *to_fill_table(t_stack **stack)
{
	t_stack *temp;
	int *tb;
	int i;

	i = 0;
	temp = *stack;
	tb = malloc(ft_lstsize(*stack));
	while (temp)
	{
		tb[i++] = (temp)->value;
		temp = (temp)->next;
	}
	return (tb);
}

int check_duplicate(t_stack **stack)
{
    int i;
    int j;
    int size;
    int *tb;

    tb = to_fill_table(stack);
    size = ft_lstsize(*stack);
    i = 0;
    while (i < size)
    {
        j = i + 1;
        while(j < size)
        {
            if (tb[i] == tb[j])
            {
                ft_putendl_fd("Error", 1);
                return (free (tb), 0);
            }
            
            j++;
        }
        i++;
    }
    return (free (tb), 1);
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