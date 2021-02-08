# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/06 14:23:58 by ynakamot          #+#    #+#              #
#    Updated: 2021/02/08 22:42:26 by ynakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
CFLAGS = -Wall -Wextra -Werror

SRCFILE =   srcs/ft_strlen.s \
			srcs/ft_strcpy.s \
			srcs/ft_strcmp.s \
			srcs/ft_write.s \
			srcs/ft_read.s

OBJECTS = $(SRCFILE:.s=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.s
	nasm -g -felf64 $<

test: $(NAME)
	gcc -g -no-pie -o test test.c -lasm -L./
	./test
	$(RM) test

clean:
	$(RM) $(OBJECTS)

fclean:
	$(RM) $(OBJECTS) $(NAME)

re: fclean all

.PHONY: all clean fclean re test