/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 12:22:56 by hpiotrow          #+#    #+#             */
/*   Updated: 2026/10/03 18:44:53 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* Computes the disorder metric for stack_a, per the mandatory
 * definition: for every pair (i, j) with i above j in the stack,
 * count a "mistake" if i's value is greater than j's (i.e. they're
 * out of order). Returns mistakes / total_pairs, a fraction from
 * 0 (already sorted) to 1 (fully reverse-sorted). Must be called
 * before any moves, since it's measuring the starting state.
 * Returns 0 for a NULL, empty, or single-element stack (no pairs
 * to compare, so disorder is trivially 0). O(n^2) time, O(1) space. */
double	compute_disorder(t_stack *stack_a)
{
	t_num	*i;
	t_num	*j;
	int		mistakes;
	int		total_pairs;

	if (stack_a == NULL || stack_a->top == NULL || stack_a->top->next == NULL)
	{
		return (0.00);
	}
	mistakes = 0;
	total_pairs = (stack_a->size * (stack_a->size - 1)) / 2;
	i = stack_a->top;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return ((double)mistakes / (double)total_pairs);
}
