/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:16:42 by lrosalee          #+#    #+#             */
/*   Updated: 2019/11/25 16:16:47 by lrosalee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_FT_PRINTF_H
#define PRINTF_FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>

typedef struct	s_printf
{
	char		conversion;	// преобразование
	int			precision; // точность
	int			min_width;
	int 		zero;
	int			plus;
	int			minus;
	int			hash;	// ???????????????
	int			space;
	int			l;		//long int, unsigned long int
	int			bl;		//long long int, unsigned long long int
	int 		j;		// intmax, unsigned intmax
	int			z;		// size_t return from size_of in bytes
	int 		h;		// short int, ushort int
	int			inf;	// ???????????????
	int			nan;	// ???????????????
}				t_printf;

int 			ft_printf(const char *format, ...);
int 			parse_percentage(va_list *arg, char **format);
static char 	*designation_p(char *format, t_printf *p);
static t_printf	filling_p(char *format, int i);


int				width(char *str);
static int		dispatch_conversion(va_list *arg, char **str, t_printf p);
int 			print_num(va_list *arg, t_printf p);
int 			length(char *str, char c);
int 			print_num(va_list *arg, t_printf p);
static int 		print_d(va_list *arg, int char_printed, t_printf p);
int				print_d_longlong(int char_printed, t_printf p, long long nb);


size_t			ft_longlong_len(long long nbr);
int				print_space(t_printf p, long long nb);
int				print_plus(t_printf p, long long nb);
int				print_width(t_printf p, int written);
int				print_zero_padding(t_printf p, int char_printed);
int				print_precision(t_printf p, long long nb, int nb_len);
int				print_width_minus(t_printf p, int char_printed);

/*
 * tools
 */

int				precision(char *str);
int				zero_flag(char *str, int minus);

/*
 * utilits
 */

void			ft_putchar(char c);
char			*ft_strchr(const char *s, int c);
char 			*ft_strnew(size_t size);
void			ft_bzero(void *s, size_t size);
char 			*ft_strncpy(char *dst, const char *src, size_t len);
size_t			ft_strlen(char *str);
char			*ft_strndup(const char *src, size_t n);
int 			ft_atoi(const char *str);
void			*ft_memset(void *destination, int c, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_str_multi_chr(char *str, char *c);
#endif //PRINTF_FT_PRINTF_H
