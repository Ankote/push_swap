/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 16:52:10 by aankote           #+#    #+#             */
/*   Updated: 2023/01/08 16:52:11 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack)
{
	if (check_sort(stack))
		return ;
	if (big(stack) == 0 && ft_lstsize(*stack) == 2)
	{
		do_sa(stack);
		return ;
	}
	if (big(stack) == 0 && small(stack) == 1)
		do_ra(stack);
	if (big(stack) == 0 && small(stack) == 2)
	{
		do_ra(stack);
		do_sa(stack);
	}
	if (big(stack) == 2 && small(stack) == 1)
		do_sa(stack);
	if (big(stack) == 1 && small(stack) == 2)
		do_rra(stack);
	if (big(stack) == 1 && small(stack) == 0)
	{
		do_rra(stack);
		do_sa(stack);
	}
}

void	do_sort_5(t_stack **stack_a, t_stack **stack_b)
{
	if (check_sort(stack_a) && !ft_lstsize(*stack_b))
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
	else if (ft_lstsize(*stack_a) == 3)
	{
		sort_3(stack_a);
		while (ft_lstsize(*stack_b))
			do_pa(stack_a, stack_b);
	}
}
