/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:25:12 by dferrari          #+#    #+#             */
/*   Updated: 2023/11/24 02:13:28 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	args;
	int		size;

	i = 0;
	size = 0;
	va_start(args, str);
	while (str && str[i])
	{
		if (str[i] == '%')
		{
			while (str[i + 1] == ' ')
				i++;
			size += ft_targeting(&str[i + 1], args);
			i++;
		}
		else
			size += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (size);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("\n");
// 	printf("\nNombre de char : %d\n", ft_printf("%    d", -1));
// 	printf("\n");
// 	printf("%    d", -1);
// 	printf("\n");
// 	return (0);
// }
