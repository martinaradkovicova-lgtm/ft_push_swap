/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions_swap.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:47:15 by hpiotrow          #+#    #+#             */
/*   Updated: 2026/10/03 18:14:00 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* sa: swaps the top two elements of stack_a, prints "sa\n", and
 * tallies the operation. */
void	sa(t_stack *stack_a)
{
	swap_stack(stack_a);
	write(1, "sa\n", 3);
	count_operations(0);
}

/* sb: swaps the top two elements of stack_b, prints "sb\n", and
 * tallies the operation. */
void	sb(t_stack *stack_b)
{
	swap_stack(stack_b);
	write(1, "sb\n", 3);
	count_operations(1);
}

/* ss: performs sa and sb simultaneously, prints "ss\n" once, and
 * tallies the operation. */
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
	write (1, "ss\n", 3);
	count_operations(2);
}

/* Swaps the VALUES of the top two nodes of stack (the nodes
 * themselves stay in place, only their contents trade). Does
 * nothing if stack is NULL, empty, or has only one element. */
void	swap_stack(t_stack *stack)
{
	int	swap;

	if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
		return ;
	swap = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = swap;
}
