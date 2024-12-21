/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihancer <ihancer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:12:36 by ihancer           #+#    #+#             */
/*   Updated: 2024/11/01 16:33:31 by ihancer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_putnbr(long n, int base, char spcf)
{
	int		count;
	char	*value;

	count = 0;
	if (spcf == 'X')
		value = "0123456789ABCDEF";
	else
		value = "0123456789abcdef";
	if (n < 0)
	{
		ft_putchar('-');
		count = count + ft_putnbr(-n, base, spcf) + 1;
	}
	else if (n < base)
		count = count + ft_putchar(value[n]);
	else
	{
		count = count + ft_putnbr(n / base, base, spcf);
		count = count + ft_putnbr(n % base, base, spcf);
	}
	return (count);
}

int	ft_ptrnbr(size_t n, size_t base, char spcf)
{
	size_t		count;
	char		*value;

	ft_putstr("0x");
	count = 2;
	value = "0123456789abcdef";
	if (n < base)
		count = count + ft_putchar(value[n]);
	else
	{
		count = count + ft_putnbr(n / base, base, spcf);
		count = count + ft_putnbr(n % base, base, spcf);
	}
	return (count);
}
