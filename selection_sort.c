#include "ft_push_swap.h"

int find_minimum(t_stack *stack)
{
	int	minimum;
	int	min_position;
	int i;
	t_num	*current_num;

	current_num = stack->top;
	minimum = current_num->value;
	min_position = 0;
	i = 0;
	while (current_num != NULL)
	{
		if (current_num->value < minimum)
		{
			minimum = current_num->value;
			min_position = i;
		}
		current_num = current_num->next;
		i++;
	}
	if ((stack->size / 2) < min_position)
		min_position = (stack->size - min_position) * (-1);
	return (min_position);
}

void push_minimum(t_stack *stack_a, t_stack *stack_b, int min_pos)
{
	if (min_pos < 0)
	{
		while (min_pos < 0)
		{
			rra(stack_a);
			min_pos++;
		}
	}
	else
	{
		while (min_pos > 0)
		{
			ra(stack_a);
			min_pos--;
		}
	}
	pb(stack_a, stack_b);
}

void selection_sort(t_stack *stack_a, t_stack *stack_b)
{
	int min_position;
	
	while (stack_a->size > 5 && compute_disorder(stack_a) > 0.000000)
	{
		min_position = find_minimum(stack_a);
		push_minimum(stack_a, stack_b, min_position);
	}
	sort_five(stack_a,stack_b);
	while (stack_b->size > 0)
	{
		pa(stack_b, stack_a);
	}
}

