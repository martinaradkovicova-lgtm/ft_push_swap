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
	stack_a.top = NULL;
	stack_a.bottom = NULL;
	stack_a.size = 0;
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
		new_num->prev = stack_bottom;
		stack->bottom->next = new_num;
		stack->bottom = new_num;
	}
	stack->size++;
}

int fill_stack_a(t_stack *stack_a, int argc, char **argv)
{
	int		i;
	t_num	*new_num;

	i = 1;
	while (i < argc)
	{
		new_num = create_new_number(ft_atoi(argv[i]));
		if (new_num == NULL)
			return (0); //fail
		push_new_number(stack_a, new_num);
		i++;
	}
	return (1);
}

clean_stack_memory(t_stack *stack_a)
{
		
}

int main (int argc, char **argv)
{
	t_stack	stack_a;

	if (argc < 2)
		return (0);
	//add check other args
	
	create_empty_stack(&stack_a);
	if (! fill_stack_a(&stack_a, argc, argv))
		clean_stack_memory(&stack_a); //ERROR during fill the stack
	
	return (0);
}
