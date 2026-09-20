#include "ft_push_swap.h"
#include <stdio.h>

double compute_disorder (t_stack *stack_a)
{
	t_num	*i;
	t_num	*j;
	int		mistakes;
	int		total_pairs;

	if (stack_a == NULL || stack_a->top == NULL || stack_a->top->next == NULL)
	{
		printf("stack error\n"); //DEBUG
		return (0.00);
	}
	mistakes = 0;
	printf("\nsize = %i\n", stack_a->size); //DEBUG
	total_pairs = (stack_a->size * (stack_a->size - 1)) / 2;
	i = stack_a->top;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if(i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return ((double)mistakes / (double)total_pairs);
}
