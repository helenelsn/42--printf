/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:36:21 by hlesny            #+#    #+#             */
/*   Updated: 2022/11/26 21:08:08 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	zero_prec(int *i, int *j, const char *format, t_input *input)
{
	while (format[++(*i)] == '0' && (format[(*i) + 1] == '0'
			|| !ft_isdigit(format[(*i) + 1])))
	{
		if (ft_strchr(CONV, format[++(*i)]))
		{
			input->options[type] = format[(*i)++];
			*j += (*i);
			return (1);
		}
	}
	return (0);
}

int	set_input(const char *format, t_input *input, int *j)
{
	int	i;

	i = 0;
	set_format(format, input, &i);
	if (input->options[modulo] == 0)
	{
		get_width(format, input, &i);
		if (format[i] && format[i] == '.')
		{
			input->options[point] = 1;
			if (zero_prec(&i, j, format, input))
				return (1);
			getprec(format, input, &i);
		}
		get_modulo_format(format, input, &i);
	}
	*j += i;
	return (1);
}

void	reset_struct(t_input *input)
{
	int	i;

	i = -1;
	while (++i < 11)
		input->options[i] = 0;
	i = -1;
	while (++i < 3)
		input->len[i] = 0;
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		i;
	int		c;
	t_input	input;

	if (!format)
		return (0);
	reset_struct(&input);
	i = 0;
	c = 0;
	va_start(ptr, format);
	while ((size_t)i < ft_strlen(format))
	{
		while (format[i] && format[i] != '%')
			c += write(1, &format[i++], 1);
		if (format[i] == '%')
		{
			set_input(&format[++i], &input, &i);
			c += convert_and_print(ptr, &input);
		}
		reset_struct(&input);
	}
	va_end(ptr);
	return (c);
}
