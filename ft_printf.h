/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrosalee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:16:42 by lrosalee          #+#    #+#             */
/*   Updated: 2020/01/31 18:43:59 by lrosalee         ###   ########.fr       */
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
	char		conversion;	// спецификатор преобразование
	int			precision; // точность
	int			min_width;
	int 		zero;
	int			plus;
	int			minus;
	int			hash;	// #
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


int				width(char *str);
int 			print_num(va_list *arg, t_printf p);
int 			length(char *str, char c);
int 			print_num(va_list *arg, t_printf p);
int				print_d_longlong(int char_printed, t_printf p, long long nb);


size_t			ft_longlong_len(long long nbr);
int				print_space(t_printf p, long long nb);
int				print_plus(t_printf p, long long nb);
int				print_width(t_printf p, int written);
int				print_zero_padding(t_printf p, int char_printed);
int				print_precision(t_printf p, long long nb, int nb_len);
int				print_width_minus(t_printf p, int char_printed);


/*
 * numbers
 */

int				print_o_unsigned(va_list *arg, int char_printed, t_printf p);
//static int		print_u_o_long(int char_printed, t_printf p, unsigned long long nb);
int				print_o_longlong(int char_printed, t_printf p, long long nb);
//static int		print_x(va_list *arg, int char_printed, t_printf p);
int				print_x_l(int char_printed, t_printf p, unsigned long long nb);


/*
 * tools
 */

int				precision(char *str);
int				zero_flag(char *str, int minus);
int				plus_flag(char *str);
int				minus_flag(char *str);
int				hash_flag(char *str);
int				space_flag(char *str, int plus);
int				print_hash(t_printf p, long long nb);
int				hash_length(t_printf p, long long nb);

/*
 * char
 */
int				print_simple_char(int char_printed, t_printf p);
int				print_sc(va_list *arg, t_printf p);
int				print_ptr(int char_printed, va_list *arg ,t_printf p);
//static void		ft_print_ptr(size_t nb);

/*
 * utilits
 */

void			ft_putchar(char c);
char			*ft_strchr(const char *s, int c);
char 			*ft_strnew(size_t size);
void			ft_bzero(void *s, size_t size);
char 			*ft_strncpy(char *dst, const char *src, size_t len);
size_t			ft_strlen(const char *str);
char			*ft_strndup(const char *src, size_t n);
int 			ft_atoi(const char *str);
void			*ft_memset(void *destination, int c, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_str_multi_chr(char *str, char *c);
void			ft_putnstr(const char *str, size_t n);
void			ft_putstr(char const *s);
size_t			ft_u_longlong_len(unsigned long long nb);
int				print_u_l(int char_printed, t_printf p, unsigned long long nb);
void			ft_putnchar(char c, size_t n);
void			ft_put_u_longlong_base(unsigned long long nb, char base);
size_t			ft_u_len_base(unsigned long long int nb, char base);
int				ft_hex_len(unsigned long long nb);
void			ft_print_u_hex(unsigned long long nb, const char *str);
size_t			ft_ptr_len_base(size_t ptr, unsigned int base);

#endif //PRINTF_FT_PRINTF_H
