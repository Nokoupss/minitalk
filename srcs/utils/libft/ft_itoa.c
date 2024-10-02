/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:12:45 by nbelkace          #+#    #+#             */
/*   Updated: 2023/11/16 15:54:02 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lenint(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

char	*ft_itoa(int n)
{
	int			len;
	long int	nb;
	char		*result;

	nb = n;
	len = lenint(nb);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (nb < 0)
	{
		result[0] = '-';
		nb = -nb;
	}
	result[len] = '\0';
	len--;
	while (nb > 9)
	{
		result[len] = (nb % 10) + 48;
		nb = nb / 10;
		len--;
	}
	result[len] = nb % 10 + 48;
	return (result);
}
