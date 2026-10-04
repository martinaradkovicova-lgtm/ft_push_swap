/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 14:13:38 by hpiotrow          #+#    #+#             */
/*   Updated: 2026/10/03 18:45:49 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* Returns how many bits are needed to represent the largest rank
 * in stack_a (size - 1), i.e. ceil(log2(size)). This is the number
 * of LSD radix passes complex_alg needs to fully sort the stack. */
int	count_bits(t_stack *stack_a)
{
	int	max_num;
	int	max_bits;

	max_num = stack_a->size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

/* Performs one LSD radix pass on bit i: sweeps every element
 * currently in stack_a once, routing it to stack_b if bit i of its
 * rank is 1, or rotating it to the back of stack_a if bit i is 0.
 * Then drains stack_b completely back into stack_a - since pb/pa
 * preserve relative order (stable), this groups elements by bit i
 * without disturbing the ordering already established by lower
 * bits. One full O(n) sweep + drain per call. */
void	radix_pass(t_stack *stack_a, t_stack *stack_b, int i)
{
	int	j;
	int	num;
	int	size;

	j = 0;
	size = stack_a->size;
	while (j < size)
	{
		num = stack_a->top->index;
		if (((num >> i) & 1) == 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		j++;
	}
	while (stack_b->size > 0)
		pa(stack_b, stack_a);
}

/* sweep stack, move 1s to stack_b, keep 0s in stack_a */
/* return all elements back from stack_b to stack_a */

/* Complex strategy, O(n log n): assigns each node a rank via
 * pre_sort, then runs one radix_pass per bit (from least to most
 * significant) over count_bits(stack_a) bits. Because each pass is
 * stable, the accumulated effect after all bits is a fully sorted
 * stack_a, with no recursion needed. */

void	complex_alg(t_stack *stack_a, t_stack *stack_b)
{
	int	bit_count;
	int	i;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (compute_disorder(stack_a) == 0.000000)
		return ;
	pre_sort(stack_a);
	bit_count = count_bits(stack_a);
	i = 0;
	while (i < bit_count)
	{
		radix_pass(stack_a, stack_b, i);
		i++;
	}
}
