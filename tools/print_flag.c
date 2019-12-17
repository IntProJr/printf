//
// Created by Int Pro on 09.12.2019.
//

#include "../ft_printf.h"

int		print_space(t_printf p, long long nb)
{
	if (p.space && ft_strchr("diD", p.conversion))
	{
		if (nb >= 0)
		{
			ft_putchar(' ');
			return (1);
		}
	}
	return (0);
}

int print_plus(t_printf p, long long nb)
{
	if (p.plus && nb >= 0 && !ft_strchr("uU", p.conversion))
	{
		ft_putchar('+');
		return (1);
	}
	return (0);
}
