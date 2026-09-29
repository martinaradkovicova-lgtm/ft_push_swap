#include "ft_push_swap.c"

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

int cost_a(t_stack *stack_a, int index)
{
	if (index <= stack_a->size / 2)
		return (index); //top part, middle (ra) 
	return (index - stack_a->size) //bottom (rra)
}

int cost_b(t_stack *stack_b, int value)
{
	int	target_position;

	target_position = find_target_position(stack_b, value);
	if (target_position <= (stack_b->size / 2))
		return (target_pos); //top part, middle (rb)
	return (target_position - stack_b->size); //bottom (rrb)
}
