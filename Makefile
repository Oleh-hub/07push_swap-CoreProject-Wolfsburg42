NAME 		:= push_swap
CFLAGS 		:= -Wall -Wextra -Werror
SRCS 		:=	push_swap.c		\
				stack_utils.c	\
				sort_utils.c

OBJS 		:= $(SRCS:.c=.o)
LIB_PATH 	:= libft/
LIB 		:= $(LIB_PATH)libft.a

$(NAME): $(OBJS) $(LIB)

$(LIB):
	make -C $(LIB_PATH) all bonus clean

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f push_swap
	rm -f *.out
	make -C $(LIB_PATH) $@

re: fclean all