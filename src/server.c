/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlence-l <nlence-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:57:48 by nlence-l          #+#    #+#             */
/*   Updated: 2024/02/25 13:52:48 by nlence-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

char	*add_c_to_str(char *str, char c)
{
	char	*new;
	int		i;

	i = 0;
	if (!str)
	{
		new = (char *)malloc(sizeof(char) * 2);
		if (!new)
			return (NULL);
		new[0] = c;
		new[1] = '\0';
		return (new);
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!new)
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i++] = c;
	new[i] = '\0';
	free(str);
	return (new);
}

char	*print_and_free(char *str)
{
	if (str)
		ft_printf("%s\n", str);
	free(str);
	return (NULL);
}

void	ft_handler(int signal, siginfo_t *info, void *s)
{
	static int	i;
	static char	c;
	static char	*str = NULL;

	(void)s;
	if (signal == SIGUSR1)
		c = c | (0x01 << i);
	i++;
	if (i == 8)
	{
		if (c == '\0')
		{
			str = print_and_free(str);
			kill(info->si_pid, SIGUSR1);
		}
		else
		{
			str = add_c_to_str(str, c);
		}
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("PID: \033[33m%d\033[0m\n", getpid());
	sa.sa_sigaction = ft_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (42)
		pause();
	return (0);
}
