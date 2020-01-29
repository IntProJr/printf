/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_len_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 19:39:26 by lrosalee          #+#    #+#             */
/*   Updated: 2020/01/29 19:39:26 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_u_len_base(unsigned long long int nb, char base)
{
	size_t	len;

	len = 1;
	while (nb > (unsigned long long)base)
	{
		nb /= base;
		len++;
	}
	return (len);
}