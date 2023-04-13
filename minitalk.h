/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:38:44 by rapelcha          #+#    #+#             */
/*   Updated: 2023/04/13 14:19:19 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "signal.h"
# include "unistd.h"
# include "stdio.h"
# include "Libft/libft.h"
# define BITE_SIZE 8

typedef struct s_client_variable
{
	char	*message;
	int		pid;
	int		index;
	int		len;
	int		size_bin;
}			t_client_variable;

typedef struct s_serv_variable
{
	char	*message;
	int		pid;
	int		client_pid;
}			t_serv_variable;

#endif