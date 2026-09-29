#include "ft_push_swap.h"

void adaptive_alg(t_stack *stack_a, t_stack *stack_b, double disorder)
{
	if (stack_a == NULL || stack_b == NULL)
		return;
	if (disorder == 0.0)
		return;
	else if (stack_a->size <= 5 || disorder < 0.2)
		simple_alg(stack_a, stack_b);
	else if (disorder < 0.5)
		medium_alg(stack_a, stack_b);
	else
		complex_alg(stack_a, stack_b);
}
