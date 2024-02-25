/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlence-l <nlence-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:57:41 by nlence-l          #+#    #+#             */
/*   Updated: 2024/02/25 16:30:22 by nlence-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	ft_atoi(char *str) {
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[0] == '-')
		sign = -1;
	if (str[i] >= '0' && str[i] <= '9') {
		while (str[i] <= '9' && str[i] >= '0') {
			res = res * 10 + str[i] - '0';
			i++;
		}
	}
	return (res * sign);
}

void ft_sender(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8) {
		if ((c & (0x01 << i)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(400);
		i++;
	}
}

void	ft_handler2(int pid)
{
	if (pid == SIGUSR1) {
		ft_printf("[+] Server: \033[32mMessage received\033[0m\n");
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	int	i;
	int	pid_server;

	i = 0;
	if (ac == 3) {	
		signal(SIGUSR1, ft_handler2);
		signal(SIGUSR2, ft_handler2);
		pid_server = ft_atoi(av[1]);
		while (av[2][i] != '\0') {
			ft_sender(pid_server, av[2][i]);
			i++;
		}
		ft_sender(pid_server, '\0');
		while (42)
			pause();
	}
	else {
		ft_printf("usage: ./client <server's pid> <string>\n");
		return (1);
	}
	return (0);
}
