#include "ft_push_swap.h"

char *adaptive_alg(t_stack *stack_a, t_stack *stack_b, double disorder)
{
	if (stack_a == NULL || stack_b == NULL)
		return ("none");
	if (disorder == 0.0)
		return ("none (already sorted)");
	else if (stack_a->size <= 5 || disorder < 0.2)
	{
		simple_alg(stack_a, stack_b);
		return ("simple");
	}
	else if (disorder < 0.5)
	{
		medium_alg(stack_a, stack_b);
		return ("medium");
	}
	complex_alg(stack_a, stack_b);
	return ("complex");
}
