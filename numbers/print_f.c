/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:09:17 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/12 18:25:06 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

long double	ft_va_arg(va_list *arg, t_printf p)
{
	long double	nb;

	if (p.bl)
		nb = (long double)va_arg(*arg, long double);
	else
		nb = (long double)va_arg(*arg, double);
	return (nb);
}

int		printf_f(va_list *arg, int char_printed, t_printf p)
{
	char 		*integer;
	char		*decimal;
	long double	nb;

	nb = ft_va_arg(arg, p);
	p = flag_manager_f(nb, p);
	if (!p.inf && !p.nan)
	{
		nb = round_ld(nb, p);
	}


}

