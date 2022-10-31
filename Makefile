NAME = push_swap

SRC = main.c  handle_params.c libft.c check_if_is_valid.c push_to_stacks.c instructions.c return_indexes.c sort_3.c sort_5.c ft_free.c  sort.c ft_func.c

SRCO = $(SRC:.c=.o)

CC = gcc  -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCO)
	@$(CC) $^ -o $(NAME)

%.o : %.c
	$(CC) -c $<

clean:
	rm -rf $(SRCO)

fclean: clean
	rm -rf $(NAME)
 
re: fclean all
