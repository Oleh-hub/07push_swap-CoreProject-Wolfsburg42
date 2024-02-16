/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:39:53 by oruban            #+#    #+#             */
/*   Updated: 2024/02/16 17:16:06 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>

// structure for stack elements 
typedef struct s_stack
{
	int				number;
	int				index;
	bool			above_median;
	int				push_cost;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*previous;
}					t_stack;
/* target_node  - for an element of stack a is the nearest smallest in 
stack b and for an element in b - the nearest biggest in stack a.
If the nearest is not found: target_node is the max and the min accodingly 
===
above_median - if a target_node is above median "rotate" ra or rb should be
executed, if not - "reverse rotate" rra or rrb*/
void	free_stack(t_stack **a);
void	error_exit(t_stack **a);
void	error_exit_free_2_stacks(t_stack **a, t_stack **b);
bool	issorted(t_stack *stack);
size_t	stack_size(t_stack *a);
void	swap(t_stack **a);
void	sort_stack_of3(t_stack **a);
void	sort_large_stack(t_stack **a);
void	push(t_stack **src, t_stack **dst);
// b4 pushb
t_stack	*max_number(t_stack	*lst);
// b4 pusha
t_stack	*min_number(t_stack *lst);
void	push_cost_ini(t_stack *lst);
void	cheapest_ini(t_stack *lst);
void	rotate(t_stack **a);
void	rrotate(t_stack **head);
void	move_node(t_stack **src, t_stack **dst, char *stack); /* char stack is
 just the 'from' stack name if it is a ´pb´ follows */

/* structure and functions using it */
typedef struct s_name
{
	char	*op_name;
	char	*stack_name;
}				t_name;
/* static void	node2top(t_stack *src, t_stack *dst, void (*r_rr)(t_stack **),
	char *stack_name); */
/* void node2top_itself(t_stack **src, t_stack **dst, void (*r_rr)(t_stack **),
	t_name *full_op_name); */
t_stack	*find_cheapest(t_stack *src);
// frees memory allocated for argument string by ft_split
void	free_after_ft_split(char **str);
void	error_during_parsing(char **str, t_stack **a, int ac);

/* Moves nodes from already sorted stack b back into stack a.
Target_nodes in a are the "nearest bigger". */
void	move_stack_b2a(t_stack **a, t_stack **b);
// soritng the stak when it is larger then 3 nodes
void	sort_large_stack(t_stack **a);
void	stacks_ini(t_stack *a, t_stack *b);
void	b2a_target_ini(t_stack *src, t_stack *dst);
void	index_median_ini(t_stack *lst);

/* Debugging functions: */
void	tracing_t_stack_node(t_stack *a, char *name); // debug tracing
void	tracing_lst(t_stack *lst, char *name); // debug, lst tracing
#endif