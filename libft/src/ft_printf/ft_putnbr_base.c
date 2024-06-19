/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 23:24:50 by razaccar          #+#    #+#             */
/*   Updated: 2024/05/28 02:01:08 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

/**
 * This function prints a number in the given base.
 *
 * @param nbr       The number to print.
 * @param base      The base to use.
 * @param is_upper  Whether to use uppercase letters for the base.
 * @return          The number of characters printed.
 */
static int	putnbr_base(unsigned long long nbr, unsigned int base, int is_upper)
{
	char	*symbols;
	int		len;

	if (is_upper == 0)
		symbols = "0123456789abcdef";
	else
		symbols = "0123456789ABCDEF";
	if (nbr < base)
		return (ft_putchar(symbols[nbr]));
	else
	{
		len = putnbr_base(nbr / base, base, is_upper);
		return (len + putnbr_base(nbr % base, base, is_upper));
	}
}

/**
 * This function prints a pointer in the given base.
 *
 * @param ptr       The pointer to print.
 * @param base      The base to use.
 * @param is_upper  Whether to use uppercase letters for the base.
 * @return          The number of characters printed.
 */
int	ft_putnbr_base_ptr(void *ptr, int base, int is_upper)
{
	int		len;

	len = ft_putstr("0x");
	if (ptr == NULL)
		return (len + write(1, "0", 1));
	return (len += putnbr_base((unsigned long long)ptr, base, is_upper));
}

/**
 * This function prints a number in the given base.
 *
 * @param nbr       The number to print.
 * @param base      The base to use.
 * @param is_upper  Whether to use uppercase letters for the base.
 * @return          The number of characters printed.
 */
int	ft_putnbr_base(long long nbr, int base, int is_upper)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		return (1 + putnbr_base(-nbr, base, is_upper));
	}
	return (putnbr_base(nbr, base, is_upper));
}
