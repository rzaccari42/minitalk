/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 03:51:57 by razaccar          #+#    #+#             */
/*   Updated: 2024/05/28 03:26:06 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Duplicates a portion of a string.
 *
 * This function duplicates a portion of the given string, from the start 
 * index to the end index. The duplicated string is then returned.
 *
 * @param str The string to duplicate.
 * @param start The index to start the duplication from.
 * @param end The index to end the duplication at.
 * @return The duplicated string, or NULL if the start index is greater 
 * than the end index.
 */
char	*ft_strndup(char *str, size_t start, size_t end)
{
	char	*dup;
	int		i;

	i = 0;
	if (end < start || start < 0 || ft_strlen(str) <= start)
		return (NULL);
	if (end > ft_strlen(str))
		end = ft_strlen(str) - 1;
	dup = (char *)malloc((end - start + 2) * sizeof(char));
	if (!dup)
		return (NULL);
	while (start <= end)
		dup[i++] = str[start++];
	dup[i] = 0;
	return (dup);
}

/**
 * @brief Concatenates two strings into a new string.
 *
 * This function concatenates the two given strings into a new string, 
 * and returns it.
 *
 * @param str1 The first string to concatenate.
 * @param str2 The second string to concatenate.
 * @return The new string, or NULL if the allocation fails.
 */
char	*ft_strjoin_gnl(char *str1, char *str2)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(str1) + ft_strlen(str2) + 1;
	str = (char *)malloc(len);
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (str1)
		while (str1[j] != 0)
			str[i++] = str1[j++];
	j = 0;
	if (str2)
		while (str2[j] != 0)
			str[i++] = str2[j++];
	str[i] = 0;
	free(str1);
	return (str);
}
