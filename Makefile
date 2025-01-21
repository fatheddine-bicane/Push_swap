CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap
HEADER = push_swap.h
SRCS =	 	command_push.c command_reverse_rotate.c command_rotate.c command_swap.c ft_free_stack.c \
			split.c ft_print_error.c ft_stack_check.c ft_stack_manag.c init_node_b.c init_nodes_a.c \
			max_min.c prep_for_push.c rr_rrr_both.c sort_for_tree.c sort_stack.c stack_len.c stack_sorted.c \

OFILES = $(SRCS:.c=.o)


$(NAME) : $(OFILES)

all : $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@
	ar rcs $(NAME) $@

clean:
	rm -rf  $(OFILES) $(BOFILES)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

bonus: $(BOFILES)

.PHONY:	all bonus clean

