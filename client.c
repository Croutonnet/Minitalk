/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:38:30 by rapelcha          #+#    #+#             */
/*   Updated: 2023/04/11 14:43:33 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	*return_struc(void *ptr)
{
	static void	*data = NULL;

	if (ptr)
		data = ptr;
	return (data);
}

static void	writer(int signal, siginfo_t *init, void *context)
{
	t_client_variable	*varia;
	int					size_bin;

	size_bin = 0;
	varia = return_struc(NULL);
	
}

int	main(int argc, char **argv)
{
	struct sigaction			init;
	static t_client_variable	varia;

	return_struc(&varia);
	if (argc < 3)
		return (0);
	varia.message = argv[2];
	varia.pid = argv[1];
	init.sa_flags = SA_SIGINFO;
	init.sa_sigaction = writer;
	sigaction(SIGUSR1, &init, NULL);
	sigaction(SIGUSR2, &init, NULL);
	/*
	while (argv[2][i])
	{
		if (c[i] & (1 << size_bin))
			kill(ft_atoi(argv[1]), SIGUSR1);
		else
			kill(ft_atoi(argv[1]), SIGUSR2);
		size_bin++;
		if (size_bin == BITE_SIZE)
		{
			i++;
			size_bin = 0;
		}
		usleep(120);
	}
	*/
}
