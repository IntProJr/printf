//
// Created by Int Pro on 26.12.2019.
//
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

