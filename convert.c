/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 05:05:08 by hlesny            #+#    #+#             */
/*   Updated: 2022/11/26 19:27:19 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	case_s(va_list ptr, t_input *input, int *i)
{
	char	*s;

	s = (char *)va_arg(ptr, char *);
	if (n_digits_bis(input->options[precision], 10) == 0
		&& input->options[point] == 1)
	{
		format_s("", input, i);
	}
	else if (!s)
	{
		if (input->options[precision] < 6 && input->options[point])
		{
			format_s("", input, i);
		}
		else
			format_s("(null)", input, i);
	}
	else
		format_s(s, input, i);
}

void	case_id(va_list ptr, t_input *input, int *i)
{
	long long int	n;

	n = va_arg(ptr, int);
	if (n < 0)
	{
		input->options[negatif] = 1;
		n = -n;
	}
	format(n, input, i);
}

void	case_p(va_list ptr, t_input *input, int *i)
{
	unsigned long long	n;

	n = (unsigned long long)va_arg(ptr, void *);
	if (n)
		format(n, input, i);
	else
	{
		input->options[type] = 's';
		format_s("(nil)", input, i);
	}
}

void	convert(va_list ptr, t_input *input, int *i)
{
	if (ft_strchr("id", input->options[type]))
		case_id(ptr, input, i);
	else if (ft_strchr("xX", input->options[type]))
		format(va_arg(ptr, unsigned int), input, i);
	else if (input->options[type] == 'p')
		case_p(ptr, input, i);
	else if (input->options[type] == 'u')
		format(va_arg(ptr, unsigned int), input, i);
	else if (input->options[type] == 's')
		case_s(ptr, input, i);
	else if (input->options[type] == 'c')
		format_c((char)(va_arg(ptr, int)), input, i);
}

int	convert_and_print(va_list ptr, t_input *input)
{
	int	i;

	i = 0;
	if (input->options[modulo] || !input->options[type])
		return (write(1, "%", 1));
	else
	{
		convert(ptr, input, &i);
		return (i);
	}
}
