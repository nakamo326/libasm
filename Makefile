# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/06 14:23:58 by ynakamot          #+#    #+#              #
#    Updated: 2021/02/19 16:42:57 by ynakamot         ###   ########.fr        #
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


B_SRCFILE = srcs/ft_atoi_base_bonus.s \
			srcs/ft_list_push_front_bonus.s \
			srcs/ft_list_size_bonus.s \
			srcs/ft_list_sort_bonus.s \
			srcs/ft_list_remove_if_bonus.s

OBJECTS = $(SRCFILE:.s=.o)
B_OBJECTS = $(B_SRCFILE:.s=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

bonus: $(OBJECTS) $(B_OBJECTS)
	ar rcs $(NAME) $(OBJECTS) $(B_OBJECTS)

%.o: %.s
	nasm -F dwarf -g -felf64 $<

test: bonus
	gcc -g -o test main.c tests.c -lasm -L./
	./test

bonustest: all $(B_OBJECTS)
	gcc -g -ggdb -o test main_bonus.c $(B_OBJECTS) -lasm -L./

atoi: $(B_OBJECTS)
	gcc -g -ggdb -o test atoi_test.c $(B_OBJECTS)

clean:
	$(RM) $(OBJECTS) $(B_OBJECTS)

fclean:
	$(RM) $(OBJECTS) $(B_OBJECTS) $(NAME)

re: fclean all

.PHONY: all clean fclean re test