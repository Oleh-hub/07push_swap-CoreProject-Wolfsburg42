/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slarge_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:10:09 by oruban            #+#    #+#             */
/*   Updated: 2024/02/05 14:00:28 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// tracing function 4 debug
void	tracing_t_stack_node(t_stack *a, char *name)
{
	ft_printf("======node %s=========\n", name);
	ft_printf("%s = %p\n", name, a);
	if (!a)
		return ;
	ft_printf("%s->number = %i\n", name, a->number);
	ft_printf("%s->index = %i\n", name, a->index);
	ft_printf("%s->above_median = %i\n", name, a->above_median);
	ft_printf("%s->push_cost = %i\n", name, a->push_cost);
	ft_printf("%s->cheapest = %i\n", name, a->cheapest);
	ft_printf("%s->target_node = %p\n", name, a->target_node);
	if (a->target_node)
		ft_printf("%s->target_node->number = %d\n", name,
			a->target_node->number);
	ft_printf("%s->prev = %p\n", name, a->previous);
	ft_printf("%s->next = %p\n", name, a->next);
}
// tracing list lst
void	tracing_lst(t_stack *lst, char *name)
{
	if (!lst)
	{
		printf("list %s = NULL", name);
		return ;
	}
	while (lst)
	{
		tracing_t_stack_node(lst, name);
		lst = lst->next;
	}
}

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
	size_t max;
	
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