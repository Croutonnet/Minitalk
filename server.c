/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:38:32 by rapelcha          #+#    #+#             */
/*   Updated: 2023/04/14 12:11:53 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	initialization(int *size_bin, int *c, int *pid)
{
	*size_bin = 0;
	*c = 0;
	*pid = 0;
}

static t_serv_variable	*struc(void)
{
	static t_serv_variable	data;

	return (&data);
}

static char	*char_join(char *str, char c)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_calloc((ft_strlen(str) + 2), sizeof(char));
	if (str)
	{
		while (str[i])
		{
			res[i] = str[i];
			i++;
		}
	}
	res[i] = c;
	ft_xfree(str);
	return (res);
}

static void	received(int signal, siginfo_t *received, void *context)
{
	static int		temp;
	static int		size_bin;

	(void)context;
	if (received->si_pid != struc()->client_pid && received->si_pid != 0)
		initialization(&size_bin, &temp, &struc()->client_pid);
	if (struc()->client_pid == 0)
		struc()->client_pid = received->si_pid;
	if (signal == SIGUSR1)
		temp |= (1 << size_bin);
	size_bin++;
	if (size_bin == BITE_SIZE)
	{
		if (temp == '\0')
		{
			ft_putendl_fd(struc()->message, 1);
			struc()->message = ft_xfree(struc()->message);
			kill(struc()->client_pid, SIGUSR2);
		}
		else
			(struc()->message) = char_join((struc()->message), temp);
		temp = 0;
		size_bin = 0;
	}
	kill(struc()->client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction		rcv;

	struc()->pid = getpid();
	ft_putnbr_fd(struc()->pid, 1);
	ft_putchar_fd('\n', 1);
	rcv.sa_flags = SA_SIGINFO;
	rcv.sa_sigaction = received;
	sigaction(SIGUSR1, &rcv, NULL);
	sigaction(SIGUSR2, &rcv, NULL);
	while (1)
		pause();
}
