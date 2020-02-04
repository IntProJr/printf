/* Example for printf() */
#include "../ft_printf.h"

double average(int count, ...)
{
    va_list ap;
    int j;
    double sum = 0;

    va_start(ap, count); /* Requires the last fixed parameter (to get the address) */
    for (j = 0; j < count; j++) {
        sum += va_arg(ap, int); /* Increments ap to the next argument. */
    }
    va_end(ap);

    return sum / count;
}

void foo(char *fmt, ...)
{
    va_list ap;
    int d;
    char c, *s;
    va_start(ap, fmt);
    while (*fmt)
        switch (*fmt++) {
        case 's':              /* string */
            s = va_arg(ap, char *);
            printf("string %s\n", s);
            break;
        case 'd':              /* int */
            d = va_arg(ap, int);
            printf("int %d\n", d);
            break;
        case 'c':              /* char */
            /* need a cast here since va_arg only
               takes fully promoted types */
            c = (char) va_arg(ap, int);
            printf("char %c\n", c);
            break;
        }
    va_end(ap);
}

int main(){

//    printf ("Integers: %i %u \n", -3456, 3456);
//    printf ("Characters: %c %c \n", 'z', 80);
//    printf ("Decimals: %d %ld\n", 1997, 32000L);
//    printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
//    printf ("floats: %4.2f %+.0e %E \n", 3.14159, 3.14159, 3.14159);
//    printf ("Preceding with empty spaces: %10d \n", 1997);
//    printf ("Preceding with zeros: %010d \n", 1997);
//    printf ("Width: %*d \n", 15, 140);
//    printf ("Simple string (my example): %s \n", "Educative");
 
//    ft_printf ("Integers: %i %u \n", -3456, 3456);
//    ft_printf ("Characters: %c %c \n", 'z', 80);
//    ft_printf ("Decimals: %d %ld\n", 1997, 32000L);
//    ft_printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
//    ft_printf ("floats: %4.2f %+.0e %E \n", 3.14159, 3.14159, 3.14159);
//    ft_printf ("Preceding with empty spaces: %10d \n", 1997);
//    ft_printf ("Preceding with zeros: %010d \n", 1997);
//    ft_printf ("Width: %*d \n", 15, 140);
//    ft_printf ("%s \n", "Educative");

//    CAN I USE A MIXED ORDER? FOR EXAMPLE, printf("%i",20,"%s"," and some string")printf("%i",20,"%s"," and some string")
//		this will cause "warning: data argument not used by format string"

//    char *s = "Здравствуй, если не шутишь!";
//    int i1=printf (":%s:\n",s);
//    printf (":%27s:\n",s);
//    printf (":%-27s:\n",s);
//    printf (":%32s:\n",s);
//    printf (":%-32s:\n",s);
//    printf (":%032s:\n",s);
//    printf (":%32.16s:\n",s);
//    printf (":%-32.16s:\n",s);
//    printf (":%.16s:\n",s);
    
//    printf ("\"Всем лечь!\"- быстро произнес он.\n");
//    printf("this is return meaning: %i",i1);
// ft_printf ("\"Всем лечь!\"- быстро произнес он.\n");


	// printf("First:|%c|. Second:|%s|",114," it should be r sign");

	
	// ft_printf ("%d%c%f",1,'c',1.234);
    
//    printf("%f\n", average(3, 1, 2, 3) );

   //simple_printf("dcff", 3, 'a', 1.999, 42.5); 

//    ft_printf ("float as a string: %f\n", 3.14159);

	double			var;
	t_str_and_size	var_t_str_and_size;

	var = -6.000000;

	printf("%.6f\n", var);
	var_t_str_and_size = ft_flt_to_str(var, 6);
	printf("%s\n",var_t_str_and_size.str);
	return 0;
}