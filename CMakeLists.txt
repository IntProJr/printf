cmake_minimum_required(VERSION 3.15)
project(printf C)

set(CMAKE_C_STANDARD 99)

include_directories(./numbers ./tools ./utilits)

link_directories(./numbers ./tools ./utilits)

add_executable(printf ft_printf.c ft_printf.h parse.c main.c
		utilits/ft_putchar.c
		utilits/ft_strchr.c
		utilits/ft_strnew.c
		utilits/ft_bzero.c
		utilits/ft_strncpy.c
		utilits/ft_strlen.c
		utilits/ft_strndup.c
		utilits/ft_atoi.c
		utilits/ft_longlong_len.c
		utilits/ft_memset.c
		utilits/ft_strcmp.c
		utilits/ft_str_multi_chr.c
		utilits/ft_putnstr.c
		utilits/ft_putstr.c
		utilits/ft_u_longlong_len.c
		utilits/ft_put_u_longlong_base.c
		utilits/ft_putnchar.c
		utilits/ft_u_len_base.c
		utilits/ft_hex_len.c
		utilits/ft_print_u_hex.c
		utilits/ft_ptr_len_base.c

		numbers/print_di.c
		numbers/print_number.c
		numbers/print_u.c
		numbers/print_o.c
		numbers/print_x.c
		numbers/print_f.c

		char/print_cs.c
		char/print_ptr.c

		tools/width.c
		tools/print_flag.c
		tools/print_padding.c
		tools/length.c
		tools/precision.c
		tools/flag.c

		utilits/ft_u_len_base.c
		utilits/ft_ptr_len_base.c
		tools/flag_manager_f.c
		tools/round_ld.c
		numbers/float_to_string.c
		utilits/ft_memalloc.c
		utilits/ft_len_base.c
		utilits/ft_put_longlong_base.c
		utilits/ft_itoa.c)