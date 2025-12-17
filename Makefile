NAME    = push_swap
BONUS   = checker

CC      = cc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -f

SRC = push_swap.c \
      parsing.c split_utils.c \
      build_stack.c add_to_stack.c \
      is_sorted.c check.c \
      moves.c moves_2.c moves_3.c \
      target.c cost.c final.c \
      push_swap_utils.c \
      stack_helpers.c

OBJ = $(SRC:.c=.o)

BONUS_SRC = checker.c \
            parsing_bonus.c split_utils_bonus.c \
            build_stack_bonus.c add_to_stack_bonus.c \
            is_sorted_bonus.c check_bonus.c \
            moves_bonus.c moves_2_bonus.c moves_3_bonus.c \
            push_swap_utils_bonus.c \
            stack_helpers_bonus.c \
            get_next_line.c get_next_line_utils.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
.SECONDARY: $(BONUS_OBJS) $(OBJS)