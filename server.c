/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:33:45 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/17 11:12:47 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static inline
void	ft_putnbr(int nbr)
{
	char	str[16];
	size_t	i;
	long	num;

	num = nbr;
	if (!num)
	{
		write(1, "0", 1);
		return ;
	}
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	i = 0;
	while (num)
	{
		str[i++] = num % 10 + 48;
		num = num / 10;
	}
	while (i--)
		write(1, &str[i], 1);
}

static inline
void	ft_handler(int sgn)
{
	static char				bit = 0;
	static unsigned char	i = 0;

	if (sgn == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		i = 0;
		bit = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause();
	}
}
