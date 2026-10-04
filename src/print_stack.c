/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:36:28 by mradkovi          #+#    #+#             */
/*   Updated: 2026/10/03 18:41:59 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* Debug helper: prints every value in stack_a from top to bottom,
 * one per line. NOT for use in the normal sort path - stdout must
 * contain only push_swap operations, so this should only be called
 * manually while debugging, never from main/run_push_swap. */
void	print_stack(t_stack *stack_a)
{
	t_num	*current;

	current = stack_a->top;
	while (current != NULL)
	{
		ft_printf ("%d\n", current->value);
		current = current->next;
	}
}
