/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:38:20 by aankote           #+#    #+#             */
/*   Updated: 2023/01/09 10:38:27 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	swap;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
			swap = tab[j];
			tab[j] = tab[i];
			tab[i] = swap;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int  *sort_table(t_stack **stack)
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
	tb = ft_sort_int_tab(tb, ft_lstsize((*stack)));
	return (tb);
}

t_stack **butterfly_push(t_stack **stack_a, t_stack **stack_b, int base)
{
	t_vars vars;

	vars.i = 0;
	vars.tb = sort_table(stack_a);
	vars.x = ft_lstsize(*stack_a);
	while (ft_lstsize(*stack_a))
	{
		vars.y = vars.i + base;
		if(vars.y > vars.x - base)
			vars.y = vars.x - base;
		if (ft_lstsize(*stack_a) && (*stack_a)->value <= vars.tb[vars.i])
		{
			do_pb(stack_a, stack_b);
			do_rb(stack_b);
			vars.i ++;
		}
		else if (ft_lstsize(*stack_a) &&(*stack_a)->value <= vars.tb[vars.y])
		{
			do_pb(stack_a, stack_b);
			vars.i ++;
		}
		else
			do_ra(stack_a);
	}
	return(free (vars.tb), stack_b);
}

void sort_h(t_stack **stack_a, t_stack **stack_b)
{
	indexes (*stack_b);
	if (ft_lstsize(*stack_b) && big(stack_b) == 0)
	{
		do_pa(stack_a, stack_b );
		sort_h(stack_a, stack_b);
	}
	else if (ft_lstsize(*stack_b)  && big(stack_b) >= ft_lstsize(*stack_b) / 2)
	{
		do_rrb(stack_b);
		sort_h(stack_a, stack_b);
	}
	else if (ft_lstsize(*stack_b)  && big(stack_b) < ft_lstsize(*stack_b) / 2)
	{
		do_rb(stack_b);
		sort_h(stack_a, stack_b);
	}
	else
		return ;
}