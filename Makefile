# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/24 15:42:15 by kbossio           #+#    #+#              #
#    Updated: 2025/02/04 16:20:19 by kbossio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
SRCS = push_swap.c node_utils.c push_swap_utils.c simple_sort.c solve.c solve_utils.c create_stack.c instructions/push.c instructions/rotate.c instructions/reverse_rotate.c instructions/swap.c
OBJS = $(SRCS:.c=.o)
BSRCS = bonus/checker_bonus.c bonus/checker_utils_bonus.c node_utils.c push_swap_utils.c create_stack.c instructions/push.c instructions/rotate.c instructions/reverse_rotate.c instructions/swap.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
BOBJS = $(BSRCS:.c=.o)

%.o: %.c
	gcc -Wall -Wextra -Werror -I./ -c $< -o $@

$(NAME): $(OBJS)
	gcc -Wall -Wextra -Werror $(OBJS) -o $(NAME)

all: $(NAME) $(CHECKER)

$(CHECKER): $(BOBJS)
	gcc -Wall -Wextra -Werror $(BOBJS) -o $(CHECKER)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

bonus: $(CHECKER)

.PHONY: all clean fclean re bonus