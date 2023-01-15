/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aankote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:52:21 by aankote           #+#    #+#             */
/*   Updated: 2023/01/04 15:52:22 by aankote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;
typedef struct s_vers
{
	int 			*tb;
	int				i;
	int				x;
	int				y;
}					t_vars;
void				swap(t_stack **stack);
t_stack				*ft_lstnew(int value, int index);
void				ft_lstadd_front(t_stack **lst, t_stack *new);
void				ft_lstadd_back(t_stack **lst, t_stack *new);
int					ft_lstsize(t_stack *lst);
t_stack				*ft_lstlast(t_stack *lst);
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
void				do_pp(t_stack **stack_a, t_stack **stack_b);
void				indexes(t_stack *stack);
int					check_sort(t_stack **stack);
int					small(t_stack **stack);
void				sort_3(t_stack **stack_a);
void				do_sort_5(t_stack **stack_a, t_stack **stack_b);
int					big(t_stack **stack);
void				do_sort_4(t_stack **stack_a, t_stack **stack_b);
void				do_sort_5(t_stack **stack_a, t_stack **stack_b);
int					*sort_table(t_stack **stack);
t_stack				**butterfly_push(t_stack **stack_a, t_stack **stack_b, int base);
void				sort_h(t_stack **stack_a, t_stack **stack_b);
int					check_duplicate(t_stack *stack_a);
#endif
