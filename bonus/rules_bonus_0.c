/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 03:42:25 by aankote           #+#    #+#             */
/*   Updated: 2023/01/15 03:42:26 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_stack **stack)
{
	int	tmp;

	if (ft_lstsize(*stack) <= 1)
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
}

void	do_sa(t_stack **stack_a)
{
	swap(stack_a);
}

void	do_sb(t_stack **stack_b)
{
	swap(stack_b);
}

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}


void	do_ra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = *stack_a;
	temp2 = *stack_a;
	if (ft_lstsize(*stack_a) < 2)
		return ;
	(*stack_a) = (*stack_a)->next;
	while (temp->next)
		temp = temp->next;
	temp->next = temp2;
	temp2->next = NULL;
}