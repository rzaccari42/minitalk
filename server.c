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
	int	i;

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

void	displayCharacter(int sig)
{
	static char			*s;
	static int			i;
	static int			j;
	static int			size;
	static pid_t		pid;
	static int			check_pid;

	if (check_pid < 32)
	{
		pid = get_pid(sig, check_pid);
		++check_pid;
		return ;
	}
	if (!s)
	{
		s = ft_calloc(1001, sizeof(char));
		if (!s)
			return ;
	}
	s[j] <<= 1;
	if (sig == SIGUSR1)
		s[j] = s[j] | (unsigned char)1;
	if (i == 7)
	{
		if (!s[j])
		{
			kill(pid, SIGUSR1);
			check_pid = 0;
			write(1, s, ft_strlen(s));
			free(s);
			s = NULL;
			j = 0;
			i = 0;
			return ;
		}
		i = 0;
		++j;
		if (j >= (1000 * size) - 1)
		{
			size++;
			s = strdup_plus(s);
			if (!s)
				return ;
		}
		s[j] = 0;
	}
	else
		++i;
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
