/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 12:05:57 by mradkovi          #+#    #+#             */
/*   Updated: 2026/10/03 18:42:39 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* Sorts temp_array in place (ascending) using a plain bubble sort.
 * Shared helper used by duplicity_checker's overflow/duplicate
 * check and by pre_sort's rank-assignment pass. */
void	bubble_sort(int *temp_array, int len)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (temp_array[j] > temp_array[j + 1])
				ft_swap(&temp_array[j], &temp_array[j + 1]);
			j++;
		}
		i++;
	}
}

/* Prepares stack_a for the medium/complex algorithms: copies every
 * node's value into a temporary array, sorts that copy, then uses
 * it to assign each node a rank (0..n-1) via assign_index. Ranks
 * are stored in t_num->index and let chunk/bit boundaries work off
 * clean 0..n-1 positions instead of the raw (possibly negative,
 * widely spread) values. Does nothing on allocation failure. */
void	pre_sort(t_stack *stack_a)
{
	t_num	*curr;
	int		*temp_array;
	int		i;
	int		len;

	len = stack_a->size;
	temp_array = (int *)malloc(sizeof(int) * len);
	if (temp_array == NULL)
		return ;
	curr = stack_a->top;
	i = 0;
	while (curr != NULL)
	{
		temp_array[i] = curr->value;
		curr = curr->next;
		i++;
	}
	bubble_sort(temp_array, len);
	assign_index(temp_array, stack_a);
	free(temp_array);
}

/* For every node in stack_a, finds where its value sits in the
 * sorted array str and stores that position as the node's rank in
 * curr->index. Assumes no duplicate values (so each lookup is
 * unambiguous) and that str holds exactly the same values as
 * stack_a's nodes, already sorted by pre_sort. */
void	assign_index(int *str, t_stack *stack_a)
{
	int		i;
	t_num	*curr;

	curr = stack_a->top;
	while (curr != NULL)
	{
		i = 0;
		while (str[i] != curr->value)
			i++;
		curr->index = i;
		curr = curr->next;
	}
}
