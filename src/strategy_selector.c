/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy_selector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:36:46 by mradkovi          #+#    #+#             */
/*   Updated: 2026/10/03 17:28:25 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* Dispatches to the matching explicit strategy based on flag.
 * --adaptive is intentionally not handled here, since adaptive
 * is called directly from run_push_swap so its real internal
 * choice can be captured for --bench reporting. */
void	strategy_selector(char *flag, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp("--simple", flag, 9) == 0)
		simple_alg(stack_a, stack_b);
	if (ft_strncmp("--medium", flag, 9) == 0)
		medium_alg(stack_a, stack_b);
	if (ft_strncmp("--complex", flag, 10) == 0)
		complex_alg(stack_a, stack_b);
}

/* Scans argv[1..numbers_start) for flags: sets *bench if --bench
 * is present, and returns the first non-bench flag found (or NULL
 * if none, meaning adaptive should be used by default). */
char	*find_strategy(char **argv, int numbers_start, int *bench)
{
	int		i;
	char	*strategy;

	i = 1;
	strategy = NULL;
	*bench = 0;
	while (i < numbers_start)
	{
		if (ft_strncmp(argv[i], "--bench", 8) == 0)
			*bench = 1;
		else if (strategy == NULL)
			strategy = argv[i];
		i++;
	}
	return (strategy);
}

/* Checks a single argument against the four known strategy flags.
 * Returns 1 if valid, 0 if it's not a flag at all (doesn't start
 * with --), or -1 if it starts with -- but matches nothing known. */
int	validate_flag(char *flag)
{
	if (ft_strncmp(flag, "--", 2) != 0)
		return (0);
	if (ft_strncmp("--simple", flag, 9) == 0)
		return (1);
	else if (ft_strncmp("--medium", flag, 9) == 0)
		return (1);
	else if (ft_strncmp("--complex", flag, 10) == 0)
		return (1);
	else if (ft_strncmp("--adaptive", flag, 11) == 0)
		return (1);
	else
		return (-1);
}

/* Walks argv past every leading flag (--bench and/or one strategy
 * flag), validating each one. Returns the index of the first
 * non-flag argument (where numbers start), or -1 if an unknown
 * flag was found. */
int	validate_all_flags(int argc, char **argv)
{
	int	i;
	int	result;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--bench", 8) == 0)
			i++;
		else
		{
			result = validate_flag(argv[i]);
			if (result == 1)
				i++;
			else if (result == -1)
				return (-1);
			else
				break ;
		}
	}
	return (i);
}
