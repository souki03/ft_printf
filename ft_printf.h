/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:24:37 by dferrari          #+#    #+#             */
/*   Updated: 2023/11/24 02:03:23 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_printf(const char *str, ...);
int				ft_targeting(const char *specifier, va_list args);
int				ft_strlen(char *str);
int				ft_putchar(char c);
int				ft_putstr(char *str);
int				ft_putnbr(long long int d);
int				ft_printp(void *addr);
int				ft_printunsigned(unsigned int n);
unsigned long	ft_printhex(long num, const char format);

#endif