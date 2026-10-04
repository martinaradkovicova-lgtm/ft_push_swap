/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:39:29 by hpiotrow          #+#    #+#             */
/*   Updated: 2026/10/03 18:39:11 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* Simple strategy, O(n^2): dispatches by size. Sizes 0-2 are
 * handled directly (0/1 need nothing, 2 needs at most one sa),
 * sizes 3-5 use the hardcoded sort_three/four/five, and anything
 * larger falls through to insertion_sort. Guards against NULL
 * stacks and an already-sorted input before doing any work. */
void	simple_alg(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (compute_disorder(stack_a) == 0.000000)
		return ;
	if (stack_a->size <= 1)
		return ;
	else if (stack_a->size == 2)
	{
		if (stack_a->top->value > stack_a->top->next->value)
			sa(stack_a);
		return ;
	}
	if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size == 4)
		sort_four(stack_a, stack_b);
	else if (stack_a->size == 5)
		sort_five(stack_a, stack_b);
	else
		insertion_sort(stack_a, stack_b);
}

/* Cost-based insertion sort for stacks larger than 5:
 * seeds stack_b with the first two elements, then repeatedly finds
 * the element in stack_a whose insertion into stack_b is cheapest
 * (find_beast_cost) and moves it there using the fewest combined
 * rotations (push_beast). Once stack_a is empty, align_stack_b
 * rotates the true maximum to the top of stack_b so the final
 * drain (repeated pa) rebuilds stack_a in ascending order. */
void	insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	position;

	if (stack_a->size > 0)
		pb(stack_a, stack_b);
	if (stack_a->size > 0)
		pb(stack_a, stack_b);
	while (stack_a->size > 0)
	{
		position = find_beast_cost(stack_a, stack_b);
		push_beast(stack_a, stack_b, position);
	}
	align_stack_b(stack_b);
	while (stack_b->size > 0)
		pa(stack_b, stack_a);
}
