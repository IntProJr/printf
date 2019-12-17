/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:40:25 by lrosalee          #+#    #+#             */
/*   Updated: 2019/11/25 16:40:27 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int 	print_d(va_list *arg, int char_printed, t_printf p)
{
	long long	nb;
	char		c;

	c = p.conversion;
	if (c == 'd' || c == 'i' || c =='D')
	{
		if (p.l == 1 || c == 'D')
			nb = (long long)va_arg(*arg, long);

		else if (p.l == 2)
			nb == va_arg(*arg, long long);
		else if (p.j == 1)
			nb = (long long)va_arg(*arg, intmax_t);
		else if (p.z == 1)
			nb = (long long)va_arg(*arg, size_t);
		char_printed += print_d_longlong(char_printed, p, nb);
	}
	return (char_printed);
}



int 	print_num(va_list *arg, t_printf p)
{
	int 	char_printed;
	char	c;

	char_printed = 0;
	c = p.conversion;
	if (c == 'd' || c == 'i' || c == 'D')
		char_printed += print_d(arg, char_printed, p);
	return (0);
}
