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

void	do_sort_5(t_stack **stack_a, t_stack **stack_b)
{
	if (check_sort(stack_a) && ft_lstsize(*stack_a) == 5)
		return ;
	if (small(stack_a) == 0 && ft_lstsize(*stack_a) > 3)
	{
		do_pb(stack_a, stack_b);
		do_sort_5(stack_a, stack_b);
	}
	else if (small(stack_a) <= 2 && ft_lstsize(*stack_a) > 3)
	{
		do_ra(stack_a);
		do_sort_5(stack_a, stack_b);
	}
	else if (small(stack_a) > 2 && ft_lstsize(*stack_a) > 3)
	{
		do_rra(stack_a);
		do_sort_5(stack_a, stack_b);
	}
	else if (ft_lstsize(*stack_a) <= 4)
	{
		sort_3(stack_a);
		while (ft_lstsize(*stack_b))
			do_pa(stack_a, stack_b);
	}
}

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

t_stack **sort_100(t_stack **stack_a, t_stack **stack_b)
{
	int *tb;
	int i;
	t_stack *temp;

	i = 0;
	temp = *stack_a;
	tb = sort_table(&temp);
	while (ft_lstsize(*stack_a))
	{
		if ((*stack_a)->value <= tb[i])
		{
			do_pb(stack_a, stack_b);
			do_rb(stack_b);
			i ++;
			
		}
		else if ((*stack_a)->value <= tb[i + 1])
		{
			do_pb(stack_a, stack_b);
			i ++;
		}
		else
			do_ra(stack_a);
	}
	return(stack_b);
}

void sort_h(t_stack **stack_a, t_stack **stack_b)
{
	indexes (*stack_b);
	printf ("%d*",ft_lstsize(*stack_b ));
	if (ft_lstsize(*stack_b) && big(stack_b) == 0)
	{
		do_pa(stack_a, stack_b );
		sort_h(stack_a, stack_b);
	}
	else if (ft_lstsize(*stack_b)  && big(stack_b) == ft_lstsize(*stack_b) - 1)
	{
		do_rrb(stack_b);
		sort_h(stack_a, stack_b);
	}
	else
		return ;
}
