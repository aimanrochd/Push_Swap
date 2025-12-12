CC = cc
CFLAGS = -Wall -Wextra -Werror 

SRC =  srcs/main.c 						\
       srcs/libft_utils/libft_utils_2.c  \
       srcs/libft_utils/libft_utils.c 	  \
       srcs/operations/operations_utils.c  \
       srcs/operations/push_ops.c 			\
       srcs/operations/rotate_ops.c 		 \
       srcs/operations/rrr.c 				  \
       srcs/operations/swap_ops.c 			   \
       srcs/parsing/parse_args.c 				\
       srcs/sorting/sort_small.c 				 \
       srcs/sorting/sort_utils.c 				  \
       srcs/stacks/stack_utils.c				   \
	   srcs/stacks/stack_init.c


OBJ = $(SRC:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o push_swap

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all