/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:09:54 by razaccar          #+#    #+#             */
/*   Updated: 2024/05/28 02:01:07 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/**
 * This function prints a character to the standard output.
 *
 * @param c The character to print.
 * @return  The number of characters printed.
 */
int	ft_putchar(int c)
{
	return (write(1, &c, 1));
}
