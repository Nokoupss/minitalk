/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:20:07 by nbelkace          #+#    #+#             */
/*   Updated: 2024/01/31 11:49:07 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printnbr_d(int n)
{
	char	*str;
	int		len;

	str = ft_itoa_base(n, "0123456789");
	if (str == NULL)
		return (-1);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}

int	ft_printnbr_i(int n)
{
	char	*str;
	int		len;

	str = ft_itoa_base(n, "0123456789");
	if (str == NULL)
		return (-1);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}

int	ft_printnbr_u(unsigned int n)
{
	char	*str;
	int		len;

	str = ft_itoa_base(n, "0123456789");
	if (str == NULL)
		return (-1);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}

int	ft_printnbr_x(unsigned int n)
{
	char	*str;
	int		len;

	str = ft_itoa_base(n, "0123456789abcdef");
	if (str == NULL)
		return (-1);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}

int	ft_printnbr_uppercase_x(unsigned int n)
{
	char	*str;
	int		len;

	str = ft_itoa_base(n, "0123456789ABCDEF");
	if (str == NULL)
		return (-1);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}
