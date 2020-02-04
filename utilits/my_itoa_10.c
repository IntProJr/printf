
#include "../ft_printf.h"

unsigned long int	ft_abs(long n)
{
	unsigned long int	t1;

	if (n < 0)
	{
		t1 = -n;
	}
	else
	{
		t1 = n;
	}
	return (t1);
}

unsigned int	ft_gt_dpth(long n, int sign)
{
	unsigned int	i1;
	unsigned long int	t1;

	if (sign < 0)
		i1 = 2;
	else
		i1 = 1;
	t1 = ft_abs(n);
	while (t1 > 9)
	{
		t1 = t1 / 10;
		i1++;
	}
	return (i1);
}

char				*ft_itoa(long n,char*fresh, int i1, int sign)
{
	unsigned long int	t1;

	if (n == 0 && sign == -1)
	{
		fresh[0] = '-';
		fresh[1] = '0';
		return (fresh);
	}
	t1 = ft_abs(n);
	// fresh[i1] = '\0';
	while (t1 > 9)
	{
		fresh[--i1] = t1 % 10 + '0';
		t1 = t1 / 10;
	}
	fresh[--i1] = t1 + '0';
	if (n < 0)
		fresh[--i1] = '-';
	return (fresh);
}
