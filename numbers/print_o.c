/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 19:21:34 by lrosalee          #+#    #+#             */
/*   Updated: 2020/01/29 19:23:05 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int 	print_u_o_long(int char_printed, t_printf p, unsigned long long nb)
{
	int prec;
	int nb_len;

	prec = 0;
	nb_len = ft_u_len_base(nb, 8);

}

static int 	print_o_unsigned(va_list *arg, int char_printed, t_printf p)
{
	unsigned long long	u_nb;

	u_nb = 0;
	if (p.l == 1 || p.conversion == 'o')
		u_nb = (unsigned long long)va_arg(*arg, unsigned long);
	else if (p.l == 2)
		u_nb = va_arg(*arg, unsigned long long);
	else if (p.h == 1)
		u_nb = (unsigned short)va_arg(*arg, unsigned int);
	else if (p.h == 2)
		u_nb = (unsigned char)va_arg(*arg, unsigned int);
	else if (p.j == 1)
		u_nb = (unsigned long long)va_arg(*arg, uintmax_t);
	else if (p.z == 1)
		u_nb = (unsigned long long)va_arg(*arg, size_t);
	char_printed += print_u_o_long(char_printed, p, u_nb);
	return (char_printed);
}