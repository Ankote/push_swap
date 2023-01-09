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
	t_stack	*temp;

	temp = *stack;
	if (check_sort(stack))
		return ;
	if (big(stack) == 0 && small(stack) == 1)
		do_ra(stack);
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
