NAME    = push_swap

CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

SRC     = push_swap.c \
          parsing.c split_utils.c \
          build_stack.c add_to_stack.c \
          is_sorted.c check.c \
          moves.c moves_2.c moves_3.c \
          target.c cost.c final.c \
          push_swap_utils.c

OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
