/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:16:00 by lrosalee          #+#    #+#             */
/*   Updated: 2019/11/25 16:16:04 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*dst;

	dst = ft_strnew(n);
	if (dst)
	{
		dst = ft_strncpy(dst, src, n);
		return (dst);
	}
	else
		return (NULL);
}