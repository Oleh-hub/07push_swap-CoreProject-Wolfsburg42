/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slarge_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:48:03 by oruban            #+#    #+#             */
/*   Updated: 2024/02/16 17:06:33 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* pushes nodes from list (named stack) src into stack dst */
void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

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
}

//initialisation of ->index ans ->above_median elements of the stack and
// ->push_cost to 0, sets ->cheapest and ->target_node to false and NULL
void	index_median_ini(t_stack *lst)
{
	size_t	i;
	size_t	size;
	size_t	median;

	if (!lst)
		return ;
	i = 0;
	size = stack_size (lst);
	median = size / 2 + size % 2;
	while (lst)
	{
		lst->index = i;
		if (i < median)
			lst->above_median = true;
		else
			lst->above_median = false;
		lst->push_cost = 0;
		lst->cheapest = false;
		lst->target_node = NULL;
		lst = lst->next;
		i++;
	}
}

/* ini all lst->target_node with NULL. For debugging perposis. Somehow with
debug extantion I often have rubbish in src->target_node*/
/* static void target2null_ini(t_stack *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		lst->target_node = NULL;
		lst = lst->next;
	}
} */
/* find for every node of src list the target node in dst list */
/* max is maximum number in dst
targeted indicates if the number less than src one was found in dst and 
the target_node was therefore found */
static void	target_ini(t_stack *src, t_stack *dst)
{
	t_stack	*tmp;
	bool	targeted;

	if (!src || !dst)
		return ;
	tmp = dst;
	while (src)
	{
		targeted = false;
		dst = tmp;
		while (dst)
		{
			if (dst->number < src->number && (!src->target_node
					|| (dst->number > src->target_node->number)))
			{
				src->target_node = dst;
				targeted = true;
			}
			dst = dst->next;
		}
		if (!targeted)
			src->target_node = max_number(tmp);
		src = src->next;
	}
}

/* initialisation (finding out the correct element to push) of both stacks b4 
sorting (moving the correct element to another stack).
wher epush_cost_ini assingns ->push_cost with the number of r or rr needed
to get to the top of the stack */
void	stacks_ini(t_stack *a, t_stack *b)
{
	index_median_ini(a);
	index_median_ini(b);
	target_ini(a, b);
	push_cost_ini(a);
	push_cost_ini(b);
	cheapest_ini(a);
}

/* ini ->target_node 4 all noeds in stack b. Target_nodes in a are the 
"nearest bigger". If the closest bigger is not found, tehn target node 
is the 'min' value.*/
void	b2a_target_ini(t_stack *src, t_stack *dst)
{
	t_stack	*tmp;
	bool	targeted;

	if (!src || !dst)
		return ;
	tmp = dst;
	while (src)
	{
		targeted = false;
		dst = tmp;
		while (dst)
		{
			if (dst->number > src->number && (!src->target_node
					|| (dst->number < src->target_node->number)))
			{
				src->target_node = dst;
				targeted = true;
			}
			dst = dst->next;
		}
		if (!targeted)
			src->target_node = min_number(tmp);
		src = src->next;
	}
}
