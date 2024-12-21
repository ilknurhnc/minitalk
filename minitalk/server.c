/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihancer <ihancer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:44:03 by ihancer           #+#    #+#             */
/*   Updated: 2024/12/06 16:42:45 by ihancer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		ft_printf(const char *str, ...);

void	collect_bit(int signal)
{
	static int	bit;
	static int	count_bit;

	if (signal == SIGUSR1)
		bit |= (1 << count_bit);
	count_bit++;
	if (count_bit == 8)
	{
		ft_printf("%c", bit);
		bit = 0;
		count_bit = 0;
	}
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, collect_bit);
	signal(SIGUSR2, collect_bit);
	while (1)
		pause();
}
