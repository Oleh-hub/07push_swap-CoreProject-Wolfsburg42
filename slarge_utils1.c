/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slarge_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:10:09 by oruban            #+#    #+#             */
/*   Updated: 2024/02/04 14:12:13 by oruban           ###   ########.fr       */
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
	ft_printf("%s->target_node = %p\n", name, a->target_node);
	if (a->target_node)
		ft_printf("%s->target_node->number = %d\n", name,
			a->target_node->number);
	ft_printf("%s->prev = %p\n", name, a->previous);
	ft_printf("%s->next = %p\n", name, a->next);
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
