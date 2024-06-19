/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 00:10:43 by razaccar          #+#    #+#             */
/*   Updated: 2024/05/28 04:53:31 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "libft.h"

char	*get_next_line(int fd);
char	*ft_strndup(char *str, size_t start, size_t end);
char	*ft_strjoin_gnl(char *s1, char *s2);

#endif