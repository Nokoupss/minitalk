/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:25:40 by nbelkace          #+#    #+#             */
/*   Updated: 2024/01/31 11:22:27 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mal;

	if (size > 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	mal = (void *)malloc(nmemb * size);
	if (mal == NULL)
		return (NULL);
	ft_bzero(mal, nmemb * size);
	return (mal);
}
