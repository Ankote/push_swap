#include "checker.h"

void free_duble(char **p)
{
	int i;

	i = 0;
	while (p[i])
		free (p[i++]);
	free (p);
}

char **read_instructions()
{
    char    *res;
    char    *buff;
	char	**p;

    
    res = ft_calloc(1, 1);
    while (1)
    {
        buff = get_next_line(0);
        if (!buff)
            break;
        res = join_free(res, buff);
        free (buff);
    }
	p = ft_split(res, '\n');
	free (res);
    return (p);
}

int checher_util(t_stack **stack_a, t_stack **stack_b, char *p)
{
		if(!ft_strncmp(p, "sa", 2))
			do_sa(stack_a);
		else if(!ft_strncmp(p, "sb", 2))
			do_sb(stack_a);
		else if(!ft_strncmp(p, "ss", 2))
			do_ss(stack_a, stack_b);
		else if(!ft_strncmp(p, "ra", 2))
			do_ra(stack_a);
		else if(!ft_strncmp(p, "rb", 2))
			do_ra(stack_b);
		else if(!ft_strncmp(p, "rra", 3))
			do_rra(stack_a);
		else if(!ft_strncmp(p, "rrb", 3))
			do_rrb(stack_b);
		else if(!ft_strncmp(p, "rr", 2))
			do_rr(stack_a, stack_b);
		else if(!ft_strncmp(p, "pa", 2))
			do_pa(stack_a, stack_b);
		else if(!ft_strncmp(p, "pb", 2))
			do_pb(stack_a, stack_b);
		else
			return (0);
		return (1);	
}

int checker(char **p, t_stack *stack_a, t_stack *stack_b)
{
	int i;

	i = 0;
	while (p[i])
	{
		if (!checher_util(&stack_a, &stack_b, p[i]))
			return (free_duble(p), 0);
		i ++;
	}
	return (free_duble(p), 1);
}

// void	fill_stack(int ac, char **av, t_stack *stack)
// {
// 	int i;

// 	i = 1;
// 	if (ac > 1)
// 	{
// 		while (av[i])
// 		{
// 			ft_lstadd_back(&stack, ft_lstnew(ft_atoi(av[i]), i - 1));
// 			i++;
// 		}
// 	}
// }


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

int main(int argc, char **argv)
{
    char **ins;
	t_stack *stack_a;
	t_stack *stack_b;

	stack_b = NULL;
	stack_a = NULL;
	int i =1;
	while (argv[i] && argc)
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(argv[i]), i - 1));
		i++;
	}
	ins = read_instructions();
	if (!checker(ins, stack_a, stack_b))
		printf("Error\n");
	if (check_sort(&stack_a))
		ft_putendl_fd("OK\n", 1);
	else
		ft_putendl_fd("KO\n", 1);
	free_stack(&stack_a);
	free_stack(&stack_b);
}