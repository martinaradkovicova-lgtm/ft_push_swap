#include "ft_push_swap.h"

void	print_bench(t_stack *stack_a, double disorder, char *strategy, char *complexity)
{
	int	total;
	int	i;

	write(2, "Disorder: ", 10);
	ft_put_percent_fd(disorder, 2);
	write(2, "Strategy: ", 10);
	write(2, strategy, ft_strlen(strategy));
	write(2, " (", 2);
	write(2, complexity, ft_strlen(complexity));
	write(2, ")\n", 2);
	total = 0;
	i = 100;
	while (i <= 110)
	{
		total += count_operations(i);
		i++;
	}
	write(2, "Total ops: ", 11);
	ft_putnbr_fd(total, 2);
	write(2, "\n", 1);
	print_op_counting();
	(void)stack_a;
}

char	*get_plain_strategy(char *flag)
{
	if (flag[0] == '-' && flag[1] == '-')
		return (flag + 2);
	return (flag);
}

char	*get_complexity(char *strategy)
{
	if (ft_strncmp(strategy, "simple", 7) == 0)
		return ("O(n^2)");
	if (ft_strncmp(strategy, "medium", 7) == 0)
		return ("O(n*sqrt(n))");
	if (ft_strncmp(strategy, "complex", 8) == 0)
		return ("O(n*log(n))");
	return ("O(1)");
}
