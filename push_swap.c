#include "push_swap.h"
#include <stdio.h>

int main (int ac, char **av)
{
	char 		**int_nbr;
	// t_stack		*a;
	
	int_nbr = NULL;
	if (1 == ac)
		return (1);
	
	while (*av[1])			//
	{
		write(1, av[1], 1);
		av[1]++;
	}
	write(1, "\n", 1);		//

	if (2 == ac)
		int_nbr = ft_split(av[1], ' ');
	// if (NULL == int_nbr)
	// {
	// 	ft_printf("Error\n");
	// 	return (1); 
	// }
	
	for (int i = 0; int_nbr[i]; i++)	//
		ft_printf("%s\n", int_nbr[i]);	//

	
}