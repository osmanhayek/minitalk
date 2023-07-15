/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohayek <ohayek@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 16:25:27 by ohayek            #+#    #+#             */
/*   Updated: 2023/07/15 23:20:06 by ohayek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int	ft_atoi(const char *nptr)
{
	long	result;
	int		a;

	while (*nptr == '\n' || *nptr == '\t' || *nptr == '\r' \
	|| *nptr == '\v' || *nptr == '\f' || *nptr == ' ')
		nptr++;
	a = *nptr == '-';
	nptr += (a || *nptr == '+');
	result = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = (result * 10) + *nptr++ - '0';
		if (result > 2147483647 && a == 0)
			return (-1);
		if (result > 2147483648U && a == 1)
			return (0);
	}
	return (result * ((a * -2) + 1));
}

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

void    ft_handler(int sgm)
{
    if (sgm == SIGUSR2)
        write(1, "Thank You!\n", 11);
	exit(0);
}
int	main(int ac, char **av)
{
	int		pid;
	size_t	i;

	if (ac == 3)
	{
		if (!ft_check_arg(av[1]))
			ft_putstrerr("Invalid pid!");
		pid = ft_atoi(av[1]);
		i = 0;
		while (av[2][i])
			ft_send(pid, av[2][i++]);
		ft_send(pid, '\0');
		signal(SIGUSR2, ft_handler);
	}
	else
		ft_putstrerr("Invalid Input!");
}
