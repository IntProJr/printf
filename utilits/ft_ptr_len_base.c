
#include "../ft_printf.h"

size_t	ft_ptr_len_base(size_t ptr, unsigned int base)
{
	size_t	len;

	len = 1;
	while (ptr >= base)
	{
		ptr /= base;
		len++;
	}
	return (len);
}