# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 18:42:42 by lrosalee          #+#    #+#              #
#    Updated: 2020/01/20 18:47:39 by lrosalee         ###   ########.fr        #
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


OBJS = ft_printf.o parse.o ./char/print_cs.o \
         ./numbers/print_di.o ./numbers/print_number.o \
         ./tools/flag.o ./tools/length.o ./tools/precision.o \
         ./tools/print_flag.o ./tools/print_padding.o \
         ./tools/width.o \
         ./utilits/ft_atoi.o ./utilits/ft_bzero.o ./utilits/ft_longlong_len.o \
         ./utilits/ft_memset.o ./utilits/ft_putchar.o ./utilits/ft_putnstr.o \
         ./utilits/ft_putstr.o ./utilits/ft_str_multi_chr.o ./utilits/ft_strchr.o \
         ./utilits/ft_strcmp.o ./utilits/ft_strlen.o ./utilits/ft_strncpy.o \
         ./utilits/ft_strndup.o ./utilits/ft_strnew.o \

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
