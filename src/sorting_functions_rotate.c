/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:51:48 by hpiotrow          #+#    #+#             */
/*   Updated: 2026/10/03 18:16:02 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* ra: rotates stack_a up by one (top becomes bottom), prints
 * "ra\n", and tallies the operation. */
void	ra(t_stack *stack_a)
{
	rotate_stack(stack_a);
	write(1, "ra\n", 3);
	count_operations(3);
}

/* rb: rotates stack_b up by one, prints "rb\n", and tallies the
 * operation. */
void	rb(t_stack *stack_b)
{
	rotate_stack(stack_b);
	write(1, "rb\n", 3);
	count_operations(4);
}

/* rr: performs ra and rb simultaneously, prints "rr\n" once, and
 * tallies the operation. */
void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	write(1, "rr\n", 3);
	count_operations(5);
}

/* Moves the top node of stack to the bottom (the first element
 * becomes the last). Does nothing if stack is NULL, empty, or has
 * only one element. */
void	rotate_stack(t_stack *stack)
{
	t_num	*first;

	if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
		return ;
	first = stack->top;
	stack->top = first->next;
	stack->top->prev = NULL;
	stack->bottom->next = first;
	first->prev = stack->bottom;
	first->next = NULL;
	stack->bottom = first;
}
