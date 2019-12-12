# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkhabour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 15:58:57 by kkhabour          #+#    #+#              #
#    Updated: 2019/12/11 22:56:08 by kkhabour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
SRC=main.c checkmap.c ./lib/get_next_line.c storage.c draw.c event.c
FLAGS= -Wall -Wextra -Werror


all: $(NAME)

$(NAME):
	make -C ./lib/libft/
	mv ./lib/libft/libft.a .
	gcc $(FLAGS) -L. -lmlx -framework OpenGL -framework Appkit $(SRC) libft.a -o $(NAME)
clean:
	make -C ./lib/libft clean
	rm -rf  libft.a

fclean: clean
	make -C ./lib/libft fclean
	rm -rf $(NAME) fdf.dSYM

re : fclean all

norme:
	norminette *.c
