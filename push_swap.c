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

int push_swap(t_stack **stack_a, t_stack **stack_b, int count)
{
	if (check_sort(stack_a))
		return (0);
	if (count <= 3)
		sort_3(stack_a);
	else if (count <= 5)
		do_sort_5(stack_a, stack_b);
	else if (count <= 100)
	{
		*stack_b = *butterfly_push(stack_a, stack_b, 15);
		sort_h(stack_a, stack_b);
	}
	return (0);
}

void free_stack(t_stack **stack)
{
	t_stack *tmp;

	if (!stack || !(*stack))
		return;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void fill_stack(int ac, char **av, t_stack **stack)
{
	int i;

	i = 1;
	while (av[i] && ac > 1)
	{
		ft_lstadd_back(stack, ft_lstnew(ft_atoi(av[i]), i - 1));
		i++;
	}
}

int main(int argc, char **argv)
{
	t_stack *stack1;
	t_stack *stack2;
	stack2 = NULL;
	
	if (argc < 2 || !check_numbers(argc, argv))
		exit (1);
	fill_stack(argc, argv, &stack1);
	indexes(stack1);
	push_swap(&stack1, &stack2, argc - 1);
	free_stack(&stack1);
	free_stack(&stack2);
	return (0);
}
