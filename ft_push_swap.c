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

void create_empty_stack(t_stack *stack_a)
{
	stack_a->top = NULL;
	stack_a->bottom = NULL;
	stack_a->size = 0;
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
	{
		write(2, "[ERROR]\n", 8);
		return ;
	}
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

void strategy_selector(char *flag, t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_a;//DEBUG
	(void)stack_b;//DEBUG
	if (ft_strncmp("--simple", flag, 9) == 0)
		write(1, "--simple", 8); //DEBUG -> call simple algorithm
	if (ft_strncmp("--medium", flag, 9) == 0)
		write(1, "--medium", 8); //DEBUG -> call medium algorithm
	if (ft_strncmp("--complex", flag, 10) == 0)
		write(1, "--complex", 9); //DEBUG//call complex algorithm
	if (ft_strncmp("--adaptive", flag, 11) == 0)
		write(1, "--adaptive", 10); //DEBUG -> call adaptive
		//call adaptive function which counts numbers and choose simple, medium or complex
}

int validate_flag(char *flag)
{
	if (ft_strncmp(flag, "--", 2) != 0)
		return (0); //no flag
	if (ft_strncmp("--simple", flag, 9) == 0)
		return (1);
	else if (ft_strncmp("--medium", flag, 9) == 0)
		return (1);
	else if (ft_strncmp("--complex", flag, 10) == 0)
		return (1);
	else if (ft_strncmp("--adaptive", flag, 11) == 0)
		return (1);
	else
	{
		write(2, "[ERROR] INVALID FLAG\n", 21);
		return (-1); //invalid flag
	}
}

int arg_checker(int argc)
{
	if (argc < 2)
	{
		write(2, "[ERROR] NO ARGUMENTS\n", 21);
		return (1); 
	}
	return (0);
}

int main (int argc, char **argv)
{
	t_stack	stack_a;
	t_stack stack_b;
	int has_flag;

	if ((arg_checker(argc) == 1))
		return (1);
	has_flag = validate_flag(argv[1]);
	if (has_flag == -1)
		return (1);
	create_empty_stack(&stack_a);
	create_empty_stack(&stack_b);
	if (! fill_stack_a(&stack_a, argc, argv, has_flag))
	{
		clean_stack_memory(&stack_a); //ERROR during fill the stack
		write(2, "[ERROR]\n", 8);
		return (1);
	}
	if (has_flag == 1)
		strategy_selector(argv[1], &stack_a, &stack_b);
	else
		//call adaptive algorithm
	clean_stack_memory(&stack_a);
	return (0);
}
