/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 09:17:11 by rzaccari          #+#    #+#             */
/*   Updated: 2022/12/23 17:41:36 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "libft.h"

typedef struct s_msg
{
	char		*str;
	int			i;
	int			j;
	int			size;
	pid_t		pid;
	int			check_pid;
}	t_msg;

pid_t	get_pid(int sig, int check_pid)
{
	static pid_t	pid;
	static int		i;

	if (!check_pid)
		pid = 0;
	pid <<= 1U;
	if (sig == SIGUSR1)
	{
		pid = pid | (unsigned int)1;
	}
	++i;
	return (pid);
}

char	*strdup_plus(char *str)
{
	char	*ret;
	int		i;

	ret = ft_calloc(ft_strlen(str) + 1001, sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	free(str);
	return (ret);
}

int	display_message(t_msg *message)
{
	if (!message->str[message->j])
	{
		kill(message->pid, SIGUSR1);
		message->check_pid = 0;
		write(1, message->str, ft_strlen(message->str));
		write(1, "\n", 1);
		free(message->str);
		message->str = NULL;
		message->j = 0;
		message->i = 0;
		return (1);
	}
	message->i = 0;
	++message->j;
	if (message->j >= (1000 * message->size) - 1)
	{
		message->size++;
		message->str = strdup_plus(message->str);
		if (!message->str)
			return (1);
	}
	message->str[message->j] = 0;
	return (0);
}

void	make_message(int sig)
{
	static t_msg	message;

	if (message.check_pid < 32)
	{
		message.pid = get_pid(sig, message.check_pid);
		message.check_pid++;
		return ;
	}
	if (!message.str)
	{
		message.str = ft_calloc(1001, sizeof(char));
		if (!message.str)
			return ;
	}
	message.str[message.j] <<= 1;
	if (sig == SIGUSR1)
		message.str[message.j] = message.str[message.j] | (unsigned char)1;
	if (message.i == 7)
	{
		if (display_message(&message))
			return ;
	}
	else
		++message.i;
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, make_message);
	signal(SIGUSR2, make_message);
	while (1)
		;
	return (1);
}
