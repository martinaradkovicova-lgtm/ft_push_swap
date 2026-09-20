#include "ft_push_swap.h"

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
}

void sb(t_stack *stack_b)
{
	swap_stack(stack_b);
	write(1, "sb\n", 3);
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
	write (1, "ss\n", 3);
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
}

void rb(t_stack *stack_b)
{
	rotate_stack(stack_b);
	write(1, "rb\n", 3);
}

void rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	write(1, "rr\n", 3);
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
}

void rrb(t_stack *stack_b)
{
	reverse_rotate_stack(stack_b);
	write(1, "rrb\n", 4);	
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_stack(stack_a);
	reverse_rotate_stack(stack_b);
	write(1, "rrr\n", 4);
}


