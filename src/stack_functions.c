/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:35:40 by mradkovi          #+#    #+#             */
/*   Updated: 2026/10/03 13:29:00 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* Builds stack_a from argv[numbers_start..argc): joins the number
 * arguments into one space-separated string, splits it back apart,
 * validates every token, then converts each to a node and pushes
 * it onto stack_a. Frees all intermediate memory on every exit
 * path. Returns 1 on success, 0 on any failure (join, split,
 * validation, or allocation). */
int	fill_stack_a(t_stack *stack_a, int argc, char **argv, int numbers_start)
{
	int		i;
	char	*joined;
	t_num	*new_num;
	char	**splited_args;

	joined = join_args(argc, argv, numbers_start);
	if (joined == NULL)
		return (0);
	splited_args = ft_split(joined, ' ');
	free(joined);
	if (splited_args == NULL || (validate_args(splited_args) != 1))
		return (clean_split_memory(splited_args), 0);
	i = 0;
	while (splited_args[i] != NULL)
	{
		new_num = create_new_number(ft_atoi(splited_args[i]));
		if (new_num == NULL)
			return (clean_split_memory(splited_args), 0);
		push_new_number(stack_a, new_num);
		i++;
	}
	return (clean_split_memory(splited_args), 1);
}

/* Resets a stack to its empty state: no top, no bottom, size 0. */
void	create_empty_stack(t_stack *stack_a)
{
	stack_a->top = NULL;
	stack_a->bottom = NULL;
	stack_a->size = 0;
}

/* Allocates and initializes a single t_num node holding num.
 * index starts at -1 (unassigned, set later by pre_sort/
 * ft_assign_index). Returns NULL on allocation failure. */
t_num	*create_new_number(int num)
{
	t_num	*new_num;

	new_num = (t_num *)malloc(sizeof(t_num));
	if (! new_num)
		return (NULL);
	new_num->value = num;
	new_num->index = -1;
	new_num->next = NULL;
	new_num->prev = NULL;
	return (new_num);
}

/* Appends new_num to the bottom of stack, updating top/bottom/size
 * accordingly. Used while building the stack from input, so
 * argument order is preserved top-to-bottom. */
void	push_new_number(t_stack *stack, t_num *new_num)
{
	if (! new_num)
		return ;
	if (stack->top == NULL)
	{
		stack->top = new_num;
		stack->bottom = new_num;
	}
	else
	{
		new_num->prev = stack->bottom;
		stack->bottom->next = new_num;
		stack->bottom = new_num;
	}
	stack->size++;
}

/* Joins argv[numbers_start..argc) into a single space-separated
 * string, so it can later be re-split on spaces to normalize
 * argument formatting (handles both "1 2 3" and "1" "2" "3" style
 * input the same way). Returns NULL on allocation failure. */
char	*join_args(int argc, char **argv, int numbers_start)
{
	char	*joined;
	char	*tmp;
	int		i;

	i = numbers_start;
	joined = ft_strjoin(argv[i], " ");
	if (joined == NULL)
		return (NULL);
	i++;
	while (i < argc)
	{
		tmp = ft_strjoin(joined, argv[i]);
		free(joined);
		if (tmp == NULL)
			return (NULL);
		joined = ft_strjoin(tmp, " ");
		free(tmp);
		if (joined == NULL)
			return (NULL);
		i++;
	}
	return (joined);
}
