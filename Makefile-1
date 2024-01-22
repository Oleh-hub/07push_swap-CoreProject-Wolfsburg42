# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oruban <oruban@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/11 09:36:45 by oruban            #+#    #+#              #
#    Updated: 2023/12/11 09:36:45 by oruban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#ft_printf
NAME		:=	libftprintf.a
SRCS		:=	ft_printf.c	\
				upxx_out.c
LIB_PATH	:=	libft/
LIB			:=	$(LIB_PATH)libft.a

# SRCS_BONUS	:=

OBJS		:=	$(SRCS:.c=.o)
# OBJS_BONUS	:=	$(SRCS_BONUS:.c=.o)
# CFLAGS variable garantees the usage of the flags by default in 'make aaa.o'
CFLAGS		:=  -Wall -Wextra -Werror
CC			:=	gcc

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	mv $(LIB) $(NAME)
	ar rs $(NAME) $(OBJS)

$(LIB):
	make -C $(LIB_PATH) all bonus clean

# .c.o:
# %.o: %.c
# 	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	# rm -f $(OBJS_BONUS)

fclean: clean
	make -C $(LIB_PATH) $@
	rm -f $(NAME)

re: fclean all

# bonus: $(OBJS_BONUS) $(NAME)
# 	ar rs $(NAME) $(OBJS_BONUS)