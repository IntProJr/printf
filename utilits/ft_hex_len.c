
#include "../ft_printf.h"

int ft_hex_len(unsigned long long nb)
{
	int char_printed;

	if (nb < 16)
		char_printed = 1;
	else
		char_printed = ft_u_len_base(nb, 16);
	return (char_printed);
}