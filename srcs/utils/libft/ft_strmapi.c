/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:13:52 by nbelkace          #+#    #+#             */
/*   Updated: 2023/11/16 15:53:04 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		index;
	char	*result;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	index = 0;
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (len > index)
	{
		result[index] = s[index];
		result[index] = (*f)(index, result[index]);
		index++;
	}
	result[index] = '\0';
	return (result);
}
