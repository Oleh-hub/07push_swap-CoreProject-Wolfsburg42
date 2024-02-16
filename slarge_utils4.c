/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slarge_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:10:09 by oruban            #+#    #+#             */
/*   Updated: 2024/02/16 10:15:16 by oruban           ###   ########.fr       */
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

/* RETURNS the pointer at the cheapest node to move */
t_stack	*find_cheapest(t_stack *src)
{
	t_stack	*node2mv;

	node2mv = src;
	while (!(node2mv->cheapest))
		node2mv = node2mv->next;
	return (node2mv);
}
