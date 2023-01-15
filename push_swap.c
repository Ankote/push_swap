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
		return(0);
	if (count <= 3)
		sort_3(stack_a);
	else if (count <= 5)
		do_sort_5(stack_a, stack_b);
	else if (count <= 100)
	{
		*stack_b = *butterfly_push(stack_a, stack_b, 15);
		sort_h(stack_a, stack_b);
	}
	else
	{
		*stack_b = *butterfly_push(stack_a, stack_b, 30);
		sort_h(stack_a, stack_b);	
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack1;
	t_stack	*stack2;
	t_stack	*temp;
		
	stack2 = NULL;
	
	i = 1;
	argc = 0;
	while (argv[i])
	{
		ft_lstadd_back(&stack1, ft_lstnew(ft_atoi(argv[i]), i - 1));
		i++;
	}
	indexes(stack1);
	temp = stack1;
	if (!check_duplicate(&temp))
	{
		printf("nooo");
		return (0);
	}
	push_swap (&stack1, &stack2, i - 1);

	return (0);
}
