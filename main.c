/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:20:09 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/03 21:00:43 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_printf.h"

int main (int argc, char *argv[])
{
	char *s_hidden = "hi low\n\0don't print me lol\0";


	ft_printf("%-.00s\n", s_hidden);
	printf("%-.00s", s_hidden);

	ft_printf("%1.15f\n", 1543.342423);
	printf("%1.15f\n", 1543.342423);

}

