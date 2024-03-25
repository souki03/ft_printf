/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 05:14:35 by dferrari          #+#    #+#             */
/*   Updated: 2023/11/24 05:16:32 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(long long int d)
{
	int	size;

	size = 0;
	if (d < 0)
	{
		d = -d;
		size += ft_putchar('-');
	}
	if (d >= 10)
	{
		size += ft_putnbr(d / 10);
		size += ft_putnbr(d % 10);
	}
	else
		size += ft_putchar(d + '0');
	return (size);
}
