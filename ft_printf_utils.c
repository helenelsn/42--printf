/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 06:30:38 by hlesny            #+#    #+#             */
/*   Updated: 2022/11/26 19:49:54 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a >= b)
		return (b);
	return (a);
}

int	n_digits(unsigned long long n, int base_size)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= base_size;
		i++;
	}
	return (i);
}

int	n_digits_bonus(unsigned long long n, int base_size)
{
	int	i;

	i = 0;
	while (n >= (unsigned long long)base_size)
	{
		n /= base_size;
		i++;
	}
	i++;
	return (i);
}

int	n_digits_bis(unsigned long long n, int base_size)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (n >= (unsigned long long)base_size)
	{
		n /= base_size;
		i++;
	}
	i++;
	return (i);
}
