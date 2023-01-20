#ifndef CHECKER_H
# define CHECKER_H
#include <fcntl.h>
# include "get_next_line/get_next_line.h"
# include "../libft/libft.h"
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;
void				do_sa(t_stack **stack_a);
void				do_sb(t_stack **stack_b);
void				do_ss(t_stack **stack_a, t_stack **stack_b);
void				do_ra(t_stack **stack_a);
void				do_rr(t_stack **stack_a, t_stack **stack_b);
void				do_rb(t_stack **stack_b);
void				do_rra(t_stack **stack);
void				do_rrb(t_stack **stack);
void				do_rrr(t_stack **stack_a, t_stack **stack_b);
void				do_pa(t_stack **stack_a, t_stack **stack_b);
void				do_pb(t_stack **stack_a, t_stack **stack_b);
t_stack	            *ft_lstnew(int value, int index);
void	            ft_lstadd_back(t_stack **lst, t_stack *new);
int                 ft_lstsize(t_stack *lst);
void	            indexes(t_stack *stack);
int                 check_sort(t_stack **stack);
# endif