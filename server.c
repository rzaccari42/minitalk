#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "./libft/libft.h"

int	displayPid()
{
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	return (1);
}

void	displayCharacter(int sig)
{
	if (sig == SIGUSR1)
		write(1, "0", 1);
	else
		write(1, "1", 1);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	displayPid();
	signal(SIGUSR1, displayCharacter);
	signal(SIGUSR2, displayCharacter);
	while (1)
		;
	return (1);
}
