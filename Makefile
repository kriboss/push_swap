# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/24 15:42:15 by kbossio           #+#    #+#              #
#    Updated: 2025/01/09 13:53:02 by kbossio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
SRCS = push_swap.c node_utils.c push_swap_utils.c simple_sort.c solve.c instructions/*.c
OBJS = $(SRCS:.c=.o)
BSRCS = bonus/checker
BOBJS = $(BSRCS:.c=.o)
%.o: %.c
	gcc -Wall -Wextra -Werror -I./ -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(CHECKER): $(BOBJS)
	gcc -Wall -Wextra -Werror -I./ -o $(CHECKER) $(BOBJS)

all: $(NAME) $(CHECKER)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:
	gcc -Wall -Wextra -Werror -Igetnextline$(BSRCS) -o checker

.PHONY: all clean fclean re bonus