/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_and_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 06:27:27 by hlesny            #+#    #+#             */
/*   Updated: 2022/11/26 20:54:51 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format(unsigned long long n, t_input *input, int *i)
{
	int	base_size;

	if (input->options[point] || input->options[minus])
		input->options[zero] = 0;
	if (ft_strchr("xXp", input->options[type]))
		base_size = 16;
	else
		base_size = 10;
	set_prefix(input);
	if (ft_strchr("xX", input->options[type]) && n == 0)
		input->len[prefix] = 0;
	set_full_nbr(input, n, base_size);
	if (n == 0 && ft_strchr("iduxX", input->options[type])
		&& input->options[point] && !input->options[precision])
		set_margin(input, 0);
	else
		set_margin(input, n_digits_bonus(n, base_size));
	if (input->options[minus])
		case_minus(input, n, base_size, i);
	else if (input->options[zero])
		case_zero(input, n, base_size, i);
	else
		case_other(input, n, base_size, i);
}

void	format_s(char *s, t_input *input, int *i)
{
	int	c;

	c = 0;
	set_prefix(input);
	set_margin(input, ft_strlen(s));
	if (n_digits_bis(input->options[precision], 10) == 0
		&& input->options[point] == 0)
		input->options[precision] = (int)ft_strlen(s);
	if (input->options[minus])
	{
		while (s[c] && (input->options[precision])--)
			(*i) += write(1, &s[c++], 1);
		while (input->len[margin]-- > 0)
			(*i) += write(1, " ", 1);
	}
	else
	{
		while (input->len[margin]-- > 0)
			*i += write(1, " ", 1);
		while (s[c] && (input->options[precision])--)
			*i += write(1, &s[c++], 1);
	}
}

void	format_c(char c, t_input *input, int *i)
{
	set_margin(input, 1);
	if (input->options[minus])
	{
		write(1, &c, 1);
		(*i) += 1;
		while (input->len[margin]-- > 0)
		{
			write(1, " ", 1);
			(*i) += 1;
		}
	}
	else
	{
		while (input->len[margin]-- > 0)
		{
			write(1, " ", 1);
			(*i) += 1;
		}
		write(1, &c, 1);
		(*i) += 1;
	}
}
