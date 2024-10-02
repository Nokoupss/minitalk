/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:13:17 by nbelkace          #+#    #+#             */
/*   Updated: 2023/11/21 19:12:07 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*strdest;
	unsigned char	*strsrc;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	strdest = (unsigned char *)dest;
	strsrc = (unsigned char *)src;
	while (i < n)
	{
		strdest[i] = strsrc[i];
		i++;
	}
	return (dest);
}
