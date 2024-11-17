# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abnaciri <abnaciri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/11 14:02:11 by abnaciri          #+#    #+#              #
#    Updated: 2024/05/29 09:20:45 by abnaciri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER = push_swap.h
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f
AR = ar crs
SRC = main.c \
	parse_input.c \
	parse_utils.c \
	utils.c \
	ft_split.c \
	sort3.c \
	sort4.c \
	instructions.c \
	swap.c \
	sort5.c \
	rotate.c \
	sort_big.c \
	sort_big_utils.c 

OBJ = $(SRC:.c=.o)
all : $(NAME)
$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)
fclean : clean
	$(RM) $(NAME)
re : fclean all
.PHONY : all clean fclean re