NAME	= push_swap

CC		= gcc
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror
DEPFLAGS	= -MMD -MP

SRC_DIR	= src
OBJ_DIR	= obj

SRC		= main.c sorting_functions_push.c medium_alg.c sorting_functions_revrotate.c \
adaptive_alg.c pre_sort.c sorting_functions_rotate.c bench_output.c print_stack.c \
sorting_functions_swap.c bench_output_utils.c simple_alg.c stack_functions.c \
clean_memory.c simple_alg_utils1.c strategy_selector.c complex_alg.c simple_alg_utils2.c \
validate_args.c compute_disorder.c sort_3_4_5.c

OBJS	= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEPS	= $(OBJS:.o=.d)

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

INCLUDES	= -I. -I$(LIBFT_DIR)

all:	$(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	${RM} $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	${RM} $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
