#include "checker_bonus.h"

void free_duble(char **p)
{
	int i;

	i = 0;
	while (p[i])
		free (p[i++]);
	free (p);
}


char **args(char **av)
{
    int i;
    char *t;
    char *res;
    char **p;

    i = 1;
    res = ft_calloc(1, 1);
    while (av[i])
    {
		
		t = ft_strjoin(av[i], " ");
       res = join_free(res, t);
       free (t);
       i ++;
    }
    p = ft_split(res, ' ');
	if (!p[0])
	{
		ft_putendl_fd("Error!", 1);
		exit (0);
	}
    return (free(res), p);
}

int main(int argc, char **argv)
{
    char **ins;
	t_stack *stack_a;
	t_stack *stack_b;
	char **p;
	int i;
	
	i = -1;
	stack_b = NULL;
	p = args(argv);
	if (argc < 2 || !check_numbers(p) || !check_n(argv))
		exit (1);
	while (p[++i])
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(p[i]), 0));
	ins = read_instructions();
	do_instracts(ins, &stack_a, &stack_b);
	if (check_sort(&stack_a) && !ft_lstsize(stack_b))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_duble (ins);
	free_duble(p);
	return (0);
	}