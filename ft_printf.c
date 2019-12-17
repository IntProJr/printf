/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:16:34 by lrosalee          #+#    #+#             */
/*   Updated: 2019/11/25 16:16:38 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	parse_format(va_list *arg, char *format)
{
	size_t	char_printed;

	char_printed = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			char_printed += parse_percentage(arg, &format);
		else
		{
			ft_putchar(*format);
			char_printed++;
		}
		if (*format != '\0')
			format++;
	}
	return (char_printed);
}

int 	ft_printf(const char *format, ...)
{
	/*
	 * arg переменная для извлечения дополнительных параметров функции
	 * с переменным числом параметров
	 */
	va_list arg;
	size_t char_printed;
	/*
	 * Макрос инициализирует arg для извлечения дополнительных аргументов,
	 * которые идут после строки *format.
	 */
	va_start(arg, format);
	char_printed = parse_format(&arg, (char*)format);
	va_end(arg);

	return (char_printed);
}
