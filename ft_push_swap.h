/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 13:50:22 by hpiotrow          #+#    #+#             */
/*   Updated: 2026/10/03 17:05:13 by hpiotrow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft.h"

typedef struct s_num
{
	int				value;
	int				index;
	struct s_num	*next;
	struct s_num	*prev;
}	t_num;

typedef struct s_stack
{
	t_num	*top;
	t_num	*bottom;
	int		size;
}	t_stack;

/* main functions */
int		arg_checker(int argc);
int		run_push_swap(t_stack *stack_a, t_stack *stack_b, char *strategy,
			int bench);

/*simple_alg*/
void	simple_alg(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack *stack_a);
void	sort_four(t_stack *stack_a, t_stack *stack_b);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
int		four_minimum_index(t_stack *stack_a);
int		five_minimum_index(t_stack *stack_a);
int		find_maximum_position(t_stack *stack_b, int *maximum, int *minimum);
int		find_beast_cost(t_stack *stack_a, t_stack *stack_b);
void	push_beast(t_stack *stack_a, t_stack *stack_b, int possition);
int		find_target_position(t_stack *stack_b, int top_a_value);
void	align_stack_b(t_stack *stack_b);
int		cost_stack_b(t_stack *stack_b, int value);
int		cost_stack_a(t_stack *stack_a, int index);
int		total_cost(int cost_a, int cost_b);
void	both_rotate(t_stack *stack_a, t_stack *stack_b,
			int *cost_a, int *cost_b);
void	single_rotate(t_stack *stack_a, t_stack *stack_b,
			int cost_a, int cost_b);
void	push_beast(t_stack *stack_a, t_stack *stack_b, int possition);
void	insertion_sort(t_stack *stack_a, t_stack *stack_b);

/* medium algorithm */
void	medium_alg(t_stack *stack_a, t_stack *stack_b);
void	check_chunk(t_stack *stack_a, t_stack *stack_b, int chunk_start,
			int chunk_end);
int		find_max(t_stack *stack);
void	bring_to_top_b(t_stack *stack_b, int position);
int		ft_sqrt(int nb);

/* complex algorithm */
void	complex_alg(t_stack *stack_a, t_stack *stack_b);
int		count_bits(t_stack *stack_a);
void	radix_pass(t_stack *stack_a, t_stack *stack_b, int i);

/* adaptive algorithm */
char	*adaptive_alg(t_stack *stack_a, t_stack *stack_b, double disorder);

/* pre-sort */
void	pre_sort(t_stack *stack_a);
void	bubble_sort(int *temp_array, int len);
void	assign_index(int *str, t_stack *stack_a);

/* sorting functions */
void	push_stack_top(t_stack *src, t_stack *dest);
void	pa(t_stack *stack_b, t_stack *stack_a);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	swap_stack(t_stack *stack);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	rotate_stack(t_stack *stack);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate_stack(t_stack *stack);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

/* bench output */
void	print_bench(t_stack *stack_a, double disorder, char *strategy,
			char *complexity);
char	*get_plain_strategy(char *flag);
char	*get_complexity(char *strategy, t_stack *stack_a, t_stack *stack_b,
			double disorder);
int		count_operations(int op_index);
void	print_op_counting(void);
void	ft_put_percent_fd(double disorder, int fd);

/* stack operations */
int		fill_stack_a(t_stack *stack_a, int argc, char **argv,
			int numbers_start);
void	create_empty_stack(t_stack *stack_a);
t_num	*create_new_number(int num);
void	push_new_number(t_stack *stack, t_num *new_num);
char	*join_args(int argc, char **argv, int numbers_start);
void	clean_split_memory(char **splited_args);
void	clean_stack_memory(t_stack *stack);

/* count disorder */
double	compute_disorder(t_stack *stack_a);

/* strategy */
void	strategy_selector(char *flag, t_stack *stack_a, t_stack *stack_b);
char	*find_strategy(char **argv, int numbers_start, int *bench);
int		validate_flag(char *flag);
int		validate_all_flags(int argc, char **argv);

/* arguments validation */
int		validate_args(char **splited_args);
int		duplicity_checker(char **splited_args, int len);
int		fill_sorted_copy(char **args, int *copy, int len);
void	ft_swap(int *a, int *b);

/* print stack for testing */
void	print_stack(t_stack *stack_a);

#endif
