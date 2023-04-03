/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:46:56 by hlesny            #+#    #+#             */
/*   Updated: 2022/11/26 20:56:12 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_otherflags(const char *format, t_input *input, int *j)
{
	if (format[*j] == '-')
	{
		input->options[minus] = 1;
		(*j)++;
	}
	else if (format[*j] == '#')
	{
		input->options[hashtag] = 1;
		(*j)++;
	}
	else if (format[*j] == ' ')
	{
		input->options[space] = 1;
		(*j)++;
	}
	else if (format[*j] == '+')
	{
		input->options[plus] = 1;
		(*j)++;
	}
	else
		return (0);
	return (1);
}

void	set_format(const char *format, t_input *input, int *j)
{
	int	i;

	i = 0;
	while (format[i] && ft_strchr(FLAGS, format[i]))
	{
		if (format[i] == '%')
		{
			input->options[modulo] = 1;
			*j = i + 1;
			return ;
		}
		else if (format[i] == '0')
		{
			input->options[zero] = 1;
			i++;
		}
		else if (set_otherflags(format, input, &i))
			;
		else
			return ;
	}
	*j = i;
}

void	get_width(const char *format, t_input *input, int *j)
{
	if (format[*j] && ft_isdigit(format[*j]))
	{
		input->options[width] = ft_atoi(&format[*j]);
		if (!input->options[width])
			(*j)++;
		(*j) += n_digits_bis(input->options[width], 10);
	}
}

void	getprec(const char *format, t_input *input, int *j)
{
	int	k;

	k = 0;
	if (format[*j] && format[*j] == '0' && (format[*j + 1]
			&& ft_isdigit(format[*j + 1])))
		k = 1;
	input->options[precision] = ft_atoi(&format[*j]);
	(*j) += (n_digits_bis(input->options[precision], 10) + k);
}

void	get_modulo_format(const char *format, t_input *input, int *j)
{
	if (format[*j] == '%')
	{
		input->options[modulo] = 1;
		(*j)++;
	}
	else if (ft_strchr(CONV, format[*j]))
		input->options[type] = format[(*j)++];
}
