#include <stdio.h>
#include "ft_printf.h"

int main (int argc, char *argv[])
{
	char c;

	c = 'a';

	//printf("%d\n", 5);
	ft_printf("digits : %d\n", 4);
	ft_printf("character : %c\n %s\n", c, "ferr");
	ft_printf("%x", 1232);
}

