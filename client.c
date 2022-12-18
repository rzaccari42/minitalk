#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "./libft/libft.h"

void	send_pid(pid_t server_pid)
{
	int		i;
	pid_t	pid;

	pid = getpid();
	i = 32;
	while (i)
	{
		--i;
		//printf("%d\n", i);
		if (pid & ((unsigned int)1 << i))
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(200);	
	}
}

void	check_ok(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Message transmis\n", 17);
}

void	send_eol(pid_t pid)
{
	int	i;

	i = 8;
	while (i)
	{
		--i;
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int		i;
	int 	j;
	pid_t	pid;
	char	c;

	if (ac < 3)
		return (1);
	signal(SIGUSR1, check_ok);
	signal(SIGUSR2, check_ok);
	pid = ft_atoi(av[1]);
	send_pid(pid);
	i = 0;
	while (av[2][i])
	{
		j = 8;
		c = av[2][i];
		while (j)
		{
			--j;
			if (c & ((unsigned char)1 << j))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			
		}
		++i;
	}
	send_eol(pid);
	usleep(100);
	return (0);
}