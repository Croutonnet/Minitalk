/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:38:30 by rapelcha          #+#    #+#             */
/*   Updated: 2023/04/10 12:41:02 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	int		size_bin;
	int		i;
	char	*c;

	size_bin = 0;
	i = 0;
	if (argc < 3)
		return (0);
	c = argv[2];
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
}

// 01100001