#include "ft_push_swap.h"

void	pre_sort(t_stack *stack_a)
{
	t_num	*curr;
	int		*temp_array;
	int		i;
	int		j;
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
	i = 0;
	while (i < len - 1)//sorting array copy
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
	ft_assign_index(temp_array, stack_a);
	free(temp_array);
}

void	ft_assign_index(int *str, t_stack *stack_a)
{
	int	i;
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

void medium_alg(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk_size;
	int	num_chunks;
	int	chunk_start;
	int	chunk_end;
	int	c;

	if (stack_a == NULL || stack_b == NULL)
		return;
	if (compute_disorder(stack_a) == 0.000000)
		return;
	pre_sort(stack_a);
	chunk_size = ft_sqrt(stack_a->size);
	num_chunks = (stack_a->size + chunk_size - 1) / chunk_size;
	c = 0;
	while (c < num_chunks)
	{
		chunk_start = c * chunk_size;
		chunk_end = chunk_start + chunk_size - 1;
		check_chunk(stack_a, stack_b, chunk_start, chunk_end);
		c++;
	}
	while (stack_b->size > 0)
	{
		bring_to_top_b(stack_b, find_max(stack_b));
		pa(stack_b, stack_a);
	}
}

void	check_chunk(t_stack *stack_a, t_stack *stack_b, int chunk_start, int chunk_end)
{
	int	i;
	int	j;

	i = 0;
	j = stack_a->size;
	while (i < j)
	{
		if (stack_a->top->index >= chunk_start && stack_a->top->index <= chunk_end)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
}

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

void	bring_to_top_b(t_stack *stack_b, int position)
{

	if ((stack_b->size / 2) < position)
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

/* MAYBE WILL USE LATER

void	bring_to_top_a(t_stack *stack, int position)
{
	if ((stack->size / 2) < position)
		position = (stack->size - position) * (-1);
	if (position < 0)
	{
		while (position < 0)
		{
			rra(stack);
			position++;
		}
	}
	else
	{
		while (position > 0)
		{
			ra(stack);
			position--;
		}
	}
}

MAYBE WILL USE LATER */
