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
	if (ft_lstsize(*stack_a) == 3)
	{
		sort_3(stack_a);
		do_pa(stack_a, stack_b);
		do_pa(stack_a, stack_b);
	}
	else if (small(stack_a) == 0 && ft_lstsize(*stack_a) > 3)
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
}
