/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slarge_utils5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:10:01 by oruban            #+#    #+#             */
/*   Updated: 2024/02/09 17:00:01 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void node2top_itself(t_stack *src, t_stack *dst, void (*r_rr)(t_stack **),
	t_name *full_op_name) */
void	node2top_itself(t_stack **src, t_stack **dst, void (*r_rr)(t_stack **),
	t_name *full_op_name)
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

/* RETURNS the pointer at the cheapest node to move */
t_stack	*find_cheapest(t_stack *src)
{
	t_stack	*node2mv;

	node2mv = src;
	while (!(node2mv->cheapest))
		node2mv = node2mv->next;
	return (node2mv);
}