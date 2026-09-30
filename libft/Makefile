# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hpiotrow <hpiotrow@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/22 15:17:04 by hpiotrow          #+#    #+#              #
#    Updated: 2026/09/26 11:47:18 by hpiotrow         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
AR		= ar rcs
SRC     = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
ft_lstmap.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
ft_isprint.c ft_toupper.c ft_tolower.c ft_strlen.c \
ft_strlcpy.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
ft_strlcat.c ft_strnstr.c ft_atoi.c ft_strdup.c ft_substr.c ft_strjoin.c \
ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_memset.c \
ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
ft_calloc.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_printf.c ft_putchar.c ft_puthex_lower.c ft_puthex_upper.c ft_putnbr.c \
ft_putptr.c ft_putstr.c ft_putunsign.c

OBJS	= ${SRC:.c=.o}

CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME): ${OBJS}
		${AR} $(NAME) ${OBJS}

%.o: %.c libft.h
		${CC} ${CFLAGS} -c $< -o $@

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} $(NAME)

re: fclean all

.PHONY: all clean fclean re
