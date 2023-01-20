/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:43:33 by aankote           #+#    #+#             */
/*   Updated: 2023/01/08 01:43:35 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	do_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_b;
	t_stack	*temp_a;

	temp_a = *stack_a;
	temp_b = *stack_b;
	(*stack_b) = (*stack_b)->next;
	*stack_a = temp_b;
	(*stack_a)->next = temp_a;
	indexes(*stack_a);
}

void	do_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_b;
	t_stack	*temp_a;

	temp_b = (*stack_b);
	temp_a = (*stack_a);
	*stack_a = (*stack_a)->next;
	*stack_b = temp_a;
	(*stack_b)->next = temp_b;
	indexes(*stack_a);
}
