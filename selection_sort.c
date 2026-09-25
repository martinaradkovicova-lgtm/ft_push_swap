#include "ft_push_swap.h"

int find_minimum(t_stack *stack)
{
	int	minimum;
	int	min_position;
	int i;
	t_num	*current_num;

	current_num = stack->top;
	minimum = corrent_num->value;
	min_pos = 0;
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

void push_minimum(t_stack *Stack_a, t_stack *Stack_b, int min_pos)
{
	if (ft_is_negative(min_pos))
	{
		while (min_pos < 0)
		{
			rra(Stack_a);
			min_pos++;
		}
	}
	else
	{
		while (min_pos > 0)
		{
			ra(Stack_a);
			min_pos--;
		}
	}
	pb(Stack_a, Stack_b);
}

void selection_sort(t_stack *Stack_a, t_stack *Stack_b)
{
	int min_position;
	
	while (Stack_a->size > 5)
	{
		min_position = find_minimum(Stack_a);
		push_minimum(Stack_a, Stack_b, min_position);
	}
	sort_five(Stack_a);
	while (Stack_b->size > 0)
	{
		pa(Stack_b, Stack_a);
	}
}

