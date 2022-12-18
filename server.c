/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 09:17:11 by rzaccari          #+#    #+#             */
/*   Updated: 2022/12/18 09:23:53 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "libft.h"

typedef struct s_msg
{
	char		*s;
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

char	*strdup_plus(char *s)
{
	char	*ret;
	int		i;

	ret = ft_calloc(ft_strlen(s) + 1001, sizeof(char));
	if (!ret)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	free(s);
	return (ret);
}

int	truc(t_msg *all)
{
	if (!all->s[all->j])
	{
		kill(all->pid, SIGUSR1);
		all->check_pid = 0;
		write(1, all->s, ft_strlen(all->s));
		free(all->s);
		all->s = NULL;
		all->j = 0;
		all->i = 0;
		return (1);
	}
	all->i = 0;
	++all->j;
	if (all->j >= (1000 * all->size) - 1)
	{
		all->size++;
		all->s = strdup_plus(all->s);
		if (!all->s)
			return (1);
	}
	all->s[all->j] = 0;
	return (0);
}

void	display_character(int sig)
{
	static t_msg	all;

	if (all.check_pid < 32)
	{
		all.pid = get_pid(sig, all.check_pid);
		all.check_pid++;
		return ;
	}
	if (!all.s)
	{
		all.s = ft_calloc(1001, sizeof(char));
		if (!all.s)
			return ;
	}
	all.s[all.j] <<= 1;
	if (sig == SIGUSR1)
		all.s[all.j] = all.s[all.j] | (unsigned char)1;
	if (all.i == 7)
	{
		if (truc(&all))
			return ;
	}
	else
		++all.i;
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, display_character);
	signal(SIGUSR2, display_character);
	while (1)
		;
	return (1);
}
