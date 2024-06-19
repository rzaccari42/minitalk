/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:55:01 by razaccar          #+#    #+#             */
/*   Updated: 2024/05/28 02:01:06 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/**
 * This function takes a variable argument list and a format specifier and
 * prints the corresponding argument based on the format specifier.
 *
 * @param args   The variable argument list.
 * @param format The format specifier.
 * @return       The number of characters printed.
 */
static int	ft_putarg(va_list *args, char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (format == 'p')
		return (ft_putnbr_base_ptr(va_arg(*args, void *), 16, 0));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_base(va_arg(*args, int), 10, 0));
	else if (format == 'u')
		return (ft_putnbr_base(va_arg(*args, unsigned int), 10, 0));
	else if (format == 'x')
		return (ft_putnbr_base(va_arg(*args, unsigned int), 16, 0));
	else if (format == 'X')
		return (ft_putnbr_base(va_arg(*args, unsigned int), 16, 1));
	else if (format == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

/**
 * This function takes a string and a variable number of arguments and prints
 * the string with the corresponding arguments.
 *
 * @param str  The string to print.
 * @param ...  The variable number of arguments.
 * @return     The number of characters printed.
 */
int	ft_printf(const char *str, ...)
{
	va_list	args;	
	int		len;	

	va_start(args, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
			len += ft_putarg(&args, *(++str));
		else
			len += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (len);
}
