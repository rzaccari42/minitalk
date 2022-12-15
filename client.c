#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "./libft/libft.h"

int	main(int ac, char **av)
{
	int	i;
	int j;
	pid_t	pid;
	char	c;
	if (ac < 3)
		return (1);
		pid = atoi(av[1]);
	i = 0;
	while (av[2][i])
	{
		j = 0;
		c = av[2][i];
		while (j < 8)
		{
			if (c & (unsigned char)1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			++j;
			c >>= 1;
			usleep(200);
		}
		++i;
	}
	return (0);
}