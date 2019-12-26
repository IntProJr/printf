//
// Created by Int Pro on 26.12.2019.
//

#include "../ft_printf.h"

int 	print_simple_char(int char_printed, t_printf p)
{
	char_printed += 1;
	char_printed += print_width(p, char_printed);
	char_printed += print_zero_padding(p, char_printed);
	ft_putchar(p.conversion);
	char_printed += print_width_minus(p, char_printed);
	return (char_printed);
}