/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slarge_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 09:48:03 by oruban            #+#    #+#             */
/*   Updated: 2024/01/31 21:31:11 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	push(t_stack **src, t_stack **dest)
{
	if (!*src)
		return ;
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
