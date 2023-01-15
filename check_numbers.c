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

int ft_intchr(int *tb, int nb)
{
    int i;

    i = 0;
    while (tb)
    {
        if (nb == tb[i])
            return (1);
        i++;
        tb = tb + i;
    }
    return (0);
}

int check_duplicate(t_stack *stack_a)
{
    int *tb;
    int i;

    i = 0;
	tb = to_fill_table(&stack_a);
    while (tb)
    {
        if(ft_intchr(tb, tb[i]))
            return (0);
        i ++;
        tb = tb + i;
    }
    return (1);
}