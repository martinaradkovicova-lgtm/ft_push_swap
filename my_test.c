#include "libft.h"

typedef struct s_num
{
	int	value;
	int	index;
	struct s_num *next;
	struct s_num *prev;
} t_num;

typedef struct s_stack
{
	t_num	*top;
	t_num	*bottom;
	int		size;
} t_stack

t_num *create_new_number(int num)
{
	t_num	*new_num;
	new_num = (t_num *)malloc(sizeof(t_num));
	if (! new_num)
		return (NULL);
	new_num->value = num;
	new_num->next = NULL;
	new_num->prev = NULL;
	return (new_num);
}

int main (int argc, char **argv)
{
	t_stack	stack_a;
	t_num	*new_num;
	int		i;
	int		number;

	//empty stack
	stack_a.top = NULL;
	stack_a.bottom = NULL;
	stack_a.size = 0;

	i = 1; //we starting from index 1 (argv[0] is prog.name)
	while (i < argc)
	{
		number = ft_atoi(argv[i]);
		//create new node for new num
		new_num = create_new_number(number);
		
	}
	if (stack_a.top == NULL)
	{
		stack_a.top = new_num;
		stack_a.bottom = new_num;
	}
	else
	{
		new_num->prev = stack_a.bottom;
		stack.a.bottom->next = new_num;
		stack.a.bottom = new_num;
	}
	return (0);
}
