#include "ft_push_swap.h"

int find_maximum_position(t_stack *stack_b, int *maximum, int *minimum)
{
	t_num	*current;
	int		maximum_position;
	int		i;

	current = stack_b->top;
	*maximum = current->value;
	*minimum = current->value;
	maximum_position = 0;
	i = 0;
	while (current != NULL)
	{
		if (current->value > *maximum)
		{
			*maximum = current->value;
			maximum_position = i;
		}
		if (current->value < *minimum)
			*minimum = current->value;
		current = current->next;
		i++;
	}
	return (maximum_position);
}

int	find_target_position(t_stack *stack_b, int top_a_value)
{
	t_num	*current;
	int		max;
	int		min;
	int		max_position;
	int		i;

	if (stack_b == NULL || stack_b->top == NULL)
		return (0);
	max_position = find_maximum_position(stack_b, &max, &min);
	if (top_a_value > max || top_a_value < min)
		return (max_position);
	else
	{
		current = stack_b->top;
		i = 0;
		while (current->next != NULL)
		{
			if (current->value > top_a_value && current->next->value < top_a_value)
				return (i + 1);
			current = current->next;
			i++;
		}
	}
	return (0);
}

void insert_top_value(t_stack *stack_b, t_stack *stack_a, int target_position)
{
	if ((stack_b->size / 2) >= target_position)
	{
		while (target_position > 0)
		{
			rb(stack_b);
			target_position--;
		}
	}
	else
	{
		while (target_position < stack_b->size)
		{
			rrb(stack_b);
			target_position++;
		}
	}
	pb(stack_a, stack_b);
}

void insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	target_position;
	int i;

	i = 0;
	while (stack_a->size > 0 && i < 2)
	{
		pb(stack_a, stack_b);
		i++;
	}
	while(stack_a->size > 5)
	{
		target_position = find_target_position(stack_b, stack_a->top->value);
		insert_top_value(stack_b, stack_a, target_position);
	}
	sort_five(stack_a, stack_b);
}
