/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 06:00:39 by hlesny            #+#    #+#             */
/*   Updated: 2022/11/26 19:51:29 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_prefix(t_input *input)
{
	if ((ft_strchr("xX", input->options[type]) && input->options[hashtag])
		|| input->options[type] == 'p')
		input->len[prefix] = 2;
	else if (ft_strchr("di", input->options[type]) && (input->options[negatif]
			|| input->options[plus] || input->options[space]))
		input->len[prefix] = 1;
	else
		input->len[prefix] = 0;
}

void	set_full_nbr(t_input *input, unsigned long long n, int base_size)
{
	input->len[full_num] = max(input->options[precision], n_digits_bonus(n,
				base_size));
}

void	set_margin(t_input *input, int digits_or_slen)
{
	if (input->options[point] == 1 && input->options[type] == 's')
		input->len[margin] = input->options[width]
			- min(input->options[precision], digits_or_slen)
			- input->len[prefix];
	else
		input->len[margin] = input->options[width]
			- max(input->options[precision], digits_or_slen)
			- input->len[prefix];
	input->len[margin] *= (input->len[margin] > 0);
}
