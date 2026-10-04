/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_alg_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 12:05:29 by hpiotrow          #+#    #+#             */
/*   Updated: 2026/10/03 18:41:40 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* Scans stack_b and returns the position (0 = top) of its largest
 * value, while also reporting the largest and smallest values seen
 * via *maximum/*minimum - used both to locate the max for rotation
 * and to let find_target_position know the stack's current range. */
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

/* Finds where top_a_value would need to land in stack_b to keep it
 * sorted (descending from top): if it's outside stack_b's current
 * range, that's the max's position (it belongs right there); other-
 * wise walks stack_b looking for the adjacent pair it sits between,
 * wrapping past the bottom back to the top so the search covers the
 * whole circular order. Returns 0 if stack_b is NULL or empty. */
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

/* Converts a raw index in stack_a into a signed rotation cost: a
 * positive value means "ra this many times", a negative value
 * means "rra this many times" (whichever is shorter, based on
 * which half of the stack the index falls in). */
int	cost_stack_a(t_stack *stack_a, int index)
{
	if (index <= stack_a->size / 2)
		return (index);
	return (index - stack_a->size);
}

/* Same idea as cost_stack_a, but for stack_b: finds where value
 * would need to be inserted (via find_target_position) and converts
 * that position into a signed rotation cost (positive = rb,
 * negative = rrb). */
int	cost_stack_b(t_stack *stack_b, int value)
{
	int	target_position;

	target_position = find_target_position(stack_b, value);
	if (target_position <= (stack_b->size / 2))
		return (target_position);
	return (target_position - stack_b->size);
}

/* Combines a stack_a rotation cost and a stack_b rotation cost into
 * one total operation count: if both point the same direction
 * (both positive or both negative), they can be done together via
 * rr/rrr, so the cost is just the larger of the two; otherwise they
 * have to be rotated independently, so the cost is their sum. */
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
