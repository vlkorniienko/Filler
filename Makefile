# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkorniie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/18 10:07:42 by vkorniie          #+#    #+#              #
#    Updated: 2018/08/30 16:48:33 by vkorniie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = vkorniie.filler
SRCS = filler_begin.c filler_second.c filler_third.c
FLAGS = -Wall -Werror -Wextra

all: $(NAME) 

$(NAME): $(SRCS)
	@ make -C libft re
	@ gcc $(FLAGS) $(SRCS) libft/libft.a -o $(NAME)

%.o:%.c
	@ gcc -c $< -o $@ $(FLAGS)

clean:
	@ make -C libft clean

fclean: clean
	@ rm -f $(NAME)
	@ make -C libft fclean

re: fclean all
