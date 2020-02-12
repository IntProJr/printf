/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_to_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:43:25 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/12 18:53:42 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char 	*integer_f(long double nb)
{
	char		*s;
	char		*ptr;
	int 		len;
	int 		i;
	long double temp;

	len = len_f(nb);
	if (!(s = (char *)ft_memalloc(len + 1)))
		exit (1);
	ptr = s;
	while (len > 0)
	{
		i = len - 1;
		temp = nb;
		while (i-- > 0)
			temp /= 10;
		*ptr++ = (int)temp + '0';
		temp = (int)temp;
		while (++i < len - 1)
			temp *= 10;
		nb -= temp;
		--len;
	}
	return (s);
}
