/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:18:55 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/07 15:18:37 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	*ft_memset(void *destination, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		((char *)destination)[i] = (unsigned char)c;
		i++;
	}
	return (destination);
}
