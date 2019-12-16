# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkhabour <kkhabour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 15:58:57 by kkhabour          #+#    #+#              #
#    Updated: 2019/12/16 20:11:06 by kkhabour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
SRCS=main.c checkmap.c storage.c draw.c event.c errors.c
OBJS=$(SRCS:.c=.o)
CC=gcc
CFLAGS= -Wall -Wextra -Werror

all: $(NAME)
$(NAME): $(OBJS)
	make -C libft
	$(CC) $(FLAGS) -L. -lmlx -framework OpenGL -framework Appkit $(OBJS) ./libft/libft.a -o $(NAME)

$(OBJS): %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)

re : fclean all

norme:
	norminette -R CheckForbiddenSourceHeader $(SRCS)