/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:56:47 by nbelkace          #+#    #+#             */
/*   Updated: 2023/11/21 19:05:00 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	while (len > 0 && s[len] != (unsigned char)c)
		len--;
	if (s[len] == (unsigned char)c)
		return ((char *)&s[len]);
	return (NULL);
}
