#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft.h"

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
} t_stack;

void swap_stack(t_stack *stack);
void ft_swap(int *a, int *b);
void sa(t_stack *stack_a);
void sb(t_stack *stack_b);
void ss(t_stack *stack_a, t_stack *stack_b);
void rotate_stack(t_stack *stack);
void ra(t_stack *stack_a);
void rb(t_stack *stack_b);
void rr(t_stack *stack_a, t_stack *stack_b);
void reverse_rotate_stack(t_stack *stack);
void rra(t_stack *stack_a);
void rrb(t_stack *stack_b);
void rrr(t_stack *stack_a, t_stack *stack_b);
void push_stack_top(t_stack *src, t_stack *dest);
void pa(t_stack *stack_b, t_stack *stack_a);
void pb(t_stack *stack_a, t_stack *stack_b);
void sort_three(t_stack *stack_a);
void sort_four(t_stack *stack_a, t_stack *stack_b);
void simple_alg(t_stack *stack_a, t_stack *stack_b);
double compute_disorder (t_stack *stack_a);
void sort_five(t_stack *stack_a, t_stack *stack_b);
int find_minimum(t_stack *stack);
void push_minimum(t_stack *Stack_a, t_stack *Stack_b, int min_pos);
void selection_sort(t_stack *Stack_a, t_stack *Stack_b);
int count_operations(int op_index);
void print_op_counting(void);
int run_push_swap(int argc, char **argv, int numbers_start, char *strategy, int bench);

/* medium algorithm */
void pre_sort(t_stack *stack_a);
void ft_assign_index(int *str, t_stack *stack_a);
int ft_sqrt(int nb);
void check_chunk(t_stack *stack_a, t_stack *stack_b, int chunk_start, int chunk_end);
void medium_alg(t_stack *stack_a, t_stack *stack_b);
int find_max(t_stack *stack);
void bring_to_top_b(t_stack *stack_b, int position);

/* complex algorithm */
int count_bits(t_stack *stack_a);
void radix_pass(t_stack *stack_a, t_stack *stack_b, int i);
void complex_alg(t_stack *stack_a, t_stack *stack_b);

/* adaptive algorithm */
char *adaptive_alg(t_stack *stack_a, t_stack *stack_b, double disorder);

/* helper functions */
/* functions in ft_push_swap.c */
void ft_put_percent_fd(double disorder, int fd);
void print_bench(t_stack *stack_a, double disorder, char *strategy, char *complexity);
char *get_plain_strategy(char *flag);
char *get_complexity(char *strategy);
char *find_strategy(char **argv, int numbers_start, int *bench);
void strategy_selector(char *flag, t_stack *stack_a, t_stack *stack_b);
int validate_flag(char *flag);
t_num *create_new_number(int num);
void create_empty_stack(t_stack *stack_a);
void push_new_number(t_stack *stack, t_num *new_num);
void clean_split_memory(char **splited_args);
void ft_swap(int *a, int *b);
int duplicity_checker(char **splited_args, int len);
char *join_args(int argc, char **argv, int numbers_start);
int validate_args(char **splited_args);
int fill_stack_a(t_stack *stack_a, int argc, char **argv, int numbers_start);
void clean_stack_memory(t_stack *stack);
int arg_checker(int argc);
int validate_all_flags(int argc, char **argv);
void print_stack(t_stack *stack_a);
/*simple_alg*/
int	find_maximum_position(t_stack *stack_b, int *maximum, int *minimum);

int	find_beast_cost(t_stack *stack_a, t_stack *stack_b);
void	push_beast(t_stack *stack_a, t_stack *stack_b, int possition);
int	find_target_position(t_stack *stack_b, int top_a_value);
void	align_stack_b(t_stack *stack_b);
int	cost_stack_b(t_stack *stack_b, int value);
int	cost_stack_a(t_stack *stack_a, int index);
int	total_cost(int cost_a, int cost_b);
void	both_rotate(t_stack *stack_a, t_stack *stack_b, int *cost_a, int *cost_b);
void	single_rotate(t_stack *stack_a, t_stack *stack_b, int cost_a, int cost_b);
void	push_beast(t_stack *stack_a, t_stack *stack_b, int possition);
void	insertion_sort(t_stack *stack_a, t_stack *stack_b);

#endif
