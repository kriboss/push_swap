# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/24 15:42:15 by kbossio           #+#    #+#              #
#    Updated: 2024/12/25 20:50:11 by kbossio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
SRCS = push_swap.c node_utils.c push_swap_utils.c simple_sort.c solve.c /instructions/*.c
OBJS = $(SRCS:.c=.o)
%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re