/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_alg_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 12:20:19 by hpiotrow          #+#    #+#             */
/*   Updated: 2026/10/03 18:40:30 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* Scans every element of stack_a and, for each one, computes the
 * total rotation cost (combining stack_a's position with stack_b's
 * best insertion point) of moving it to stack_b. Returns the
 * position of the element with the lowest total cost - this is the
 * element insertion_sort should move next. */
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

/* Rotates stack_a and stack_b together while both costs point the
 * same direction, using rr for two positive costs and rrr for two
 * negative costs, so a single combined operation covers one step
 * of both rotations at once instead of two separate ones. Updates
 * *cost_a/*cost_b in place to whatever's left afterward. */
void	both_rotate(t_stack *stack_a, t_stack *stack_b,
					int *cost_a, int *cost_b)
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

/* Finishes off whatever rotation cost both_rotate couldn't combine
 * (i.e. once the costs no longer share the same sign), rotating
 * stack_a and stack_b independently in the direction each cost
 * indicates (positive = ra/rb, negative = rra/rrb) until both
 * reach zero. */
void	single_rotate(t_stack *stack_a, t_stack *stack_b,
	int cost_a, int cost_b)
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

/* Moves the element at the given position in stack_a onto stack_b:
 * walks to that node, computes the rotation cost for each stack,
 * performs the combined rotation first (both_rotate) then whatever
 * single-stack rotation remains (single_rotate), and finally pushes
 * the element across with pb. This is the move insertion_sort
 * actually performs each iteration, using the position
 * find_beast_cost identified as cheapest. */
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

/* Final cleanup after insertion_sort's main loop: rotates stack_b
 * (the short way) so its true maximum ends up on top, which is
 * what lets the subsequent plain pa-drain rebuild stack_a in
 * ascending order. Does nothing if stack_b is NULL or empty. */
void	align_stack_b(t_stack *stack_b)
{
	int	max;
	int	min;
	int	max_pos;

	if (!stack_b || !stack_b->top)
		return ;
	max_pos = find_maximum_position(stack_b, &max, &min);
	if (max_pos <= stack_b->size / 2)
	{
		while (max_pos-- > 0)
			rb(stack_b);
	}
	else
	{
		while (max_pos++ < stack_b->size)
			rrb(stack_b);
	}
}
