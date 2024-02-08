/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slarge_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:10:09 by oruban            #+#    #+#             */
/*   Updated: 2024/02/08 09:00:24 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// finds the pointer at the node with max node->number
t_stack	*max_number(t_stack	*lst)
{
	t_stack	*max_node;
	long	max_number;

	max_node = NULL;
	max_number = LONG_MIN;
	while (lst)
	{
		if (lst->number > max_number)
		{
			max_number = lst->number;
			max_node = lst;
		}
		lst = lst->next;
	}
	return (max_node);
}

// initializes st->above_median and lst->push_cost
void	push_cost_ini(t_stack *lst)
{
	size_t	max;

	max = stack_size(lst);
	while (lst)
	{
		if (lst->above_median)
			lst->push_cost = lst->index;
		else
			lst->push_cost = max - lst->index;
		lst = lst->next;
	}
}

// finds out the cheapest node to push and ini-s it with true
void	cheapest_ini(t_stack *lst)
{
	long	cheapest_cost;
	long	current_cost;
	t_stack	*cheapest_node;

	cheapest_cost = LONG_MAX;
	cheapest_node = NULL;
	while (lst)
	{
		if (lst->above_median == lst->target_node->above_median)
		{
			if (lst->push_cost > lst->target_node->push_cost)
				current_cost = lst->push_cost;
			else
				current_cost = lst->target_node->push_cost;
		}
		else
			current_cost = lst->push_cost + lst->target_node->push_cost;
		if (current_cost < cheapest_cost)
		{
			cheapest_cost = current_cost;
			cheapest_node = lst;
		}
		lst = lst->next;
	}
	cheapest_node->cheapest = true;
}

/* rr, ra, rb as well as rrr, rra, rrb to till the node to b pushed adn target 
are on the top of both stacks 
is PARAMETER char stack_name is for std output if == "a" the node is moved from 
stack a to stack b BUT if stack_name == "b", it is vice versa*/

/* funciton preparing the full operation name to print out during moving 
the node up and calling the function node2top_itself() that does the move
and prints out what is needed from rr, rrr, ra, rb, rra and rrb  */
static void	node2top(t_stack *src, t_stack *dst, void (*r_rr)(t_stack **),
	char *stack_name)
{
	t_name	*full_op_name;

	full_op_name = malloc(sizeof(t_name));
	if (!full_op_name)
		error_exit_free_2_stacks(&src, &dst);
	full_op_name->op_name = NULL;
	full_op_name->stack_name = stack_name;
	if (r_rr == rotate)
		full_op_name->op_name = ft_strdup ("r");
	else
		full_op_name->op_name = ft_strdup ("rr");
	if (!(full_op_name->op_name))
		error_exit_free_2_stacks(&src, &dst);
	node2top_itself(src, dst, r_rr, full_op_name);
	if (full_op_name)
	{
		if (full_op_name->op_name)
			free (full_op_name->op_name);
		free (full_op_name);
	}
}

/* moves the cheapest node from src inot dst using r, rr , p ... commands
where char *stack_name is either "a" or "b" and is the name of 
t_stack *src */
void	move_node(t_stack *src, t_stack *dst, char *stack_name)
{
	t_stack	*tmp;

	tmp = src;
	while (!(src->cheapest))
		src = src->next;
	if (src->above_median == src->target_node->above_median)
	{
		if (src->above_median)
			node2top(src, dst, rotate, stack_name);
		else
			node2top(src, dst, rrotate, stack_name);
	}
	else if (src->above_median) //
	{
		while ((src->push_cost)-- > 0)
		{
			rotate(&src);
			printf("r%s\n", stack_name);
		}
		
	}
	else ;
			//
	
}
