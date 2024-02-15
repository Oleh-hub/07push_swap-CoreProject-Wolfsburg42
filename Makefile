# valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./push_swap hello\ world

NAME 		:= push_swap
CFLAGS 		:= -Wall -Wextra -Werror -g
SRCS 		:=	push_swap.c		\
				stack_utils1.c	\
				sort_utils2.c	\
				slarge_utils3.c	\
				slarge_utils4.c \
				move_nodes5.c	\
				others99.c

OBJS 		:= $(SRCS:.c=.o)
LIB_PATH 	:= libft/
LIB 		:= $(LIB_PATH)libft.a

$(NAME): $(OBJS) $(LIB)

$(LIB):
	make -C $(LIB_PATH) all bonus
# make -C $(LIB_PATH) all bonus clean

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f push_swap
	rm -f *.out
	make -C $(LIB_PATH) $@

re: fclean all