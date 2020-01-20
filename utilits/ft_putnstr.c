/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:55:47 by lrosalee          #+#    #+#             */
/*   Updated: 2020/01/20 17:55:47 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnstr(const char *str, size_t n)
{
	size_t	len;

	if (str != NULL)
	{
		len = ft_strlen(str);
		if (len < n)
			write(1, str, len);
		else
			write(1, str, n);
	}
}
