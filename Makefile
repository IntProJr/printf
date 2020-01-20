# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 18:42:42 by lrosalee          #+#    #+#              #
#    Updated: 2020/01/20 21:28:06 by lrosalee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

SRCS = ft_printf.c parse.c ./char/print_cs.c \
		./numbers/print_di.c ./numbers/print_number.c \
		./tools/flag.c ./tools/length.c ./tools/precision.c \
		./tools/print_flag.c ./tools/print_padding.c \
		./tools/width.c \
		./utilits/ft_atoi.c ./utilits/ft_bzero.c ./utilits/ft_longlong_len.c \
		./utilits/ft_memset.c ./utilits/ft_putchar.c ./utilits/ft_putnstr.c \
		./utilits/ft_putstr.c ./utilits/ft_str_multi_chr.c ./utilits/ft_strchr.c \
		./utilits/ft_strcmp.c ./utilits/ft_strlen.c ./utilits/ft_strncpy.c \
		./utilits/ft_strndup.c ./utilits/ft_strnew.c


OBJS = ./ft_printf.o ./parse.o ./print_cs.o \
         ./print_di.o ./print_number.o \
         ./flag.o length.o ./precision.o \
         ./print_flag.o ./print_padding.o \
         ./width.o \
         ./ft_atoi.o ./ft_bzero.o ./ft_longlong_len.o \
         ./ft_memset.o ./ft_putchar.o ./ft_putnstr.o \
         ./ft_putstr.o ./ft_str_multi_chr.o ./ft_strchr.o \
         ./ft_strcmp.o ./ft_strlen.o ./ft_strncpy.o \
         ./ft_strndup.o ./ft_strnew.o \

CCFL = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCS) 
	@gcc $(CCFL) -I ./ -c $(SRCS) 
	@ar rc $(NAME) $(OBJS)
	
%.o: %.c ft_printf.h
	@gcc -Wall -Wextra -Werror -c $<
	
clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
