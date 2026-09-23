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

void swap_stack(t_stack *stack);
void sa(t_stack *stack_a);
void sb(t_stack *stack_b);
void ss(t_stack *stack_a, t_stack *stack_b);
void rotate_stack(t_stack *stack);
void ra(t_stack *stack_a);
void rb(t_stack *stack_b);
void rr(t_stack *stack_a, t_stack *stack_b);
void reverse_rotate_stack(t_stack *stack);
void rra(t_stack *stack_a);
void rrb(t_stack *stack_b);
void rrr(t_stack *stack_a, t_stack *stack_b);
void push_stack_top(t_stack *src, t_stack *dest);
void pa(t_stack *stack_b, t_stack *stack_a);
void pb(t_stack *stack_a, t_stack *stack_b);
void sort_three(t_stack *stack_a);
void sort_four(t_stack *stack_a, t_stack *stack_b);
void simple_alg(t_stack *stack_a, t_stack *stack_b);
double compute_disorder (t_stack *stack_a);
void sort_five(t_stack *stack_a, t_stack *stack_b);
#endif
