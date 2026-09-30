#include "ft_push_swap.h"
int	find_beast_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_num	*current;
	int		i;
	int		min_cost;
	int		position;

	current = stack_a->top;
	min_cost = 2147483647;
	i = 0;
	position = 0;
	while (current != NULL)
	{
		if (total_cost(cost_stack_a(stack_a, i),
				cost_stack_b(stack_b, current->value)) < min_cost)
		{
			min_cost = total_cost(cost_stack_a(stack_a, i),
					cost_stack_b(stack_b, current->value));
			position = i;
		}
		current = current->next;
		i++;
	}
	return (position);
}

void	both_rotate(t_stack *stack_a, t_stack *stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(stack_a, stack_b);
		*cost_a -= 1;
		*cost_b -= 1;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(stack_a, stack_b);
		*cost_a += 1;
		*cost_b += 1;
	}
}

void	single_rotate(t_stack *stack_a, t_stack *stack_b, int cost_a, int cost_b)
{
	while (cost_a > 0)
	{
		ra(stack_a);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(stack_a);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(stack_b);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(stack_b);
		cost_b++;
	}
}

void	push_beast(t_stack *stack_a, t_stack *stack_b, int possition)
{
	t_num	*current;
	int		cost_a;
	int		cost_b;
	int		i;

	current = stack_a->top;
	i = 0;
	while (i < possition)
	{
		current = current->next;
		i++;
	}
	cost_a = cost_stack_a(stack_a, possition);
	cost_b = cost_stack_b(stack_b, current->value);
	both_rotate(stack_a, stack_b, &cost_a, &cost_b);
	single_rotate(stack_a, stack_b, cost_a, cost_b);
	pb(stack_a, stack_b);
}
