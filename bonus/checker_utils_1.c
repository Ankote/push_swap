/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:21:01 by aankote           #+#    #+#             */
/*   Updated: 2023/02/05 12:21:05 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_instructs(char *ptr)
{
	char	**p;
	char	*inst;
	int		i;

	i = 0;
	inst = ft_strdup("sa sb ss ra rb rr rra rrb rrr pa pb");
	p = ft_split(inst, ' ');
	while (p[i])
	{
		if (!ft_strncmp(p[i], ptr, ft_strlen(ptr) - 1)
			&& ft_strlen(p[i]) == ft_strlen(ptr) - 1)
			return (free_duble(p), free(inst), 1);
		i++;
	}
	return (free_duble(p), free(inst), 0);
}

char	**read_instructions(void)
{
	char	*res;
	char	*buff;
	char	**p;

	res = ft_calloc(1, 1);
	while (1)
	{
		buff = get_next_line(0);
		if (!buff)
			break ;
		res = join_free(res, buff);
		if (!check_instructs(buff))
		{
			ft_putendl_fd("Error", 1);
			free(buff);
			exit(0);
		}
		free(buff);
	}
	p = ft_split(res, '\n');
	free(res);
	return (p);
}

static void	instracts(t_stack **stack_a, t_stack **stack_b, char *p)
{
	if (!ft_strncmp(p, "sa", 2))
		do_sa(stack_a);
	else if (!ft_strncmp(p, "sb", 2))
		do_sb(stack_a);
	else if (!ft_strncmp(p, "ss", 2))
		do_ss(stack_a, stack_b);
	else if (!ft_strncmp(p, "ra", 2))
		do_ra(stack_a);
	else if (!ft_strncmp(p, "rb", 2))
		do_rb(stack_b);
	else if (!ft_strncmp(p, "rra", 3))
		do_rra(stack_a);
	else if (!ft_strncmp(p, "rrb", 3))
		do_rrb(stack_b);
	else if (!ft_strncmp(p, "rrr", 3))
		do_rrb(stack_b);
	else if (!ft_strncmp(p, "rr", 2))
		do_rrr(stack_a, stack_b);
	else if (!ft_strncmp(p, "pa", 2))
		do_pa(stack_a, stack_b);
	else if (!ft_strncmp(p, "pb", 2))
		do_pb(stack_a, stack_b);
}

int	do_instracts(char **p, t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	while (p[i])
	{
		instracts(stack_a, stack_b, p[i]);
		i++;
	}
	return (1);
}
