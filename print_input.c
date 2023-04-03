/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 06:55:23 by hlesny            #+#    #+#             */
/*   Updated: 2022/11/26 19:57:23 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_prefix(t_input *input, int *i)
{
	if ((input->options[type] == 'x' && input->options[hashtag]
			&& input->len[prefix] == 2) || input->options[type] == 'p')
		*i += write(1, "0x", 2);
	else if (input->options[type] == 'X' && input->options[hashtag]
		&& input->len[prefix] == 2)
		*i += write(1, "0X", 2);
	else if (ft_strchr("di", input->options[type]))
	{
		if (input->options[negatif])
			*i += write(1, "-", 1);
		else if (input->options[plus])
			*i += write(1, "+", 1);
		else if (input->options[space])
			*i += write(1, " ", 1);
	}
}

void	ft_putnbr_base(unsigned long long nbr, char *base, int *ccount,
		int base_size)
{
	if (nbr >= (unsigned long long)base_size)
	{
		ft_putnbr_base(nbr / base_size, base, ccount, base_size);
		*ccount += write(1, &base[nbr % base_size], 1);
		nbr /= base_size;
	}
	else
		*ccount += write(1, &base[nbr % base_size], 1);
}

void	case_minus(t_input *input, unsigned long long n, int base_size, int *i)
{
	int	j;

	j = -1;
	print_prefix(input, i);
	while (++j < (input->len[full_num] - n_digits_bonus(n, base_size)))
		*i += write(1, "0", 1);
	if (n == 0 && ft_strchr("iduxX", input->options[type])
		&& input->options[point] && !input->options[precision])
		;
	else if (base_size == 10)
		ft_putnbr_base(n, DEC, i, base_size);
	else if (input->options[type] == 'X')
		ft_putnbr_base(n, BHEXA, i, base_size);
	else
		ft_putnbr_base(n, SHEXA, i, base_size);
	while (input->len[margin]-- > 0)
		*i += write(1, " ", 1);
}

void	case_zero(t_input *input, unsigned long long n, int base_size, int *i)
{
	int	j;

	j = -1;
	print_prefix(input, i);
	while (input->len[margin]-- > 0)
		*i += write(1, "0", 1);
	while (++j < (input->len[full_num] - n_digits_bonus(n, base_size)))
		*i += write(1, "0", 1);
	if (n == 0 && ft_strchr("iduxX", input->options[type])
		&& input->options[point] && !input->options[precision])
		;
	else if (base_size == 10)
		ft_putnbr_base(n, DEC, i, base_size);
	else if (input->options[type] == 'X')
		ft_putnbr_base(n, BHEXA, i, base_size);
	else
		ft_putnbr_base(n, SHEXA, i, base_size);
}

void	case_other(t_input *input, unsigned long long n, int base_size, int *i)
{
	int	j;

	j = -1;
	while (input->len[margin]-- > 0)
		*i += write(1, " ", 1);
	print_prefix(input, i);
	while (++j < (input->len[full_num] - n_digits_bonus(n, base_size)))
		*i += write(1, "0", 1);
	if (n == 0 && ft_strchr("iduxX", input->options[type])
		&& input->options[point] && !input->options[precision])
		;
	else if (input->options[type] == 'X')
		ft_putnbr_base(n, BHEXA, i, base_size);
	else if (input->options[type] == 'x' || input->options[type] == 'p')
		ft_putnbr_base(n, SHEXA, i, base_size);
	else
		ft_putnbr_base(n, DEC, i, base_size);
}
