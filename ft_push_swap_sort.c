#include "ft_push_swap.h"


void simple_alg(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	if (stack_a == NULL || stack_b == NULL)
		return;
	if (stack_a->size == 3)
	{
		sort_three(stack_a);
	}
    else if (stack_a->size == 4)
		sort_four(stack_a, stack_b);
}

void sort_three(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;

	if (stack_a == NULL || stack_a->size < 3)
		return ;

	a = stack_a->top->value;
	b = stack_a->top->next->value;
	c = stack_a->top->next->next->value;

	if (a > b && b > c)           //B: 3 2 1
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a < b && b > c && a < c) //C: 1 3 2
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (a < b && b > c && a > c) //D: 2 3 1
		rra(stack_a);
	else if (a > b && b < c && a < c) //E: 2 1 3
		sa(stack_a);
	else if (a > b && b < c && a > c) //F: 3 1 2
		ra(stack_a);
}

int minimum_index(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	minimum_idx;
	
	a = stack_a->top->value;
	b = stack_a->top->next->value;
	c = stack_a->bottom->prev->value;
	d = stack_a->bottom->value;
	if ((a < b) && (a < c) && (a < d))
		minimum_idx = 0;
	else if ((b < a) && (b < c) && (b < d))
		minimum_idx = 1;
	else if ((c < a) && (c < b) && (c < d))
		minimum_idx = 2;
	else
		minimum_idx = 3;
	return (minimum_idx);
}
void sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int minimum_idx;

	minimum_idx = minimum_index(stack_a);
	
	if (minimum_idx == 1)
		sa(stack_a);
	else if (minimum_idx == 2)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (minimum_idx == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_b, stack_a);
}
