/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions_push.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:57:55 by hpiotrow          #+#    #+#             */
/*   Updated: 2026/10/03 18:29:13 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* pa: takes the top of stack_b and pushes it onto the top of
 * stack_a, prints "pa\n", and tallies the operation. */
void	pa(t_stack *stack_b, t_stack *stack_a)
{
	push_stack_top(stack_b, stack_a);
	write(1, "pa\n", 3);
	count_operations(9);
}

/* pb: takes the top of stack_a and pushes it onto the top of
 * stack_b, prints "pb\n", and tallies the operation. */
void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push_stack_top(stack_a, stack_b);
	write(1, "pb\n", 3);
	count_operations(10);
}

/* Detaches the top node of src and prepends it onto the top of
 * dest, updating top/bottom/size on both stacks. Does nothing if
 * src is NULL/empty or dest is NULL. This is the shared mechanic
 * behind both pa and pb. */
void	push_stack_top(t_stack *src, t_stack *dest)
{
	t_num	*num;

	if (src == NULL || src->top == NULL || dest == NULL)
		return ;
	num = src->top;
	src->top = src->top->next;
	if (src->top != NULL)
		src->top->prev = NULL;
	else
		src->bottom = NULL;
	src->size--;
	num->next = dest->top;
	num->prev = NULL;
	if (dest->top != NULL)
		dest->top->prev = num;
	else
		dest->bottom = num;
	dest->top = num;
	dest->size++;
}
