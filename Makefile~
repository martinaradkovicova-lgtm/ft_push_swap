NAME	= push_swap

CC		= gcc
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror
DEPFLAGS	= -MMD -MP

SRC_DIR	= src
OBJ_DIR	= obj

SRC		= ft_push_swap.c ft_push_swap_sort.c ft_push_swap_operations.c \
		ft_push_swap_disorder.c selection_sort.c medium_alg.c complex_alg.c \
		adaptive_alg.c ft_put_percent_fd.c bench_output.c

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
