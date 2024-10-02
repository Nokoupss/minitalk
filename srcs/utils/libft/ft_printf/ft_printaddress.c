/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:11:59 by nbelkace          #+#    #+#             */
/*   Updated: 2024/01/31 11:48:57 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printaddress_p(unsigned long int p)
{
	char	*str;
	int		len;

	if (p == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	str = ft_itoa_base_address(p, "0123456789abcdef");
	if (str == NULL)
		return (-1);
	len = ft_strlen(str) + 2;
	ft_putstr(str);
	free(str);
	return (len);
}
