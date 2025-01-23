CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = push_swap
BNAME = checker
HEADER = push_swap.h
SRCS =	 	command_push.c command_reverse_rotate.c command_rotate.c command_swap.c \
			create_main_stack.c create_stack_utils.c free_functions.c initialize_a.c \
			initialize_b.c main_function.c sort_stack.c sort_stack_of_3.c \
			sorting_utils_1.c sorting_utils_2.c split.c \

BONNUS =	bonus_apply_command.c bonus_get_next_line.c bonus_get_nex_line_utils.c bonus_main.c \

OFILES = $(SRCS:.c=.o)
BOFILES = $(BONNUS:.c=.o)

$(NAME) : $(OFILES)
$(BNAME) : $(BOFILES)

all : $(NAME)

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@
	ar rcs $(NAME) $@

$(NAME) : $(OFILES)
	$(CC) $(FLAGS) $(OFILES) -o $(NAME)

clean:
	rm -rf  $(OFILES)

fclean:	clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all bonus clean

