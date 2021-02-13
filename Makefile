# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/06 14:23:58 by ynakamot          #+#    #+#              #
#    Updated: 2021/02/14 00:07:04 by ynakamot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
CFLAGS = -Wall -Wextra -Werror

SRCFILE =   srcs/ft_strlen.s \
			srcs/ft_strcpy.s \
			srcs/ft_strcmp.s \
			srcs/ft_write.s \
			srcs/ft_read.s \
			srcs/ft_strdup.s \


B_SRCFILE = srcs/ft_atoi_base.s \
			srcs/ft_list_push_front.s \
			srcs/ft_list_size.s \
			srcs/ft_list_sort.s

OBJECTS = $(SRCFILE:.s=.o)
B_OBJECTS = $(B_SRCFILE:.s=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

bonus: $(OBJECTS) $(B_OBJECTS)
	ar rcs $(NAME) $(OBJECTS) $(B_OBJECTS)

%.o: %.s
	nasm -g -felf64 $<

test: $(NAME)
	gcc -g -o test main.c tests.c -lasm -L./
	./test

bonustest: bonus
	gcc -g -o test main_bonus.c -lasm -L./

clean:
	$(RM) $(OBJECTS) $(B_OBJECTS)

fclean:
	$(RM) $(OBJECTS) $(B_OBJECTS) $(NAME)

re: fclean all

.PHONY: all clean fclean re test