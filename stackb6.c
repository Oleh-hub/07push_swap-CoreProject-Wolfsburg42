/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackb6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:53:04 by oruban            #+#    #+#             */
/*   Updated: 2024/02/16 17:27:52 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Moves nodes from already sorted stack b back into stack a.
Target_nodes in a are the "nearest bigger". */
void	move_stack_b2a(t_stack **a, t_stack **b)
{
	while (*b)
	{
		index_median_ini(*a);
		index_median_ini(*b);
		b2a_target_ini(*b, *a);
		push_cost_ini(*b);
		push_cost_ini(*a);
		cheapest_ini(*b);
		move_node(b, a, "b");
	}
}

// soritng the stak when it is larger then 3 nodes
void	sort_large_stack(t_stack **a)
{
	size_t		size;
	t_stack		*b;
	int			i;
	t_stack		*min_nbr;

	b = NULL;
	size = 0;
	i = 2;
	size = stack_size(*a);
	while (size > 3 && !issorted(*a) && i--)
	{
		push(a, &b);
		ft_printf("pb\n");
		size--;
	}
	while (size-- > 3 && !issorted(*a))
	{
		stacks_ini(*a, b);
		move_node(a, &b, "a");
	}
	sort_stack_of3(a);
	move_stack_b2a(a, &b);
	index_median_ini(*a);
	min_nbr = min_number(*a);
	if (min_nbr->above_median)
		while ((*a) != min_nbr)
		{
			rotate(a);
			ft_printf("ra\n");
		}
	else
		while ((*a) != min_nbr)
		{
			rrotate(a);
			ft_printf("rra\n");
		}
}
