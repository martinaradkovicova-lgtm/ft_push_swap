/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 13:39:57 by hpiotrow          #+#    #+#             */
/*   Updated: 2026/10/03 18:46:45 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* Frees a NULL-terminated array of strings (as returned by
 * ft_split): every individual string, then the array itself. Does
 * nothing if splited_args is NULL. Used to clean up fill_stack_a's
 * intermediate allocations on every exit path. */
void	clean_split_memory(char **splited_args)
{
	int	i;

	if (splited_args == NULL)
		return ;
	i = 0;
	while (splited_args[i] != NULL)
	{
		free(splited_args[i]);
		i++;
	}
	free(splited_args);
}

/* Frees every node in stack's linked list and resets it to the
 * empty state (top/bottom NULL, size 0). Does nothing if stack is
 * NULL or already empty. Called at the end of run_push_swap so no
 * nodes leak after a sort completes. */
void	clean_stack_memory(t_stack *stack)
{
	t_num	*current_num;
	t_num	*swap;

	if (stack == NULL || stack->top == NULL)
		return ;
	current_num = stack->top;
	while (current_num)
	{
		swap = current_num->next;
		free(current_num);
		current_num = swap;
	}
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
}
