/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:16:13 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/07 15:18:37 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	char	*p;

	if (size + 1 == 0)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	p = str;
	while (size)
	{
		*p++ = '\0';
		size--;
	}
	*p = '\0';
	return (str);
}
