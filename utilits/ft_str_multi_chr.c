//
// Created by Int Pro on 26.12.2019.
//

#include "../ft_printf.h"

char	*ft_str_multi_chr(char *str, char *c)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (c[j])
		{
			if (str[i] == c[j])
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
