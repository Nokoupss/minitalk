/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:44:55 by nbelkace          #+#    #+#             */
/*   Updated: 2024/01/31 11:28:58 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	n;
	char	*mal;
	int		i;

	n = 0;
	i = 0;
	while (s[n] != '\0')
		n++;
	mal = (char *)malloc((n + 1) * sizeof(char));
	if (mal == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		mal[i] = s[i];
		i++;
	}
	mal[i] = '\0';
	return (mal);
}
