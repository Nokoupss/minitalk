/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_address.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 17:31:54 by nbelkace          #+#    #+#             */
/*   Updated: 2024/01/31 11:48:53 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	nbrcase_address(unsigned long int nbr, char *base)
{
	int					len;
	unsigned long int	size;

	size = ft_strlen(base);
	len = 1;
	while (nbr > size - 1)
	{
		nbr = nbr / size;
		len++;
	}
	return (len);
}

char	*ft_itoa_base_address(unsigned long int nbr, char *base)
{
	unsigned long int					size;
	char								*n;
	int									lenres;

	size = ft_strlen(base);
	lenres = nbrcase_address(nbr, base);
	n = (char *)malloc((lenres + 1) * sizeof(char));
	if (n == NULL)
		return (NULL);
	n[lenres] = '\0';
	lenres--;
	while (nbr > size - 1)
	{
		n[lenres] = base[nbr % size];
		nbr = nbr / size;
		lenres--;
	}
	n[lenres] = base[nbr % size];
	return (n);
}
