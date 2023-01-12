/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:52:13 by aankote           #+#    #+#             */
/*   Updated: 2023/01/04 15:52:15 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	indexes(*stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	do_sb(t_stack **stack_b)
{
	swap(stack_b);
	indexes(*stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack1;
	t_stack	*stack2;
		
	stack2 = NULL;
	i = 1;
	argc = 0;
	while (argv[i])
	{
		ft_lstadd_back(&stack1, ft_lstnew(ft_atoi(argv[i]), i - 1));
		i++;
	}
	do_sort_5(&stack1, &stack2);
	printf("\n\n____Stack1____\n\n");
	while (stack1)
	{
		printf("%d -> %d\n", stack1->index, stack1->value);
		stack1 = stack1->next;
	}
	return (0);
}
