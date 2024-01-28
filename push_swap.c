/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oruban <oruban@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:32:55 by oruban            #+#    #+#             */
/*   Updated: 2024/01/28 10:52:44 by oruban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	addnew_stacknode(t_stack **a, int nbr)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (!a)
		error_exit(a);
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		error_exit(a);
	new_node->number = nbr;
	new_node->next = NULL;
	if (!*a)
	{
		new_node->previous = NULL;
		*a = new_node;
	}
	else
	{
		last_node = *a;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new_node;
		new_node->previous = last_node;
	}
}

/* The function checks if stirng has only digits that may be preceded by + or -
details
input: a string char *
if str begings with somthing other then +, -, digit - return false
if str begings with + or - but is not followed by digit - return false
if other characters of str are not digits - return false 
returns: true or false*/
static bool	syntax(char *str)
{
	size_t	i;

	if (!(*str == '-' || *str == '+' || ft_isdigit(*str)))
		return (false);
	if ((*str == '-' || *str == '+') && !ft_isdigit(str[1]))
		return (false);
	i = 0;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (false);
	return (true);
}

/* shell initialize the list of structures called stack with int numbers
that should be sorted later on. Step by step:
1. checking the syntax of input format -/+NN(N) is only allowed 
2. checking if the number to input into the stak is int
3. checking if the number is not a duplicate
parameters: a - the pointer at the stack pointer, str - the pointer at the
array of srrings got by ft_split()*/
static void	init_stack_a(t_stack **a, char **str)
{
	size_t	i;
	long	nbr;
	t_stack	*tmp;

	i = 0;
	while (str[i])
	{
		if (!syntax(str[i]))
			error_exit(a);
		nbr = ft_atol(str[i]);
		if (nbr < INT_MIN || nbr > INT_MAX)
			error_exit(a);
		tmp = *a;
		while (tmp)
		{
			if (tmp->number == nbr)
				error_exit(a);
			tmp = tmp->next;
		}
		addnew_stacknode(a, (int) nbr);
		i++;
	}
}

int	main(int ac, char **av)
{
	char		**chr_nbr;
	t_stack		*a;
	// t_stack		*tmp;	//
	size_t		size;

	chr_nbr = NULL;
	a = NULL;
	size = 0;
	if (1 == ac || (2 == ac && !av[1][0]))
		return (1);
	if (2 == ac)
	{
		chr_nbr = ft_split(av[1], ' ');
		if (!chr_nbr)
			return (ft_printf("Error\n"), 1);
		init_stack_a(&a, chr_nbr);
	}
	else
		init_stack_a(&a, &av[1]);
	if (!issorted(a))
	{
		size = stack_size(a);
		// ft_printf("%i\n", (int) size);	//
		if (2 == size)
		{
			swap(a);	
			ft_printf("sa\n");
		}
	}
	else
		ft_printf("stack is sorted!\n");	//
	// {	// tracing the stack initiation
	// 	ft_printf("checking the stack initiation: \n");
	// 	ft_printf("%p\n", a);
	// 	tmp = a;
	// 	while (tmp)
	// 	{
	// 		ft_printf("%i ", tmp->number);
	// 		tmp = tmp->next;
	// 	}
	// 	ft_printf(" \n");
	// 	ft_printf("%p\n", a);
	// }
	free_stack(a);
}
/* ft_atoi recoded for long int. Since any number that are beyand the limits of 
LONG_MIN and LONG_MAX will be false converted into long time. We do not care 
because if the requried int will be always correctly converted */ 