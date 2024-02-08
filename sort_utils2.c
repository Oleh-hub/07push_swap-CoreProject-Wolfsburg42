/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:45:13 by oruban            #+#    #+#             */
/*   Updated: 2024/02/08 19:52:47 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_last(t_stack *a)
{
	t_stack	*last;

	last = NULL;
	while (a)
	{
		last = a;
		a = a->next;
	}
	return (last);
}

void	rotate(t_stack **a)
{
	t_stack	*last;

	last = find_last(*a);
	if (!(*a && (*a)->next))
		return ;
	last->next = *a;
	(*a)->previous = last;
	*a = (*a)->next;
	last->next->next = NULL;
	(*a)->previous = NULL;
}

void	rrotate(t_stack **head)
{
	t_stack	*last;

	last = find_last(*head);
	if (!(*head && (*head)->next))
		return ;
	last->next = *head;
	(*head)->previous = last;
	last->previous->next = NULL;
	last->previous = NULL;
	*head = last;
}

t_stack	*find_max(t_stack *a)
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

void	sort_stack_of3(t_stack **a)
{
	t_stack	*max;

	max = NULL;
	if (!a)
		return ;
	max = find_max(*a);
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
	if ((*a)->number > (*a)->next->number)
	{
		swap(a);
		ft_printf("sa\n");
	}
}
