#include "ft_push_swap.h"

// count how many bits we need
int	count_bits(t_stack *stack_a)
{
	int	max_num;
	int max_bits;

	max_num = stack_a->size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_pass(t_stack *stack_a, t_stack *stack_b, int i)
{
	int	j;
	int	num;
	int	size;

	j = 0;
	size = stack_a->size;
	while (j < size)
	{
		num = stack_a->top->index;
		if (((num >> i)&1) == 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		j++;
	}
	while (stack_b->size > 0)
		pa(stack_b, stack_a);
}

/* sweep stack, move 1s to stack_b, keep 0s in stack_a */
/* return all elements back from stack_b to stack_a */

void complex_alg(t_stack *stack_a, t_stack *stack_b)
{
	int	bit_count;
	int	i;

	if (stack_a == NULL || stack_b == NULL)
		return;
	if (compute_disorder(stack_a) == 0.000000)
		return;
	pre_sort(stack_a);
	bit_count = count_bits(stack_a);
	i = 0;
	while (i < bit_count)
	{
		radix_pass(stack_a, stack_b, i);
		i++;
	}
}
