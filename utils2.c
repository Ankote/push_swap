/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:39:44 by aankote           #+#    #+#             */
/*   Updated: 2023/01/08 15:39:46 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexes(t_stack *stack)
{
	int	i;

	i = 0;
	if (!ft_lstsize(stack))
		return ;
	while (stack)
	{
		stack->index = i++;
		stack = stack->next;
	}
}

int	check_sort(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp && (temp)->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	small(t_stack **stack)
{
	int		sm;
	int		index;
	t_stack	*temp;

	if (!*stack)
		return (-1);
	temp = *stack;
	index = 0;
	sm = temp->value;
	while (temp)
	{
		if (temp->value < sm)
		{
			sm = temp->value;
			index = temp->index;
		}
		temp = (temp)->next;
	}
	return (index);
}

int	big(t_stack **stack)
{
	int		bg;
	int		index;
	t_stack	*temp;

	if (!*stack)
		return (-1);
	bg = 0;
	index = 0;
	temp = *stack;
	while (temp)
	{
		if ((temp)->value > bg)
		{
			bg = (temp)->value;
			index = (temp)->index;
		}
		temp = (temp)->next;
	}
	return (index);
}
