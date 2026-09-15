#include "ft_push_swap.h"

t_num *create_new_number(int num)
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

t_stack create_empty_stack(t_stack *stack_a)
{
	stack_a->top = NULL;
	stack_a->bottom = NULL;
	stack_a->size = 0;
	return (stack_a);
}

void push_new_number(t_stack *stack, t_num *new_num)
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

int fill_stack_a(t_stack *stack_a, int argc, char **argv, int has_flag)
{
	int		i;
	t_num	*new_num;

	i = 1 + has_flag;
	while (i < argc)
	{
		new_num = create_new_number(ft_atoi(argv[i]));
		if (new_num == NULL)
			return (0); //fail + print error
		push_new_number(stack_a, new_num);
		i++;
	}
	return (1);
}

void clean_stack_memory(t_stack *stack)
{
	t_num	*current_num;
	t_num	*swap;

	if (stack == NULL || stack->top == NULL)
		return ; // + print error
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

int strategy_selector(char *flag, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp("--simple", flag, 9) == 0)
		//call simple algorithm ...
	else if (ft_strncmp("--medium", flag, 9) == 0)
		//call medium algorithm
	else if (ft_strncmp("--complex", flag, 9) == 0)
		//call complex algorithm
	else if (ft_strncmp("--adaptive", flag, 9) == 0)
		//call function which counts numbers and choose simple, medium or complex
	else
		return (1)//bad arg - error
	return (0);
}

int validate_flag(char *arg)
{
	if (ft_strncmp(arg, "--", 2) != 0)
		return (0); //no flag
	if (ft_strncmp(arg, "--simple", 9 == 0)
		return (1);
	else if (ft_strncmp("--medium", flag, 9) == 0)
		return (1);
	else if (ft_strncmp("--complex", flag, 9) == 0)
		return (1);
	else if (ft_strncmp("--adaptive", flag, 9) == 0)
		return (1);
	else
		return (-1); //invalid flag
}

int main (int argc, char **argv)
{
	t_stack	stack_a;
	t_stack stack_b;
	int	i;
	int has_flag;
	
	if (argc < 2)
		return (1); //+ print error0
	has_flag = validate_flag(argv[1]);
	if (has_flag == -1)
		return (1); //+ print error
	create_empty_stack(&stack_a);
	create_empty_stack(&stack_b);
	if (! fill_stack_a(&stack_a, argc, argv, has_flag))
	{
		clean_stack_memory(&stack_a); //ERROR during fill the stack
		return (1);
	}
	if (has_flag == 1)
		strategy_selector(argv[1], &stack_a, &stack_b);
	clean_stack_memory(&stack_a);
	clean_stack_memory(&stack_b);
	return (0);
}
