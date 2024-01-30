/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:45:13 by oruban            #+#    #+#             */
/*   Updated: 2024/01/30 17:55:39 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// tracing function
void tracing_t_stack_node(t_stack *a, char *name)
{
	ft_printf("node %s\n", name);
	ft_printf("%s->number = %i\n", name, a->number);
	ft_printf("%s = %p\n", name, a);
	ft_printf("%s->prev = %p\n", name, a->previous);
	ft_printf("%s->next = %p\n", name, a->next);
}

t_stack *find_last(t_stack *a)
{
	t_stack *last;
	
	last = NULL;
	while (a)
	{
		last = a;
		ft_printf("%d\n", a);
		a = a->next;
	}
	return (last);
}

void rotate(t_stack **a)
{
	t_stack	*last;
	
	last = find_last(*a);
	ft_printf("%d\n", last);
	if (!(*a && (*a)->next))
		return ;
	{	//tracing
		tracing_t_stack_node(*a, "a");
		tracing_t_stack_node((*a)->next, "b");
		tracing_t_stack_node((*a)->next->next, "c");
	}
	last->next = *a;
	(*a)->previous = last;
	*a = (*a)->next;
/* 	ft_printf("last->next->previous = %p\n", last->next->previous);
	last->next->previous = last; // last edit
	ft_printf("last->next->previous = %p\n", last->next->previous); */
	last->next->next = NULL;
	(*a)->previous = NULL;
	{	//tracing
		ft_printf("=====after rotate()=======\n");
		tracing_t_stack_node(*a, "a");
		tracing_t_stack_node((*a)->next, "b");
		tracing_t_stack_node((*a)->next->next, "c");
		/* tracing_t_stack_node(last, "last"); */
	}
}

void rrotate(t_stack **head)
{
	t_stack	*last;
	
	last = find_last(*head);
	ft_printf("%d\n", last);
	if (!(*head && (*head)->next))
		return ;
	{	//tracing
		tracing_t_stack_node(*head, "a");
		tracing_t_stack_node((*head)->next, "b");
		tracing_t_stack_node((*head)->next->next, "c");
	}
	last->next = *head;
	(*head)->previous = last;
	// ft_printf("b4 Segmentation fault\n");
	last->previous->next = NULL;
	last->previous = NULL;
	*head = last;
	{	//tracing
		ft_printf("=====after rotate()=======\n");
		tracing_t_stack_node(*head, "a");
		tracing_t_stack_node((*head)->next, "b");
		tracing_t_stack_node((*head)->next->next, "c");
		/* tracing_t_stack_node(last, "last"); */
	}
}

t_stack *find_max(t_stack *a)
{
	t_stack	*max;
	
	max = a;
	
	while (a)
	{
		if (a->number > max->number)
			max = a;
		a = a->next;
	}
	return (max);
}

void sort_stack_of3(t_stack **a)
{
	t_stack *max;
	
	max = NULL;
	if (!a)
		return ;
	max = find_max(*a);
	ft_printf("%i\n", max->number);
	ft_printf("%p\n", max);
	if (max == *a)
	{
		rotate(a);
		ft_printf("ra\n");
	}
	else if (max == (*a)->next)
	{
		rrotate(a);
		ft_printf("rra\n");
	}
}
