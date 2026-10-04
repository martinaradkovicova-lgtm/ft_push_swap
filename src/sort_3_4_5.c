/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_4_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 12:01:44 by hpiotrow          #+#    #+#             */
/*   Updated: 2026/10/03 18:37:17 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* Sorts exactly 3 elements with at most 2 operations, using a
 * hardcoded decision over the 6 possible orderings of (a, b, c) =
 * (top, 2nd, 3rd). Does nothing if stack_a is NULL or has fewer
 * than 3 elements. */
void	sort_three(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;

	if (stack_a == NULL || stack_a->size < 3)
		return ;
	a = stack_a->top->value;
	b = stack_a->top->next->value;
	c = stack_a->top->next->next->value;
	if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a < b && b > c && a < c)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
	else if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b < c && a > c)
		ra(stack_a);
}

/* Sorts exactly 4 elements: rotates the minimum to the top (the
 * short way, based on its position), then if the remaining 3
 * aren't already sorted, pushes the minimum to stack_b, sorts the
 * other 3 with sort_three, and pushes the minimum back on top
 * (correct, since it's the smallest of all 4). */
void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	int	minimum_idx;

	minimum_idx = four_minimum_index(stack_a);
	if (minimum_idx == 1)
		sa(stack_a);
	else if (minimum_idx == 2)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (minimum_idx == 3)
		rra(stack_a);
	if (compute_disorder(stack_a) > 0.000000)
	{
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_b, stack_a);
	}
}

/* Sorts exactly 5 elements: same peel-off-the-minimum pattern as
 * sort_four, one level up — rotates the minimum of all 5 to the
 * top, then (if needed) sets it aside in stack_b, sorts the
 * remaining 4 with sort_four, and pushes the minimum back on top. */
void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	minimum_idx;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	minimum_idx = five_minimum_index(stack_a);
	if (minimum_idx == 1)
		sa(stack_a);
	else if (minimum_idx == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (minimum_idx == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (minimum_idx == 4)
		rra(stack_a);
	if (compute_disorder(stack_a) > 0.000000)
	{
		pb(stack_a, stack_b);
		sort_four(stack_a, stack_b);
		pa(stack_b, stack_a);
	}
}

/* Finds which of the 4 positions (top, 2nd, 2nd-from-bottom,
 * bottom) holds the smallest value, for a stack of exactly 4
 * elements. Returns 0-3, used by sort_four to decide the shortest
 * rotation direction to bring it to the top. */
int	four_minimum_index(t_stack *stack_a)
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

/* Finds which of the 5 positions (top, 2nd, 3rd, 2nd-from-bottom,
 * bottom) holds the smallest value, for a stack of exactly 5
 * elements. Returns 0-4, used by sort_five the same way
 * four_minimum_index is used by sort_four. */
int	five_minimum_index(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	e;

	a = stack_a->top->value;
	b = stack_a->top->next->value;
	c = stack_a->top->next->next->value;
	d = stack_a->bottom->prev->value;
	e = stack_a->bottom->value;
	if ((a < b) && (a < c) && (a < d) && (a < e))
		return (0);
	else if ((b < a) && (b < c) && (b < d) && (b < e))
		return (1);
	else if ((c < a) && (c < b) && (c < d) && (c < e))
		return (2);
	else if ((d < a) && (d < b) && (d < c) && (d < e))
		return (3);
	else
		return (4);
}
