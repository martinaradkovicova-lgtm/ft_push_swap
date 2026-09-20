#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_num
{
	int	value;
	int	index;
	struct s_num *next;
	struct s_num *prev;
} t_num;

typedef struct s_stack
{
	t_num	*top;
	t_num	*bottom;
	int		size;
} t_stack;

double compute_disorder(t_stack *stack_a);
#endif
