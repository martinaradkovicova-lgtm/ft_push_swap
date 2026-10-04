/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_output_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 11:20:07 by hpiotrow          #+#    #+#             */
/*   Updated: 2026/10/03 18:49:56 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/* Writes the per-operation-type breakdown to stderr (one line per
 * operation: sa, sb, ss, ra, rb, rr, rra, rrb, rrr, pa, pb), using
 * count_operations' read-only range (100-110) to fetch each
 * count without incrementing it. Called from print_bench as the
 * last part of the --bench report. */
void	print_op_counting(void)
{
	write(2, "sa: ", 4);
	ft_putnbr_fd(count_operations(100), 2);
	write(2, "\nsb: ", 5);
	ft_putnbr_fd(count_operations(101), 2);
	write(2, "\nss: ", 5);
	ft_putnbr_fd(count_operations(102), 2);
	write(2, "\nra: ", 5);
	ft_putnbr_fd(count_operations(103), 2);
	write(2, "\nrb: ", 5);
	ft_putnbr_fd(count_operations(104), 2);
	write(2, "\nrr: ", 5);
	ft_putnbr_fd(count_operations(105), 2);
	write(2, "\nrra: ", 6);
	ft_putnbr_fd(count_operations(106), 2);
	write(2, "\nrrb: ", 6);
	ft_putnbr_fd(count_operations(107), 2);
	write(2, "\nrrr: ", 6);
	ft_putnbr_fd(count_operations(108), 2);
	write(2, "\npa: ", 5);
	ft_putnbr_fd(count_operations(109), 2);
	write(2, "\npb: ", 5);
	ft_putnbr_fd(count_operations(110), 2);
	write(2, "\n", 1);
}

/* Writes disorder (a 0.0-1.0 fraction) to fd as a percentage with
 * two decimal places, e.g. 0.8333 -> "83.33%\n". Scales to
 * hundredths-of-a-percent as a whole number first (since no float
 * formatting is available), then splits that into the whole-percent
 * part and the two-decimal part, padding a leading zero on the
 * decimal part when needed (so 3.05% doesn't print as "3.5%"). */
void	ft_put_percent_fd(double disorder, int fd)
{
	int	percent;

	percent = (int)(disorder * 10000);
	ft_putnbr_fd(percent / 100, fd);
	write(fd, ".", 1);
	if (percent % 100 < 10)
		write(fd, "0", 1);
	ft_putnbr_fd(percent % 100, fd);
	write(fd, "%\n", 2);
}
