/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:01:16 by razaccar          #+#    #+#             */
/*   Updated: 2024/06/18 16:01:23 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/include/libft.h"

void	ft_handler(int signal)
{
	static int	bit;
	static int	byte;

	if (signal == SIGUSR1)
		byte |= (0b00000001 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", byte);
		bit = 0;
		byte = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error: wrong format.\n");
		return (0);
	}
	pid = getpid();
	ft_printf("PID : %i\n", pid);
	ft_printf("Waiting for a message...\n");
	while (argc == 1)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pause ();
	}
	return (0);
}
