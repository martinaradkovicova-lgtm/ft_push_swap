/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:36:55 by mradkovi          #+#    #+#             */
/*   Updated: 2026/10/03 17:26:28 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* Checks that every split argument is a valid integer string
 * (optional leading +/-, digits only, not empty after the sign),
 * then rejects the whole set if duplicity_checker finds a repeat.
 * Returns 1 if all arguments are valid and unique, 0 otherwise. */
int	validate_args(char **splited_args)
{
	int	i;
	int	j;

	i = 0;
	while (splited_args[i] != NULL)
	{
		j = 0;
		if (splited_args[i][j] == '+' || splited_args[i][j] == '-')
			j++;
		if (splited_args[i][j] == '\0')
			return (0);
		while (splited_args[i][j] != '\0')
		{
			if ((splited_args[i][j] < '0') || (splited_args[i][j] > '9'))
				return (0);
			j++;
		}
		i++;
	}
	if (duplicity_checker(splited_args, i) == 1)
		return (0);
	return (1);
}

/* Converts each string in args to a long via ft_atoi and copies it
 * into copy, rejecting (returns 1) any value outside int range.
 * Then bubble-sorts copy in place so duplicity_checker can find
 * duplicates via adjacent comparison. Returns 0 on success. */
int	fill_sorted_copy(char **args, int *copy, int len)
{
	int		i;
	int		j;
	long	num;

	i = 0;
	while (i < len)
	{
		num = ft_atoi(args[i]);
		if (num > 2147483647L || num < -2147483648L)
			return (1);
		copy[i++] = (int)num;
	}
	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (copy[j] > copy[j + 1])
				ft_swap(&copy[j], &copy[j + 1]);
			j++;
		}
		i++;
	}
	return (0);
}

/* Allocates a working copy of the arguments as ints, delegating
 * conversion/overflow-checking/sorting to fill_sorted_copy. Then
 * scans the sorted copy for adjacent duplicates (any match means
 * a repeated value existed somewhere in the original input).
 * Frees the copy before returning. Returns 1 on malloc failure,
 * overflow, or a duplicate found; 0 if all values are valid and
 * unique. */
int	duplicity_checker(char **splited_args, int len)
{
	int	*splited_copy;
	int	i;
	int	result;

	splited_copy = (int *)malloc(sizeof(int) * len);
	if (splited_copy == NULL)
		return (1);
	if (fill_sorted_copy(splited_args, splited_copy, len) == 1)
		return (free(splited_copy), 1);
	result = 0;
	i = 0;
	while (i < len - 1)
	{
		if (splited_copy[i] == splited_copy[i + 1])
			result = 1;
		i++;
	}
	free(splited_copy);
	return (result);
}

/* Swaps the values pointed to by a and b. */
void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}
