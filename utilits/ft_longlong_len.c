//
// Created by Int Pro on 09.12.2019.
//

#include "../ft_printf.h"

size_t		ft_longlong_len(long long nbr)
{
	size_t	len;

	len = 1;
	if (nbr < 0)
		len += 1;
	while (nbr > 9 || nbr < - 9)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}
