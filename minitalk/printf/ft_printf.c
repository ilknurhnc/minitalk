/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihancer <ihancer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:09:28 by ihancer           #+#    #+#             */
/*   Updated: 2024/11/02 21:50:36 by ihancer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_spcf(char str, va_list args)
{
	unsigned int	counter;

	counter = 0;
	if (str == 'c')
		counter = counter + ft_putchar(va_arg(args, int));
	else if (str == 's')
		counter = counter + ft_putstr(va_arg(args, char *));
	else if (str == 'd' || str == 'i')
		counter = counter + ft_putnbr(va_arg(args, int), 10, str);
	else if (str == 'u')
		counter = counter + ft_putnbr(va_arg(args, unsigned int), 10, str);
	else if (str == 'X')
		counter = counter + ft_putnbr(va_arg(args, unsigned int), 16, str);
	else if (str == 'x')
		counter = counter + ft_putnbr(va_arg(args, unsigned int), 16, str);
	else if (str == 'p')
		counter = counter + ft_ptrnbr(va_arg(args, size_t), 16, str);
	else if (str == '%')
		counter = counter + ft_putchar('%');
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list			args;
	unsigned int	counter;

	va_start(args, str);
	counter = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			counter = counter + ft_spcf((*str), args);
		}
		else
		{
			counter = counter + ft_putchar(*str);
		}
		str++;
	}
	va_end(args);
	return (counter);
}
