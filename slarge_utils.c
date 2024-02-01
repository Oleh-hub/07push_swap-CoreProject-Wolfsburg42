/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slarge_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:48:03 by oruban            #+#    #+#             */
/*   Updated: 2024/02/01 20:33:34 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// tracing function
void tracing_t_stack_node(t_stack *a, char *name)
{
	ft_printf("======node %s=========\n", name);
	ft_printf("%s = %p\n", name, a);
	if (!a)
		return ;
	ft_printf("%s->number = %i\n", name, a->number);
	ft_printf("%s->prev = %p\n", name, a->previous);
	ft_printf("%s->next = %p\n", name, a->next);
}

void	push(t_stack **src, t_stack **dst)
{
	t_stack *tmp;
	
	{	// stacks b4
		tracing_t_stack_node(*src, "src");
		tracing_t_stack_node((*src)->next, "src->next");
		tracing_t_stack_node(*dst, "dst");
		if (*dst)
			tracing_t_stack_node((*dst)->next, "dst->next");
	}
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	if (*dst)
	{
		(*dst)->previous = tmp;
		tmp->next = *dst;
		*dst = tmp;
	}
	else
	{
		*dst = tmp;
		(*dst)->next = NULL;
		(*dst)->previous = NULL;
	}
	
	{	// stacks after
		ft_printf("========== after bp =======");
		tracing_t_stack_node(*src, "src");
		tracing_t_stack_node((*src)->next, "src->next");
		tracing_t_stack_node(*dst, "dst");
		if (*dst)
			tracing_t_stack_node((*dst)->next, "dst->next");
	}
}


void	sort_large_stack(t_stack **a)
{
	size_t		size;
	t_stack		*b;

	b = NULL;
	size = 0;
	size = stack_size(*a);
	if (size > 3 && !issorted(*a))
	{
		push(a, &b);
		ft_printf("pb\n", (int) size);
		size--;
	}
	
}
