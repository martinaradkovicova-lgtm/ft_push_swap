/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 14:42:42 by hpiotrow          #+#    #+#             */
/*   Updated: 2026/10/03 18:49:23 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* Writes the --bench report to stderr: disorder percentage,
 * strategy name with its complexity class, total operation count,
 * and the per-operation breakdown (via print_op_counting). Never
 * touches stdout, so it can't interfere with the printed
 * operations. stack_a is currently unused here (kept for a
 * possible future use, silenced with (void)). */
void	print_bench(t_stack *stack_a, double disorder,
					char *strategy, char *complexity)
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

/* Strips a leading "--" from an explicit flag (e.g. "--simple" ->
 * "simple") so it matches the plain names get_complexity and
 * print_bench expect. Returns flag unchanged if it has no "--"
 * prefix. */
char	*get_plain_strategy(char *flag)
{
	if (flag[0] == '-' && flag[1] == '-')
		return (flag + 2);
	return (flag);
}

/* Maps a plain strategy name to its complexity class string for
 * --bench reporting. */
char	*get_complexity(char *strategy, t_stack *stack_a,
						t_stack *stack_b, double disorder)
{
	if (ft_strncmp(strategy, "simple", 7) == 0)
		return ("O(n^2)");
	else if (ft_strncmp(strategy, "medium", 7) == 0)
		return ("O(n*sqrt(n))");
	else if (ft_strncmp(strategy, "complex", 8) == 0)
		return ("O(n*log(n))");
	return (adaptive_alg(stack_a, stack_b, disorder));
}

/* Tracks per-operation counts in a function-local static array (11
 * slots, one per operation). Dual-purpose by index range: negative
 * resets all counters to 0; 0-10 increments and returns that slot's
 * count (called from inside sa/sb/.../pb as each operation runs);
 * 100-110 reads a slot without incrementing, by subtracting 100
 * (used by print_bench/print_op_counting to report totals after
 * the fact). Any other index falls through to a safe 0 rather than
 * an out-of-bounds read. */
int	count_operations(int op_index)
{
	static int	op_counter[11];
	int			i;

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
	return (op_counter[op_index]);
}
