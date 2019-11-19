# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkhabour <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 15:58:57 by kkhabour          #+#    #+#              #
#    Updated: 2019/11/19 00:40:20 by kkhabour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
SRC=main.c checkmap.c ./GNL/get_next_line.c storage.c draw.c
FLAGS= -g -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./GNL/libft/
	make -C minilibx
	mv minilibx/libmlx.a .
	mv ./GNL/libft/libft.a .
	gcc -Wall -g -Werror -Wextra -c $(SRC)
	gcc -Wall -g -Werror -Wextra -L. -lmlx -framework OpenGL -framework Appkit $(OBJ) libft.a -o $(NAME)

clean:
	make -C ./minilibx clean
	make -C ./GNL/libft clean
	rm -rf $(OBJ) libft.a libmlx.a

fclean: clean
	make -C ./GNL/libft fclean
	rm -rf $(NAME)

re : fclean all
