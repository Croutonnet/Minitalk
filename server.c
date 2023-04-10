/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:38:32 by rapelcha          #+#    #+#             */
/*   Updated: 2023/04/10 13:25:19 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	initialization(int *size_bin, int *c, int *pid)
{
	*size_bin = 0;
	*c = 0;
	*pid = 0;
}

static char	*char_join(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
	{
		str = malloc (1 * sizeof(char));
		*str = c;
		return (str);
	}
	while (str[i])
		i++;
	i++;
	str = malloc((ft_strlen(str) + 1) * sizeof(char));
	str[i] = c;
	return (str);
}

static void	received(int signal, siginfo_t *received, void *context)
{
	static int	temp;
	static int	size_bin;
	static int	pid;
	static char	*message;

	(void)context;
	if (received->si_pid != pid)
		initialization(&size_bin, &temp, &pid);
	if (pid == 0)
		pid = received->si_pid;
	if (size_bin < BITE_SIZE)
	{
		if (signal == SIGUSR1)
		{
			temp |= (1 << size_bin);
		}
		size_bin++;
	}
	else
	{
		printf("Char received\n");
		message = char_join(message, temp);
		temp = 0;
		size_bin = 0;
	}
	printf("Message: %s\n", message);
}

int	main(void)
{
	struct sigaction	rcv;
	pid_t				pid;

	pid = getpid();
	printf("%d\n", pid);
	rcv.sa_flags = SA_SIGINFO;
	rcv.sa_sigaction = received;
	sigaction(SIGUSR1, &rcv, NULL);
	sigaction(SIGUSR2, &rcv, NULL);
	while (1)
		continue ;
}
