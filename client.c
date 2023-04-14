/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:38:30 by rapelcha          #+#    #+#             */
/*   Updated: 2023/04/14 11:15:43 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_client_variable	*struc(void)
{
	static t_client_variable	data;

	return (&data);
}

static void	writer(int signal, siginfo_t *received, void *context)
{
	(void)context;
	(void)received;
	if (signal == SIGUSR1)
	{
		if (struc()->len >= 0
			&& struc()->message[struc()->index] & (1 << struc()->size_bin))
			kill(struc()->pid, SIGUSR1);
		else
			kill(struc()->pid, SIGUSR2);
		struc()->size_bin++;
		if (struc()->size_bin == BITE_SIZE)
		{
			struc()->size_bin = 0;
			struc()->len--;
			struc()->index++;
		}
	}
	else if (SIGUSR2)
	{
		ft_putendl_fd("Message recu dans sa totalité¡", 1);
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction			init;

	if (argc < 3)
	{
		ft_putendl_fd("3 arguments necessaire pour lancer le client¡", 1);
		return (0);
	}
	struc()->pid = ft_atoi(argv[1]);
	struc()->message = argv[2];
	struc()->len = ft_strlen(struc()->message);
	struc()->index = 0;
	struc()->size_bin = 0;
	init.sa_flags = SA_SIGINFO;
	init.sa_sigaction = writer;
	sigaction(SIGUSR1, &init, NULL);
	sigaction(SIGUSR2, &init, NULL);
	kill(getpid(), SIGUSR1);
	while (1)
		pause();
}
