/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:16:55 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/03 16:45:13 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_printf	filling_p(char *format, int i)
{
	t_printf	p;
	char 		*str;

	str = ft_strnew(i);
	str = ft_strncpy(str, format, i);
	p.width_option = width(str);
	p.precision = precision(str);
	p.znak_plus = plus_flag(str);
	p.znak_minus = minus_flag(str);
	p.zero = zero_flag(str, p.znak_minus);
	p.hash = hash_flag(str);
	p.space = space_flag(str, p.znak_plus);
	p.bl = length(str, 'L');
	p.l = length(str, 'l');
	p.h = length(str, 'h');
	p.j = length(str, 'j');
	p.z = length(str, 'z');
	p.inf = 0;
	p.nan = 0;
	free(str);
	return (p);
}

static char 	*designation_p(char *format, t_printf *p)
{
	int	i;

	i = 0;
	/*
	 * определяем модификаторы функции
	 */
	while (ft_strchr("#0 -+hlLjz.123456789", format[i]) && format[i])
		i++;
	*p = filling_p(format, i);
	return (&format[i]);
}

static int 	dispatch_conversion(va_list *arg, char **str, t_printf p)
{
	int	i;
	int char_printed;
	/*
	 * спецификаторы преобразований
	 */
	i = 0;
	char_printed = 0;
	p.conversion_percent = (*str)[i];
	if(ft_strchr("fFxXuUoOidD", p.conversion_percent))
		char_printed = print_num(arg, p);
	else if (ft_strchr("sc", p.conversion_percent))
		char_printed = print_sc(arg, p);
	else if (p.conversion_percent == 'p')
		char_printed = print_ptr(char_printed, arg, p);
	else
		char_printed = print_simple_char(char_printed, p);
	*str = &(*str)[i];
	return (char_printed);
}

int 	parse_percentage(va_list *arg, char **format)
{
	int			i;
	t_printf	p;

	i = 0;
	if((*format)[i] == '%')
	{
		i++;
		if ((*format)[i] != '\0')
		{
			*format = designation_p(&(*format)[i], &p);
			return (dispatch_conversion(arg, &(*format), p));
		}
	}
	return (0);
}
