#include "ft_push_swap.h"

void	align_stack_b(t_stack *stack_b)
{
	int	max;
	int	min;
	int	max_pos;

	if (!stack_b || !stack_b->top)
		return ;
	max_pos = find_maximum_position(stack_b, &max, &min);
	if (max_pos <= stack_b->size / 2)
	{
		while (max_pos-- > 0)
			rb(stack_b);
	}
	else
	{
		while (max_pos++ < stack_b->size)
			rrb(stack_b);
	}
}

void	insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	position;

	if (stack_a->size > 0)
		pb(stack_a, stack_b);
	if (stack_a->size > 0)
		pb(stack_a, stack_b);
	while (stack_a->size > 0)
	{
		position = find_beast_cost(stack_a, stack_b);
		push_beast(stack_a, stack_b, position);
	}
	align_stack_b(stack_b);
	while (stack_b->size > 0)
		pa(stack_b, stack_a);
}
