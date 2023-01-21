#include "checker.h"

void free_duble(char **p)
{
	int i;

	i = 0;
	while (p[i])
		free (p[i++]);
	free (p);
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

static void	fill_stack(int ac, char **av, t_stack **stack)
{
	int i;

	i = 1;
	if (ac > 1)
	{
		while (av[i])
		{
			ft_lstadd_back(stack, ft_lstnew(ft_atoi(av[i]), i - 1));
			i++;
		}
	}
}

int main(int argc, char **argv)
{
    char **ins;
	t_stack *stack_a;
	t_stack *stack_b;
	
	stack_b = NULL;
	if (argc < 2 || !check_is_number(argc, argv)
		|| !check_duplicate(argc, argv))	
			exit (1);
	fill_stack(argc, argv, &stack_a);
	ins = read_instructions();
	do_instracts(ins, &stack_a, &stack_b);
	if (check_sort(&stack_a) && !ft_lstsize(stack_b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_duble (ins);
	free_stack(&stack_a);
	free_stack(&stack_b);	
	return (0);
	}