# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkhabour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 15:58:57 by kkhabour          #+#    #+#              #
#    Updated: 2019/10/29 20:43:44 by kkhabour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
LIBFT=./GNL/libft/libft.a
FILES=main.c checkmap.c ./GNL/get_next_line.c storage.c
FLAGS= -g -Wall -Wextra -Werror

all:
	Make -C ./GNL/libft/
	gcc $(FLAGS) $(FILES) $(LIBFT) -o $(NAME)

clean:
	Make -C ./GNL/libft/ clean
	rm -f *.o ./GNL/*.o
fclean: clean
	rm -f $(LIBFT) $(NAME)
re: fclean all
