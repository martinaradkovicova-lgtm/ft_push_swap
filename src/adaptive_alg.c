/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_alg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 12:27:43 by mradkovi          #+#    #+#             */
/*   Updated: 2026/10/03 18:50:32 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* Adaptive strategy: picks an internal algorithm based on measured
 * disorder, per the subject's required thresholds (<0.2 -> O(n^2),
 * 0.2-0.5 -> O(n*sqrt(n)), >=0.5 -> O(n*log(n))), with a size<=5
 * shortcut to simple_alg since the hardcoded small-case sorts beat
 * medium/complex for trivially small stacks regardless of disorder.
 * Returns the complexity class string of whichever algorithm ran,
 * for direct use in --bench reporting */
char	*adaptive_alg(t_stack *stack_a, t_stack *stack_b, double disorder)
{
	if (stack_a == NULL || stack_b == NULL)
		return ("none");
	if (disorder == 0.0)
		return ("none");
	else if (stack_a->size <= 5 || disorder < 0.2)
	{
		simple_alg(stack_a, stack_b);
		return ("O(n^2)");
	}
	else if (disorder < 0.5)
	{
		medium_alg(stack_a, stack_b);
		return ("O(n√n)");
	}
	complex_alg(stack_a, stack_b);
	return ("O(n*log(n))");
}
