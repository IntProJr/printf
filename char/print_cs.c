/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 18:42:48 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/03 18:28:49 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	printing_string_null(int char_printed, t_printf p)
{
	int prec;

	prec = p.precision;
	char_printed += 6;
	char_printed += printing_width(p, char_printed);
	char_printed += printing_padding_of_zero(p, char_printed);
	if (prec > 0)
		ft_putnstr("(null)", prec);
	else if (prec != -1)
		ft_putstr("(null)");
	return (char_printed);
}

static int	printing_string(int char_printed, t_printf p, char *str)
{
	const int	prec = p.precision;

	if (str || prec != 0)
	{
		if (!str)
			if ((str = (char*)malloc(sizeof(char) * 7)))
				str = "(null)";
		if (prec == 0 && ft_strlen(str) > 0)
			char_printed += (int)ft_strlen(str);
		else if (str && prec > 0 && prec < (int)ft_strlen(str))
			char_printed += prec;
		else if (str && prec > 0)
			char_printed += (int)ft_strlen(str);
		char_printed += printing_width(p, char_printed);
		char_printed += printing_padding_of_zero(p, char_printed);
		if (prec > 0)
			ft_putnstr(str, prec);
		else if (prec != -1)
			ft_putstr(str);
	}
	else
		char_printed += printing_string_null(char_printed, p);
	char_printed += print_width_minus(p, char_printed);
	return (char_printed);
}

int			printing_only_char(int char_printed, t_printf p)
{
	char_printed += 1;
	char_printed += printing_width(p, char_printed);
	char_printed += printing_padding_of_zero(p, char_printed);
	ft_putchar(p.conversion_percent);
	char_printed += print_width_minus(p, char_printed);
	return (char_printed);
}

static int	printing_char(int char_printed, t_printf p, char c)
{
	char_printed += 1;
	char_printed += printing_width(p, char_printed);
	char_printed += printing_padding_of_zero(p, char_printed);
	ft_putchar(c);
	char_printed += print_width_minus(p, char_printed);
	return (char_printed);
}

int			printing_string_char(va_list *arg, t_printf p)
{
	int		char_printed;
	char	c;
	char	*str;

	char_printed = 0;
	if (p.conversion_percent == 'c')
	{
		c = (char)va_arg(*arg, int);
		char_printed += printing_char(char_printed, p, c);
	}
	else if (p.conversion_percent == 's')
	{
		str = (char *)va_arg(*arg, char *);
		char_printed += printing_string(char_printed, p, str);
	}
	return (char_printed);
}
