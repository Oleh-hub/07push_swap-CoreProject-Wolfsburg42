/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slarge_utils5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:10:01 by oruban            #+#    #+#             */
/*   Updated: 2024/02/09 12:33:51 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void node2top_itself(t_stack *src, t_stack *dst, void (*r_rr)(t_stack **),
	t_name *full_op_name) */
void	node2top_itself(t_stack **src, t_stack **dst, void (*r_rr)(t_stack **),
	t_name *full_op_name)
{
/* 	ft_printf("=====node2top_itself(), b4====="); 	//
	tracing_lst(*src, "a"); 					// tracing
	tracing_lst(*dst, "b"); 					// tracing */
	while (((*src)->push_cost) && ((*src)->target_node->push_cost))
	{
		r_rr(src);
		r_rr(dst);
		(*src)->push_cost--;
		(*src)->target_node->push_cost--;
		ft_printf("%sr\n", full_op_name->op_name);
	}
	while ((*src)->push_cost-- > 0) // ra ra ra 
	{
		r_rr(src);
		ft_printf("%s%s\n", full_op_name->op_name, full_op_name->stack_name);
	}
	while ((*src)->target_node->push_cost-- > 0)
	{
		r_rr(dst);
		if (*(full_op_name->stack_name) == 'a')
			ft_printf("%sb\n", full_op_name->op_name);
		else
			ft_printf("%sa\n", full_op_name->op_name);
	}
/* 	ft_printf("=====node2top_itself(), after====="); 	//
	tracing_lst(*src, "a"); 					// tracing
	tracing_lst(*dst, "b"); 					// tracing */
}
