/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:56:43 by lrosalee          #+#    #+#             */
/*   Updated: 2019/11/25 15:56:54 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int 	ft_atoi(const char *str)
{
	char	sign;
	char	was_sign;
	int		i;
	long	num;

	i = 0;
	while(('\t' <= str[i] && str[i] <= '\r') || str[i] == ' ')
		i++;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	was_sign = sign;
	num = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if (num < 0 && was_sign == 1)
				return (-1);
		else if (num < 0 && was_sign == -1)
			return (0);
		i++;
	}
	return ((int)num * sign);
}
