/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:40:25 by lrosalee          #+#    #+#             */
/*   Updated: 2020/01/29 19:21:29 by lrosalee         ###   ########.fr       */
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
			nb = va_arg(*arg, long long);
		else if (p.j == 1)
			nb = (long long)va_arg(*arg, intmax_t);
		else if (p.z == 1)
			nb = (long long)va_arg(*arg, size_t);
		else if (p.h == 1)
			nb = (short)va_arg(*arg, int);
		else if (p.h == 2)
			nb = (char)va_arg(*arg, int);
		else
			nb = (long long)va_arg(*arg, int);
		char_printed += print_d_longlong(char_printed, p, nb);
	}
	return (char_printed);
}

static int 	print_o(va_list *arg, int char_printed, t_printf p)
{
	long long	nb;
	if (p.conversion || p.h ||p.z || p.j || p.l == 'O')
		char_printed += print_o_unsigned(arg, char_printed, p);
	else
	{
		nb = (long long)va_arg(*arg, unsigned int);
		char_printed += print_o_longlong(char_printed, p, nb);
	}
	return (char_printed);

}

static int print_u(va_list *arg, int char_printed, t_printf p)
{
	char 				c;
	unsigned long long	nb;
	c = p.conversion;
	if (c == 'u' || c == 'U')
	{
		if (p.l == 1 || c == 'U')
			nb = (unsigned long long)va_arg(*arg, unsigned long);
		else if (p.l == 2)
			nb = va_arg(*arg, unsigned long long);
		else if (p.h == 1)
			nb = (unsigned short)va_arg(*arg, unsigned int);
		else if (p.h == 2)
			nb = (unsigned char)va_arg(*arg, unsigned int);
		else if (p.j == 1)
			nb = (unsigned long long)va_arg(*arg, uintmax_t);
		else if (p.z == 1)
			nb = (unsigned long long)va_arg(*arg, unsigned int);
		char_printed += print_u_l(char_printed, p, nb);
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
	else if (c == 'u' || c == 'U')
		char_printed += print_u(arg, char_printed, p);
	else if (c == 'o' || c == 'O')
		char_printed += print_o(arg, char_printed, p);
	return (0);
}
