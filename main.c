/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <lrosalee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:20:09 by lrosalee          #+#    #+#             */
/*   Updated: 2020/02/01 19:28:23 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_printf.h"

int main (int argc, char *argv[])
{
	char *s_hidden = "hi low\n\0don't print me lol\0";


	ft_printf("%s%s", "hello", "world");
	printf("%s%s", "hello", "world");
}

