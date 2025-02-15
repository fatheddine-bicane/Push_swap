CC = cc
FLAGS = -Wall -Wextra -Werror -g
NAME = push_swap
BNAME = checker

SRCS =	command_push.c command_reverse_rotate.c command_rotate.c command_swap.c \
		create_main_stack.c create_stack_utils.c free_functions.c initialize_a.c \
		initialize_b.c main_function.c sort_stack.c sort_stack_of_3.c \
		sorting_utils_1.c sorting_utils_2.c split.c

BONUS =	apply_command_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c \
		command_push.c command_reverse_rotate.c command_rotate.c command_swap.c \
		create_main_stack.c create_stack_utils.c free_functions.c split.c sorting_utils_1.c sorting_utils_2.c \

OFILES = $(SRCS:.c=.o)
BOFILES = $(BONUS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OFILES)
	$(CC) $(FLAGS) $(OFILES) -o $(NAME)

checker: $(BNAME)

$(BNAME): $(BOFILES)
	$(CC) $(FLAGS) $(BOFILES) -o $(BNAME)

clean:
	rm -f $(OFILES) $(BOFILES)

fclean: clean
	rm -f $(NAME) $(BNAME)

re: fclean all

re_bonus : fclean bonus

.PHONY: all bonus clean fclean re
