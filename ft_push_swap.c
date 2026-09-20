#include "ft_push_swap.h"
#include <stdio.h>

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

void clean_split_memory(char **splited_args)
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

void ft_swap(int *a, int *b)
{
	int swap;
	swap = *a;
	*a = *b;
	*b = swap;
}

int duplicity_checker(char **splited_args, int len)
{
	int *splited_copy;
	int i;
	int j;
	
	splited_copy = (int *)malloc(sizeof(int) * (len));
	if (splited_copy == NULL)
		return (1);
	i = 0;
	while (i < len) //convert copy to int numbers
	{
		splited_copy[i] = ft_atoi(splited_args[i]);
		i++;
	}
	i = 0;
	while (i < len -1)//sorting array copy
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (splited_copy[j] > splited_copy[j + 1])
				ft_swap(&splited_copy[j], &splited_copy[j + 1]);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < (len - 1))//check duplicity
	{
		if (splited_copy[i] == splited_copy[i + 1])
		{	free(splited_copy);
			return (1);
		}
		i++;
	}
	free(splited_copy);
	return (0);
}

char *join_args(int argc, char **argv, int has_flag)
{
	char	*joined;
	char	*tmp;
	int		i;

	i = 1 + has_flag;
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

int validate_args(char **splited_args)
{
	int i;
	int j;
		
	i = 0;
	while (splited_args[i] != NULL)
	{
		j = 0;
		if (splited_args[i][j] == '+' || splited_args[i][j] == '-')
			j++;
		if (splited_args[i][j] == '\0')
			return (0); //invalid argument only +,- no next digit
		while (splited_args[i][j] != '\0')
		{
			if ((splited_args[i][j] < '0') || (splited_args[i][j] > '9'))
				return (0); //invalid argument no digit
			j++;
		}
		i++;
	}
	if (duplicity_checker(splited_args, i) == 1)
		return (0);
	return (1);
}

int fill_stack_a(t_stack *stack_a, int argc, char **argv, int has_flag)
{
	int		i;
	char	*joined;
	t_num	*new_num;
	char	**splited_args;

	joined = join_args(argc, argv, has_flag);
	if (joined == NULL)
		return (0);
	splited_args =  ft_split(joined, ' ');
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

void clean_stack_memory(t_stack *stack)
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

void strategy_selector(char *flag, t_stack *stack_a, t_stack *stack_b)
{
	double	disorder;
	(void)stack_b;//DEBUG
	if (ft_strncmp("--simple", flag, 9) == 0)
		write(1, "--simple", 8); //DEBUG -> call medium algorithm
	if (ft_strncmp("--medium", flag, 9) == 0)
		write(1, "--medium", 8); //DEBUG -> call medium algorithm
	if (ft_strncmp("--complex", flag, 10) == 0)
		write(1, "--complex", 9); //DEBUG//call complex algorithm
	if (ft_strncmp("--adaptive", flag, 11) == 0)
		write(1, "--adaptive", 10); //DEBUG -> call adaptive
		//call adaptive function which counts numbers and choose simple, medium or complex
	disorder = compute_disorder(stack_a); 
	printf("disorder = %f\n", disorder); //DEBUG
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
	if (fill_stack_a(&stack_a, argc, argv, has_flag) != 1)
	{
		clean_stack_memory(&stack_a); //ERROR during fill the stack
		return (write(2, "[ERROR]\n", 8),1);
	}
	if (has_flag == 1)
		strategy_selector(argv[1], &stack_a, &stack_b);
	else
	{
		write(1, "Adaptive alg\n", 13); //DEBUG- call adaptive algorithm
	}
	clean_stack_memory(&stack_a);
	return (0);
}
