/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 22:19:21 by hlesny            #+#    #+#             */
/*   Updated: 2022/11/26 21:01:14 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft2/libft.h"
# include <stdarg.h>
# include <stdio.h>

# define SHEXA "0123456789abcdef"
# define BHEXA "0123456789ABCDEF"
# define DEC "0123456789"
# define FLAGS "%-0# +"
# define CONV "cspdiuxX"

enum	e_options
{
	point,
	minus,
	plus,
	zero,
	modulo,
	width,
	precision,
	hashtag,
	space,
	type,
	negatif
};

enum	e_length
{
	prefix,
	full_num,
	margin,
};

typedef struct s_input
{
	int	options[11];
	int	len[3];
}		t_input;

int		ft_printf(const char *format, ...);
void	reset_struct(t_input *input);
int		set_input(const char *format, t_input *input, int *j);
int		zero_prec(int *i, int *j, const char *format, t_input *input);
void	set_format(const char *format, t_input *input, int *j);
int		set_otherflags(const char *format, t_input *input, int *j);
void	get_modulo_format(const char *format, t_input *input, int *j);
void	getprec(const char *format, t_input *input, int *j);
void	get_width(const char *format, t_input *input, int *j);
int		convert_and_print(va_list ptr, t_input *input);
void	convert(va_list ptr, t_input *input, int *i);
void	case_id(va_list ptr, t_input *input, int *i);
void	case_p(va_list ptr, t_input *input, int *i);
void	case_s(va_list ptr, t_input *input, int *i);
void	format(unsigned long long n, t_input *input, int *i);
void	format_s(char *s, t_input *input, int *i);
void	format_c(char c, t_input *input, int *i);
void	set_prefix(t_input *input);
void	set_full_nbr(t_input *input, unsigned long long n, int base_size);
void	set_margin(t_input *input, int digits_or_slen);
void	print_prefix(t_input *input, int *i);
void	case_minus(t_input *input, unsigned long long n, int base_size, int *i);
void	case_zero(t_input *input, unsigned long long n, int base_size, int *i);
void	case_other(t_input *input, unsigned long long n, int base_size, int *i);
void	ft_putnbr_base(unsigned long long nbr, char *base, int *ccount,
			int base_size);
int		max(int a, int b);
int		min(int a, int b);
int		n_digits(unsigned long long n, int base_size);
int		n_digits_bonus(unsigned long long n, int base_size);
int		n_digits_bis(unsigned long long n, int base_size);

#endif
