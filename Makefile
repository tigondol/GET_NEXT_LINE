# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tigondol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/28 23:22:24 by tigondol          #+#    #+#              #
#    Updated: 2018/05/14 13:18:29 by tigondol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	

SRC_PATH = srcs/

NAME =	fillit

OBJS =	$(addprefix $(SRC_PATH), $(SRC:.c=.o))

FLAGS = -Wall -Wextra -Werror

HEADER =	header.h

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	gcc $(FLAGS) $(OBJS) -o $(NAME) -L libft/ -lft

%.o: %.c
	gcc -c $(FLAGS) $< -o $@

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all
