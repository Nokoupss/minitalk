/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:36:46 by nbelkace          #+#    #+#             */
/*   Updated: 2023/11/23 15:04:33 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*strdest;
	unsigned char	*strsrc;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	strdest = (unsigned char *)dest;
	strsrc = (unsigned char *)src;
	if (strdest > strsrc)
	{
		while (i < n--)
			strdest[n] = strsrc[n];
	}
	else
	{
		while (i < n)
		{
			strdest[i] = strsrc[i];
			i++;
		}
	}
	return (dest);
}
