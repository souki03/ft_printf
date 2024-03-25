/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:35:51 by dferrari          #+#    #+#             */
/*   Updated: 2023/11/24 02:16:59 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_size(unsigned long num)
{
	int	size;

	size = 0;
	while (num != 0)
	{
		size++;
		num = num / 16;
	}
	return (size);
}

void	ft_put_hex(unsigned long num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
		{
			if (format == 'x')
				ft_putchar(num - 10 + 'a');
			if (format == 'X')
				ft_putchar(num - 10 + 'A');
		}
	}
}

unsigned long	ft_printhex(long num, const char format)
{
	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	if (num == 0)
	{
		ft_putchar('0');
		return (1);
	}
	else
	{
		ft_put_hex(num, format);
		return (ft_hex_size(num));
	}
}
