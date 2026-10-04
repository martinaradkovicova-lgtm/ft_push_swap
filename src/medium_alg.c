/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 12:05:49 by mradkovi          #+#    #+#             */
/*   Updated: 2026/10/03 17:43:52 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* Medium strategy, O(n*sqrt(n)): assigns each node a rank via
 * pre_sort, splits the rank range into chunks of ~sqrt(n)*1.8,
 * sweeps stack_a once per chunk pushing that chunk's members into
 * stack_b (check_chunk), then drains stack_b back into stack_a by
 * repeatedly rotating the current maximum to the top and pushing
 * it across, so stack_a rebuilds in ascending order. */
void	medium_alg(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_size;
	int	num_chunks;
	int	c;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (compute_disorder(stack_a) == 0.000000)
		return ;
	pre_sort(stack_a);
	chunk_size = ft_sqrt(stack_a->size) * 1.8;
	num_chunks = (stack_a->size + chunk_size - 1) / chunk_size;
	c = 0;
	while (c < num_chunks)
	{
		check_chunk(stack_a, stack_b, c * chunk_size,
			((c * chunk_size) + chunk_size - 1));
		c++;
	}
	while (stack_b->size > 0)
	{
		bring_to_top_b(stack_b, find_max(stack_b));
		pa(stack_b, stack_a);
	}
}

/* One O(n) sweep of stack_a: for every element present at the
 * start of the call, pushes it to stack_b if its rank falls within
 * [chunk_start, chunk_end], otherwise rotates it to the back of
 * stack_a so it's available for a later chunk's pass. */
void	check_chunk(t_stack *stack_a, t_stack *stack_b, int chunk_start,
			int chunk_end)
{
	int	i;
	int	j;

	i = 0;
	j = stack_a->size;
	while (i < j)
	{
		if (stack_a->top->index >= chunk_start
			&& stack_a->top->index <= chunk_end)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
}

/* Scans stack from top to bottom and returns the position (0 =
 * top) of the node holding the largest value. Used by
 * bring_to_top_b to know how far to rotate. */
int	find_max(t_stack *stack)
{
	int		max;
	int		max_position;
	int		i;
	t_num	*current_num;

	current_num = stack->top;
	max = current_num->value;
	max_position = 0;
	i = 0;
	while (current_num != NULL)
	{
		if (current_num->value > max)
		{
			max = current_num->value;
			max_position = i;
		}
		current_num = current_num->next;
		i++;
	}
	return (max_position);
}

/* Rotates stack_b so the node at the given position ends up on
 * top, choosing whichever direction (rb or rrb) takes fewer moves
 * based on which half of the stack that position falls in. */
void	bring_to_top_b(t_stack *stack_b, int position)
{
	if ((stack_b->size / 2) <= position)
		position = (stack_b->size - position) * (-1);
	if (position < 0)
	{
		while (position < 0)
		{
			rrb(stack_b);
			position++;
		}
	}
	else
	{
		while (position > 0)
		{
			rb(stack_b);
			position--;
		}
	}
}

/* Integer square root: returns the largest i such that i*i <= nb
 * (or the exact root if nb is a perfect square), computed with a
 * simple incrementing search since math.h isn't available. Capped
 * at 46340 since 46341*46341 would overflow a 32-bit int. */
int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i <= 46340 && i * i < nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i);
}
