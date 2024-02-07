/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:48:49 by oruban            #+#    #+#             */
/*   Updated: 2024/02/07 17:30:44 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swaps the first 2 elements of the stack given as  t_stack **a
void	swap(t_stack **a)
{
	if (!(*a && (*a)->next))
		return ;
	*a = (*a)->next;
	(*a)->previous->previous = *a;
	(*a)->previous->next = (*a)->next;
	if ((*a)->next)
		(*a)->next->previous = (*a)->previous;
	(*a)->next = (*a)->previous;
	(*a)->previous = NULL;
}

/* void swap(t_stack **a)
{
	if (!(*a && (*a)->next))
	{
		ft_printf("a or a->next == NULL\n"); //
		return ;
	}
	ft_printf("	a = %p\n", *a);
	ft_printf("a->number = %i\n", (*a)->number);
	ft_printf("a->prev = %p\n", (*a)->previous);
	ft_printf("a->next = %p\n", (*a)->next);
	*a = (*a)->next;
	(*a)->previous->previous = *a;
	(*a)->previous->next = (*a)->next;
	if ((*a)->next)
		(*a)->next->previous = (*a)->previous;
	(*a)->next = (*a)->previous;
	(*a)->previous = NULL;
	ft_printf("	a = %p\n", *a);
	ft_printf("a->number = %i\n", (*a)->number);
	ft_printf("a->prev = %p\n", (*a)->previous);
	ft_printf("a->next = %p\n", (*a)->next);
	ft_printf("a->next->number = %i\n", (*a)->next->number);
	ft_printf("a->next->prev = %p\n", (*a)->next->previous);
	ft_printf("a->next->next = %p\n", (*a)->next->next);
} */

size_t	stack_size(t_stack *a)
{
	size_t	i;

	if (!a)
		return (0);
	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

bool	issorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (false);
		stack = stack->next;
	}
	return (true);
}
