/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 22:12:37 by razaccar          #+#    #+#             */
/*   Updated: 2024/05/28 02:01:10 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/**
 * This function prints a string to the standard output.
 *
 * @param str The string to print.
 * @return    The number of characters printed.
 */
int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}
