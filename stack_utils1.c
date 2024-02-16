/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:48:49 by oruban            #+#    #+#             */
/*   Updated: 2024/02/16 16:41:57 by oruban           ###   ########.fr       */
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

// frees memory allocated for arg
void	free_after_ft_split(char **str)
{
	size_t	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	error_during_parsing(char **str, t_stack **a, int ac)
{
	if (ac == 2)
		free_after_ft_split(str);
	error_exit(a);
}
