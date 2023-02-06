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

void	free_duble(char **p)
{
	int	i;

	i = 0;
	if (p[0] == NULL)
		exit(0);
	while (p[i])
		free(p[i++]);
	free(p);
}

char	*join_free(char *sta_buff, char *buff)
{
	char	*temp;

	temp = ft_strjoin(sta_buff, buff);
	free(sta_buff);
	return (temp);
}

int	push_swap(t_stack **stack_a, t_stack **stack_b, int count)
{
	if (check_sort(stack_a))
		return (0);
	if (count <= 3)
		sort_3(stack_a);
	else if (count <= 20)
		do_sort_5(stack_a, stack_b);
	else if (count <= 100)
	{
		butterfly_push(stack_a, stack_b, 15);
		sort_h(stack_a, stack_b);
	}
	else
	{
		butterfly_push(stack_a, stack_b, 30);
		sort_h(stack_a, stack_b);
	}
	return (0);
}

char	**args(char **av)
{
	int		i;
	char	*t;
	char	*res;
	char	**p;

	i = 1;
	res = ft_calloc(1, 1);
	while (av[i])
	{
		t = ft_strjoin(av[i], " ");
		res = join_free(res, t);
		free(t);
		i++;
	}
	p = ft_split(res, ' ');
	if (!p[0])
	{
		ft_putendl_fd("Error!", 1);
		exit(0);
	}
	return (free(res), p);
}

int	main(int argc, char **argv)
{
	t_stack	*stack1;
	t_stack	*stack2;
	char	**p;
	int		i;

	stack2 = NULL;
	stack1 = NULL;
	i = -1;
	p = args(argv);
	if (argc < 2 || !check_numbers(p) || !check_n(argv))
		exit(0);
	while (p[++i])
		ft_lstadd_back(&stack1, ft_lstnew(ft_atoi(p[i]), 0));
	indexes(stack1);
	push_swap(&stack1, &stack2, ft_lstsize(stack1));
	free_duble(p);
	return (0);
}
