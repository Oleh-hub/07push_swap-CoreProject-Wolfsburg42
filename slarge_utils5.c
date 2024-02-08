/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slarge_utils5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:10:01 by oruban            #+#    #+#             */
/*   Updated: 2024/02/08 19:32:24 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void node2top_itself(t_stack *src, t_stack *dst, void (*r_rr)(t_stack **),
	t_name *full_op_name) */
void	node2top_itself(t_stack *src, t_stack *dst, void (*r_rr)(t_stack **),
	t_name *full_op_name)
{
	while ((src->push_cost) && (src->target_node->push_cost))
	{
		r_rr(&src);
		r_rr(&dst);
		src->push_cost--;
		src->target_node->push_cost--;
		ft_printf("%sr\n", full_op_name->op_name);
	}
	while (src->push_cost--) // ra ra ra 
	{
		// ft_printf("================\n"); 	//
		// tracing_lst(src, "a");				//
		r_rr(&src);
		// ft_printf("================\n"); 	//
		// tracing_lst(src, "a");				//
		// exit(1);							//
		ft_printf("%s%s\n", full_op_name->op_name, full_op_name->stack_name);
	}
	while (src->target_node->push_cost--)
	{
		r_rr(&dst);
		if (*(full_op_name->stack_name) == 'a')
			ft_printf("%sb\n", full_op_name->op_name);
		else
			ft_printf("%sa\n", full_op_name->op_name);
	}
}
