#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include <limits.h>

typedef struct	s_stack
{
	long			number;
	unsigned int	index;
	struct s_stack	*next;
	struct s_stack	*previous;

} 				t_stack;
#endif