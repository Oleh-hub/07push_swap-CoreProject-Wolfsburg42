/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 09:34:52 by oruban            #+#    #+#             */
/*   Updated: 2024/02/15 20:50:32 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void node2top_itself(t_stack *src, t_stack *dst, void (*r_rr)(t_stack **),
	t_name *full_op_name) */
static void	node2top_itself(t_stack **src, t_stack **dst,
	void (*r_rr)(t_stack **), t_name *full_op_name)
{
	t_stack	*node2mv;

	node2mv = find_cheapest(*src);
	while ((node2mv->push_cost) && (node2mv->target_node->push_cost))
	{
		r_rr(src);
		r_rr(dst);
		node2mv->push_cost--;
		node2mv->target_node->push_cost--;
		ft_printf("%sr\n", full_op_name->op_name);
	}
	while (node2mv->push_cost-- > 0)
	{
		r_rr(src);
		ft_printf("%s%s\n", full_op_name->op_name, full_op_name->stack_name);
	}
	while (node2mv->target_node->push_cost-- > 0)
	{
		r_rr(dst);
		if (*(full_op_name->stack_name) == 'a')
			ft_printf("%sb\n", full_op_name->op_name);
		else
			ft_printf("%sa\n", full_op_name->op_name);
	}
}

/* rr, ra, rb as well as rrr, rra, rrb to till the node to b pushed adn target 
are on the top of both stacks 
is PARAMETER char stack_name is for std output if == "a" the node is moved from 
stack a to stack b BUT if stack_name == "b", it is vice versa*/
/* funciton preparing the full operation name to print out during moving 
the node up and calling the function node2top_itself() that does the move
and prints out what is needed from rr, rrr, ra, rb, rra and rrb  */
static void	node2top(t_stack **src, t_stack **dst, void (*r_rr)(t_stack **),
	char *stack_name)
{
	t_name	*full_op_name;

	full_op_name = malloc(sizeof(t_name));
	if (!full_op_name)
		error_exit_free_2_stacks(src, dst);
	full_op_name->op_name = NULL;
	full_op_name->stack_name = stack_name;
	if (r_rr == rotate)
		full_op_name->op_name = ft_strdup ("r");
	else
		full_op_name->op_name = ft_strdup ("rr");
	if (!(full_op_name->op_name))
		error_exit_free_2_stacks(src, dst);
	node2top_itself(src, dst, r_rr, full_op_name);
	if (full_op_name)
	{
		if (full_op_name->op_name)
			free (full_op_name->op_name);
		free (full_op_name);
	}
}

/* The next two functions also move cheapest node from one stack and 
target_node from another to the tops but in case when:
cheapest and target_node are laying by different sites of medians
that means rr or rrr operations are not possible. */
static void	move_by_rotate(t_stack **src, t_stack **dst, t_stack *node2mv,
	char *stack_name)
{
	while ((node2mv->push_cost)-- > 0)
	{
		rotate(src);
		ft_printf("r%s\n", stack_name);
	}
	while ((node2mv->target_node->push_cost)-- > 0)
	{
		rrotate(dst);
		if (*stack_name == 'a')
			ft_printf("rrb\n");
		else
			ft_printf("rra\n");
	}
}

static void	move_by_rrotate(t_stack **src, t_stack **dst, t_stack *node2mv,
	char *stack_name)
{
	while ((node2mv->push_cost)-- > 0)
	{
		rrotate(src);
		ft_printf("rr%s\n", stack_name);
	}
	while ((node2mv->target_node->push_cost)-- > 0)
	{
		rotate(dst);
		if (*stack_name == 'a')
			ft_printf("rb\n");
		else
			ft_printf("ra\n");
	}
}

/* moves the cheapest node from src inot dst using r, rr , p ... commands
where char *stack_name is either "a" or "b" and is the name of 
t_stack *src */
void	move_node(t_stack **src, t_stack **dst, char *stack_name)
{
	t_stack	*node2mv;

	node2mv = find_cheapest(*src);
	if (node2mv->above_median == node2mv->target_node->above_median)
	{
		if (node2mv->above_median)
			node2top(src, dst, rotate, stack_name);
		else
			node2top(src, dst, rrotate, stack_name);
	}
	else if (node2mv->above_median)
		move_by_rotate(src, dst, node2mv, stack_name);
	else
		move_by_rrotate(src, dst, node2mv, stack_name);
	push(src, dst);
	if (*stack_name == 'a')
		ft_printf("pb\n");
	else
		ft_printf("pa\n");
}
