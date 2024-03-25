/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_targeting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:44:36 by dferrari          #+#    #+#             */
/*   Updated: 2023/11/24 02:15:51 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int static	ft_targeting_s(va_list args)
{
	char	*s;
	int		size;

	size = 0;
	s = va_arg(args, char *);
	if (s == NULL)
		size += ft_putstr("(null)");
	else
		size += ft_putstr(s);
	return (size);
}

int	ft_targeting(const char *specifier, va_list args)
{
	int	size;

	size = 0;
	if (*specifier == 'c')
		size += ft_putchar(va_arg(args, int));
	else if (*specifier == 's')
		size += ft_targeting_s(args);
	else if (*specifier == 'd' || *specifier == 'i')
		size += ft_putnbr(va_arg(args, int));
	else if (*specifier == 'p')
		size += ft_printp(va_arg(args, void *));
	else if (*specifier == 'u')
		size += ft_printunsigned(va_arg(args, unsigned int));
	else if (*specifier == 'x' || *specifier == 'X')
		size += ft_printhex(va_arg(args, unsigned int), *specifier);
	else if (*specifier == '%')
		size += ft_putchar('%');
	return (size);
}
