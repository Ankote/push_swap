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

#include "push_swap.h"

// void do_pa(t_stack *stack_1, t_stack *stack_2)
// {
//     if (!stack_2)
//         return ;
//     ft_lstadd_front(&stack_1, stack_2);
// }

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
	indexes(*stack_a);
	ft_putendl_fd("ra", 1);
}

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
	indexes(*stack);
	ft_putendl_fd("rb", 1);
}

void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	do_ra(stack_a);
	do_rb(stack_b);
	indexes(*stack_a);
	indexes(*stack_b);
	ft_putendl_fd("rr", 1);
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
	indexes(*stack);
	ft_putendl_fd("rra", 1);
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
	indexes(*stack);
	ft_putendl_fd("rrb", 1);
}
