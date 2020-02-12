# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/20 18:42:42 by lrosalee          #+#    #+#              #
#    Updated: 2020/02/12 22:17:50 by lrosalee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c parse.c ./char/print_cs.c \
        ./char/print_ptr.c \
		./numbers/print_di.c ./numbers/print_number.c \
		./numbers/print_x.c ./numbers/print_f.c\
		./tools/flag.c ./tools/length.c ./tools/precision.c \
		./tools/print_flag.c ./tools/print_padding.c \
		./tools/width.c \
		./utilits/ft_atoi.c ./utilits/ft_bzero.c ./utilits/ft_longlong_len.c \
		./utilits/ft_memset.c ./utilits/ft_putchar.c ./utilits/ft_putnstr.c \
		./utilits/ft_putstr.c ./utilits/ft_str_multi_chr.c ./utilits/ft_strchr.c \
		./utilits/ft_strcmp.c ./utilits/ft_strlen.c ./utilits/ft_strncpy.c \
		./utilits/ft_strndup.c ./utilits/ft_strnew.c ./numbers/print_u.c \
		./utilits/ft_u_longlong_len.c \
		./utilits/ft_putnchar.c ./numbers/print_o.c ./utilits/ft_u_len_base.c \
		./utilits/ft_put_u_longlong_base.c ./utilits/ft_hex_len.c \
        ./utilits/ft_print_u_hex.c ./utilits/ft_ptr_len_base.c \
        ./tools/round_ld.c ./tools/flag_manager_f.c \
        ./numbers/float_to_string.c ./utilits/ft_memalloc.c \
        ./utilits/ft_put_longlong_base.c ./utilits/ft_len_base.c\



OBJS = ./ft_printf.o ./parse.o ./print_cs.o \
         ./print_di.o ./print_number.o \
         ./print_f.o \
         ./flag.o length.o ./precision.o \
         ./print_flag.o ./print_padding.o \
         ./width.o \
         ./ft_atoi.o ./ft_bzero.o ./ft_longlong_len.o \
         ./ft_memset.o ./ft_putchar.o ./ft_putnstr.o \
         ./ft_putstr.o ./ft_str_multi_chr.o ./ft_strchr.o \
         ./ft_strcmp.o ./ft_strlen.o ./ft_strncpy.o \
         ./ft_strndup.o ./ft_strnew.o ./print_u.o \
         ./ft_u_longlong_len.o \
         ./ft_putnchar.o ./print_o.o ./ft_u_len_base.o \
         ./ft_put_u_longlong_base.o ./ft_hex_len.o \
         ./print_x.o ./ft_print_u_hex.o ./print_ptr.o \
         ./ft_ptr_len_base.o \
         round_ld.o flag_manager_f.o float_to_string.o \
         ft_memalloc.o ft_put_longlong_base.o \
         ft_len_base.o \





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
