/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:31:51 by dferrari          #+#    #+#             */
/*   Updated: 2023/11/24 02:16:37 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_size(unsigned int num)
{
	int	size;

	size = 0;
	while (num != 0)
	{
		size++;
		num = num / 10;
	}
	return (size);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		size;

	size = ft_num_size(n);
	num = (char *)malloc(sizeof(char) * (size + 1));
	if (!num)
		return (0);
	num[size] = '\0';
	while (n != 0)
	{
		num[size - 1] = n % 10 + 48;
		n = n / 10;
		size--;
	}
	return (num);
}

int	ft_printunsigned(unsigned int n)
{
	int		size;
	char	*num;

	size = 0;
	if (n == 0)
		size += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		if (!num)
			return (0);
		size += ft_putstr(num);
		free(num);
	}
	return (size);
}
