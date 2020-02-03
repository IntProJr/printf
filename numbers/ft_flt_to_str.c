/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flt_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: u18188899 <u18188899@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 10:45:10 by u18188899         #+#    #+#             */
/*   Updated: 2020/02/03 19:35:36 by u18188899        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 23. You have to manage the following conversion: f with the following flags: l and L.
// 23.1. https://github.com/Danilo3/printf/issues/2
// 23.2.from https://man.openbsd.org/printf.3#fF
// 23.3.The double argument is rounded and converted to decimal notation in 
// the style [-]ddd.ddd, where the number of digits after the 
// decimal-point character is equal to the precision specification. 
// If the precision is missing, it is taken as 6; if the precision 
// is explicitly zero, no decimal-point character appears. 
// If a decimal point appears, at least one digit appears before it.
// // 23.4.If the argument is infinity, it will be converted to 
// [-]inf (f) or [-]INF (F), respectively. 
// If the argument is not-a-number (NaN), it will be converted to 
// [-]nan (f) or [-]NAN (F), respectively.

#include "../ft_printf.h"

t_str_and_size		ft_flt_to_str(double flt, int prcsn)
{
	t_str_and_size		rslt;
	int					i1;
	double				rmndr;
	double				rnd;
	

	i1 = 0;
	rnd = 1.0;
	
	rmndr = ft_gt_rmndr(flt);
	rslt.sz = ft_gt_dpth((long)flt);
	if (!(rslt.str = (char*)malloc(sizeof(char) * (rslt.sz + prcsn + 2))))
		return (rslt);
	ft_bzero(rslt.str,(size_t)(rslt.sz + prcsn + 2));

	// flt = 1000.12345678

	while (rmndr != 0 && i1 < prcsn)
	{
		rmndr = rmndr * 10 - (int)(rmndr * 10);
		i1++;
	}
	if (rmndr > 0.5)

	// that is a case when i need to handle rounding

	{
		i1 = 0;
		while (i1 < prcsn)
		{
			rnd /= 10;
			i1++;
		}

		// flt = (double)((int)flt) + ((double)((int)(rmndr * mltplr))) / mltplr + rnd;

		flt += rnd;
	}
	// else if (rmndr <= 0.5):
		// flt has less, equal digits after point, than precision needed or remainder after precision
		// is not important (after rounding it won't change last digit)
	rslt.sz = ft_gt_dpth((long)flt);
	ft_itoa((long)flt,rslt.str, rslt.sz);
	i1 = 1;
	rmndr = ft_gt_rmndr(flt);
	while (i1 <= prcsn)
	{
		rslt.str[rslt.sz + i1] = (int)(rmndr * 10) + '0';
		rmndr = rmndr * 10 - (int)(rmndr * 10);
		i1++;
		rslt.str[rslt.sz] = '.';		
	}
	if (prcsn != 0)
		rslt.sz = rslt.sz + prcsn + 1;
	return rslt;
}

double		ft_gt_rmndr(double flt)
{
	double rmndr;
	
	rmndr = (flt - (long)flt);
	if (rmndr < 0)
		return (-rmndr);
	return rmndr;
}

int		ft_sign(long long t)
{
	if (t < 0)
		return -1;
	return 1;
}