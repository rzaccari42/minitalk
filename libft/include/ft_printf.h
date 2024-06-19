/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:15:16 by razaccar          #+#    #+#             */
/*   Updated: 2024/05/28 04:53:41 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

int	ft_printf(const char *str, ...);
int	ft_putchar(int c);
int	ft_putstr(char *str);
int	ft_putnbr_base(long long nbr, int base, int is_upper);
int	ft_putnbr_base_ptr(void *ptr, int base, int is_upper);

#endif