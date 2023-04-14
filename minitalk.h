/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapelcha <rapelcha@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:38:44 by rapelcha          #+#    #+#             */
/*   Updated: 2023/04/14 12:41:52 by rapelcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
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

void	ft_bzero(void *s, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	*ft_xfree(void	*pointer);
void	*ft_calloc(size_t count, size_t size);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);

#endif