/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:24:33 by nbelkace          #+#    #+#             */
/*   Updated: 2024/01/31 11:49:00 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	nbrcase(long int nbr, char *base)
{
	int	len;
	int	size;

	size = ft_strlen(base);
	len = 1;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		len++;
	}
	while (nbr > size - 1)
	{
		nbr = nbr / size;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(long int nbr, char *base)
{
	long int		i;
	int				size;
	char			*n;
	int				lenres;

	i = nbr;
	size = ft_strlen(base);
	lenres = nbrcase(nbr, base);
	n = (char *)malloc((lenres + 1) * sizeof(char));
	if (n == NULL)
		return (NULL);
	n[lenres] = '\0';
	lenres--;
	if (i < 0)
	{
		i = i * -1;
		n[0] = '-';
	}
	while (i > size - 1)
	{
		n[lenres--] = base[i % size];
		i = i / size;
	}
	n[lenres] = base[i % size];
	return (n);
}
