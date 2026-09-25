#include "ft_push_swap.h"
#include <stdio.h>

int	count_operations(int op_index)
{
	static int	op_counter[11];
	int	i;
	
	if (op_index < 0)
	{
		i = 0;
		while (i < 11)
		{
			op_counter[i] = 0;
			i++;
		}
		return (0);
	}
	if (op_index >= 100 && op_index <= 110)
	{
		return (op_counter[op_index - 100]);
	}
	if (op_index >= 0 && op_index <= 10)
	{
		op_counter[op_index]++;
		return (op_counter[op_index]);
	}
	return(op_counter[op_index]);
}

void swap_stack(t_stack *stack)
{
	int swap;

	if (stack == NULL || stack->top == NULL || stack->top->next == NULL)
		return ;
	swap = stack->top->value;
	stack->top->value = stack->top->next->value;
	stack->top->next->value = swap;
}
void sa(t_stack *stack_a)
{
	swap_stack(stack_a);
	write(1, "sa\n", 3);
   	count_operations(0);
}

void sb(t_stack *stack_b)
{
	swap_stack(stack_b);
	write(1, "sb\n", 3);
	count_operations(1);
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
	write (1, "ss\n", 3);
	count_operations(2);
}

void rotate_stack(t_stack *stack)
{
	t_num *first;
	
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

void ra(t_stack *stack_a)
{
	rotate_stack(stack_a);
	write(1, "ra\n", 3);
	count_operations(3);
}

void rb(t_stack *stack_b)
{
	rotate_stack(stack_b);
	write(1, "rb\n", 3);
	count_operations(4);
}

void rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	write(1, "rr\n", 3);
	count_operations(5);
}

void reverse_rotate_stack(t_stack *stack)
{
	t_num *bottom;

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

void rra(t_stack *stack_a)
{
	reverse_rotate_stack(stack_a);
	write(1, "rra\n", 4);
	count_operations(6);
}

void rrb(t_stack *stack_b)
{
	reverse_rotate_stack(stack_b);
	write(1, "rrb\n", 4);
	count_operations(7);
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_stack(stack_a);
	reverse_rotate_stack(stack_b);
	write(1, "rrr\n", 4);
	count_operations(8);
}

void push_stack_top(t_stack *src, t_stack *dest)
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

void pa(t_stack *stack_b, t_stack *stack_a)
{
	if (stack_b == NULL || stack_b->top == NULL || stack_a == NULL)
		return ;
	push_stack_top(stack_b, stack_a);
	write(1, "pa\n", 3);
	count_operations(9);
}

void pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a == NULL || stack_a->top == NULL || stack_b == NULL)
		return ;
	push_stack_top(stack_a, stack_b);
	write(1, "pb\n", 3);
	count_operations(10);
}

void print_op_counting()
{
	printf("\n\nsa(%d)\n", count_operations(100));
	printf("sb(%d)\n", count_operations(101));
	printf("ss(%d)\n", count_operations(102));
	printf("ra(%d)\n", count_operations(103));
	printf("rb(%d)\n", count_operations(104));
	printf("rr(%d)\n", count_operations(105));
	printf("rra(%d)\n", count_operations(106));
	printf("rrb(%d)\n", count_operations(107));
	printf("rrr(%d)\n", count_operations(108));
	printf("pa(%d)\n", count_operations(109));
	printf("pb(%d)\n", count_operations(110));
}
