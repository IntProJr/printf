/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:16:13 by lrosalee          #+#    #+#             */
/*   Updated: 2019/11/25 16:16:18 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
char 	*ft_strnew(size_t size)
{
	char	*s;

	if (size + 1 == 0)
		return (NULL);
	s = (char *)malloc(sizeof(char) * size + 1);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, size + 1);
	return (s);
}
