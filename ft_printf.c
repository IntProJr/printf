/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:16:34 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/03 18:33:06 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	parsing_format(va_list *arg, char *format)
{
	size_t	printed_char;

	printed_char = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			printed_char += parsing_percent(arg, &format);
		else
		{
			ft_putchar(*format);
			printed_char++;
		}
		if (*format != '\0')
			format++;
	}
	return (printed_char);
}

int 	ft_printf(const char *format, ...)
{
	/*
	 * arg переменная для извлечения дополнительных параметров функции
	 * с переменным числом параметров
	 */
	va_list arg;
	size_t printed_char;
	/*
	 * Макрос инициализирует arg для извлечения дополнительных аргументов,
	 * которые идут после строки *format.
	 */
	va_start(arg, format);
	printed_char = parsing_format(&arg, (char *) format);
	va_end(arg);

	return (printed_char);
}
