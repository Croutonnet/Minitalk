/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:38:32 by rapelcha          #+#    #+#             */
/*   Updated: 2023/04/11 14:51:06 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	initialization(int *size_bin, int *c, int *pid)
{
	*size_bin = 0;
	*c = 0;
	*pid = 0;
}

static void	*return_struc(void *ptr)
{
	static void	*data = NULL;

	if (ptr)
		data = ptr;
	return (data);
}

static char	*char_join(char *str, char c)
{
	int		i;
	char	*res;

	i = 0;
	if (!str)
	{
		str = ft_calloc(1, sizeof(char));
		*str = c;
		return (str);
	}
	res = ft_strdup(str);
	while (res[i])
		i++;
	res[i] = c;
	return (res);
}

static void	received(int signal, siginfo_t *received, void *context)
{
	static int		temp;
	static int		size_bin;
	static int		pid;
	t_serv_variable	*vari;

	(void)context;
	vari = return_struc(NULL);
	if (received->si_pid != pid)
		initialization(&size_bin, &temp, &pid);
	if (pid == 0)
		pid = received->si_pid;
	if (signal == SIGUSR1)
		temp |= (1 << size_bin);
	size_bin++;
	if (temp == '\0')
		printf("Message: %s\n", vari->message);
	if (size_bin == BITE_SIZE)
	{
		vari->message = char_join(vari->message, temp);
		temp = 0;
		size_bin = 0;
	}
}

int	main(void)
{
	struct sigaction		rcv;
	static t_serv_variable	varia;
	pid_t					pid;

	return_struc(&varia);
	varia.pid = getpid();
	printf("%d\n", pid);
	rcv.sa_flags = SA_SIGINFO;
	rcv.sa_sigaction = received;
	sigaction(SIGUSR1, &rcv, NULL);
	sigaction(SIGUSR2, &rcv, NULL);
	while (1)
		continue ;
}
