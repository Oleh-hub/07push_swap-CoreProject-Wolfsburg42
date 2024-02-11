/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others99.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:34:15 by oruban            #+#    #+#             */
/*   Updated: 2024/02/10 18:57:30 by oruban           ###   ########.fr       */
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
	if (a->target_node && a->target_node->number) // 4 cases when target_node == rubbish as for b stack b4 ini.
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

void	free_stack(t_stack **a)
{
	t_stack	*tmp_node;

	if (!*a)
		return ;
	while (*a)
	{
		tmp_node = *a;
		*a = tmp_node->next;
		free(tmp_node);
	}
	*a = NULL;
}

/* fees memory allocated for the stack and
	 exits from the programm because of input errors 
	PARAMETERS:  pointer at the pointer to the stack
	RETURNS: 	nothing*/
void	error_exit(t_stack **a)
{
	if (*a)
		free_stack(a);
	ft_printf("Error\n");
	exit(1);
}

void	error_exit_free_2_stacks(t_stack **a, t_stack **b)
{
	free_stack(b);
	error_exit(a);
}
