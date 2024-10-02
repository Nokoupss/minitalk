/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:04:08 by nbelkace          #+#    #+#             */
/*   Updated: 2024/01/31 11:43:26 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len;
	char	*str;

	start = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1) - 1;
	while (is_charset(s1[start], set) == 1)
		start++;
	while (is_charset(s1[len], set) == 1)
		len--;
	len = len - start + 1;
	str = ft_substr(s1, start, len);
	return (str);
}
