/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions_revrotate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:53:32 by hpiotrow          #+#    #+#             */
/*   Updated: 2026/10/03 18:17:26 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* rra: reverse-rotates stack_a down by one (bottom becomes top),
 * prints "rra\n", and tallies the operation. */
void	rra(t_stack *stack_a)
{
	reverse_rotate_stack(stack_a);
	write(1, "rra\n", 4);
	count_operations(6);
}

/* rrb: reverse-rotates stack_b down by one, prints "rrb\n", and
 * tallies the operation. */
void	rrb(t_stack *stack_b)
{
	reverse_rotate_stack(stack_b);
	write(1, "rrb\n", 4);
	count_operations(7);
}

/* rrr: performs rra and rrb simultaneously, prints "rrr\n" once,
 * and tallies the operation. */
void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_stack(stack_a);
	reverse_rotate_stack(stack_b);
	write(1, "rrr\n", 4);
	count_operations(8);
}

/* Moves the bottom node of stack to the top (the last element
 * becomes the first). Does nothing if stack is NULL, empty, or has
 * only one element. */
void	reverse_rotate_stack(t_stack *stack)
{
	t_num	*bottom;

	if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
		return ;
	bottom = stack->bottom;
	stack->bottom = bottom->prev;
	stack->bottom->next = NULL;
	bottom->next = stack->top;
	stack->top->prev = bottom;
	stack->top = bottom;
	stack->top->prev = NULL;
}
