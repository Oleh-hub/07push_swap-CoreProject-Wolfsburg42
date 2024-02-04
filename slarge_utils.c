/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slarge_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:48:03 by oruban            #+#    #+#             */
/*   Updated: 2024/02/04 10:03:04 by oruban           ###   ########.fr       */
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
	ft_printf("%s->index = %i\n", name, a->index);
	ft_printf("%s->target_node = %p\n", name, a->target_node);
	ft_printf("%s->prev = %p\n", name, a->previous);
	ft_printf("%s->next = %p\n", name, a->next);
}

void	push(t_stack **src, t_stack **dst)
{
	t_stack *tmp;
	
/* 	{	// stacks b4
		tracing_t_stack_node(*src, "src");
		tracing_t_stack_node((*src)->next, "src->next");
		tracing_t_stack_node(*dst, "dst");
		if (*dst)
			tracing_t_stack_node((*dst)->next, "dst->next");
	} */
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
	
/* 	{	// stacks after
		ft_printf("========== after bp =======");
		tracing_t_stack_node(*src, "src");
		tracing_t_stack_node((*src)->next, "src->next");
		tracing_t_stack_node(*dst, "dst");
		if (*dst)
			tracing_t_stack_node((*dst)->next, "dst->next");
	} */
}

//initialisation of ->index ans ->above_median elements of the stack
static void index_median_ini(t_stack *a)
{
	size_t i;
	size_t median;

	if (!a)
		return ;
	i = 0;
	median = stack_size(a)/2;
	while (a)
	{
		a->index = i;
		if (i <= median)
			a->above_median = true;
		else
			a->above_median = false;
		a = a->next;
		i++;	
	}
}

// finds the pointer at the node with max node->number
static t_stack	*max_number(t_stack	*lst)
{
	t_stack	*max_node;
	long 	max_number;
	
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

// find for every node of src list the target node in dst list
/* max is maximum number in dst
targeted indicates if the number less than src one was found in dst and 
the target_node was therefore found */
static void target_ini(t_stack *src, t_stack *dst)
{
	t_stack	*tmp;
	bool	targeted;
	
	if (!src || !dst)
		return ;
	targeted = false;
	tmp = dst;
	while (src)
	{
		dst = tmp;
		while (dst)
		{
			if (dst->number < src->number && (!src->target_node ||
				 dst->number > src->target_node->number))
			{
				src->target_node = dst;
				targeted = true;
			}
			dst = dst->next;
		}
		if (!targeted)
			{
				// tracing_t_stack_node(tmp, "b"); //
				src->target_node = max_number(tmp);
			}
		tracing_t_stack_node(src, "a"); //
		src = src->next;
	}
}

// initialisation of both stacks b4 sorting
static void stacks_ini(t_stack *a, t_stack *b)
{
	index_median_ini(a);
	index_median_ini(b);
	target_ini(a, b);
	
}

// soritng the stak when it is larger then 3 nodes
void	sort_large_stack(t_stack **a)
{
	size_t		size;
	t_stack		*b;
	int			i;

	b = NULL;
	size = 0;
	i = 2;
	size = stack_size(*a);
	while (size > 3 && !issorted(*a) && i--)
	{
		push(a, &b);
		ft_printf("pb %i\n", (int) size);
		size--;
	}
	/* {	//
		ft_printf("size =  %i\n", (int) size);
		tracing_t_stack_node(b, "b");
		tracing_t_stack_node(b->next, "b");
		tracing_t_stack_node(b->next->next, "b");
	} */
	while (size-- > 3 && !issorted(*a))
	{
		stacks_ini(*a, b);
	}
	ft_printf("sorted!\n");
}
