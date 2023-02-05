/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:11:02 by aankote           #+#    #+#             */
/*   Updated: 2023/01/06 19:11:04 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	do_rb(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = *stack;
	temp2 = *stack;
	if (ft_lstsize(*stack) < 2 || !(*stack)->next)
		return ;
	(*stack) = (*stack)->next;
	while (temp->next)
		temp = temp->next;
	temp->next = temp2;
	temp2->next = NULL;
}

void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	do_ra(stack_a);
	do_rb(stack_b);
}

void	do_rra(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*first;

	if (ft_lstsize(*stack) < 2 || !(*stack)->next)
		return ;
	first = *stack;
	temp = *stack;
	while (temp->next->next)
		temp = temp->next;
	(*stack) = temp->next;
	(*stack)->next = first;
	temp->next = NULL;
}

void	do_rrb(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*first;

	if (ft_lstsize(*stack) < 2 || !(*stack)->next)
		return ;
	first = *stack;
	temp = *stack;
	while (temp->next->next)
		temp = temp->next;
	(*stack) = temp->next;
	(*stack)->next = first;
	temp->next = NULL;
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	do_rra(stack_a);
	do_rrb(stack_b);
}
