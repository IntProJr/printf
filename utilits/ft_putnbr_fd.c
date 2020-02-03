/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u18188899 <u18188899@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 09:47:52 by klekisha          #+#    #+#             */
/*   Updated: 2020/02/03 18:32:34 by u18188899        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	n1;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n1 = (unsigned int)(-n);
	}
	else
		n1 = (unsigned int)n;
	if (n1 >= 10)
		ft_putnbr_fd(n1 / 10, fd);
	ft_putchar_fd(n1 % 10 + '0', fd);
}
