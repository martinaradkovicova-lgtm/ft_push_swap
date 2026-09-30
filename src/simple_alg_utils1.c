#include "ft_push_swap.h"

int	find_maximum_position(t_stack *stack_b, int *maximum, int *minimum)
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
	t_num	*next_node;
	int		max;
	int		min;
	int		i;

	if (stack_b == NULL || stack_b->top == NULL)
		return (0);
	find_maximum_position(stack_b, &max, &min);
	if (top_a_value > max || top_a_value < min)
		return (find_maximum_position(stack_b, &max, &min));
	current = stack_b->top;
	i = 0;
	while (current != NULL)
	{
		next_node = current->next;
		if (next_node == NULL)
			next_node = stack_b->top;
		if (current->value > top_a_value && next_node->value < top_a_value)
			return (i + 1);
		current = current->next;
		i++;
	}
	return (0);
}
int	cost_stack_a(t_stack *stack_a, int index)
{
	if (index <= stack_a->size / 2)
		return (index);
	return (index - stack_a->size);
}

int	cost_stack_b(t_stack *stack_b, int value)
{
	int	target_position;

	target_position = find_target_position(stack_b, value);
	if (target_position <= (stack_b->size / 2))
		return (target_position);
	return (target_position - stack_b->size);
}

int	total_cost(int cost_a, int cost_b)
{
	int	abs_a;
	int	abs_b;

	abs_a = cost_a;
	if (cost_a < 0)
		abs_a = -cost_a;
	abs_b = cost_b;
	if (cost_b < 0)
		abs_b = -cost_b;
	if ((cost_a > 0 && cost_b > 0) || (cost_a < 0 && cost_b < 0))
	{
		if (abs_a > abs_b)
			return (abs_a);
		return (abs_b);
	}
	return (abs_a + abs_b);
}
