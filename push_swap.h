/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:39:53 by oruban            #+#    #+#             */
/*   Updated: 2024/01/29 13:48:34 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>

// structure for stack elements 
typedef struct	s_stack
{
	int				number;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*next;
	struct s_stack	*previous;
	struct s_stack	*target_node;
} 					t_stack;
/* target_node  - for an element of stack a is the nearest smallest in 
stack b and for an element in b - the nearest biggest in stack a.
If the nearest is not found: target_node is the max and the min accodingly 
===
above_median - if a target_node is above median "rotate" ra or rb should be
executed, if not - "reverse rotate" rra or rrb*/
void 	free_stack(t_stack **a);
void	error_exit(t_stack **a);
bool	issorted(t_stack *stack);
size_t	stack_size(t_stack *a);
void swap(t_stack **a);
void sort_stack_of3(t_stack **a);
#endif