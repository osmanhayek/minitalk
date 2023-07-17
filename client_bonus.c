/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:25:27 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/17 12:10:25 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_putstrerr(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		write(2, &str[i++], 1);
	exit(0);
}

int	ft_check_arg(char *num)
{
	size_t	i;

	i = 0;
	while (num[i])
	{
		if (num[i] < '0' || num[i] > '9')
			return (0);
		i++;
	}
	if (!num[0] || ft_atoi(num) < 0 || num[0] == 48)
		return (0);
	return (1);
}

void	ft_send(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (1 & (c >> bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

void	ft_handler(int sig)
{
	if (sig == SIGUSR2)
		ft_putstrerr("The string received Thank you!\n");
}

int	main(int ac, char **av)
{
	int					pid;
	size_t				i;

	if (ac == 3)
	{
		if (!ft_check_arg(av[1]))
			ft_putstrerr("Invalid pid!");
		pid = ft_atoi(av[1]);
		i = 0;
		while (av[2][i])
			ft_send(pid, av[2][i++]);
		signal(SIGUSR2, ft_handler);
		ft_send(pid, '\0');
	}
	else
		ft_putstrerr("Invalid Input!");
}
