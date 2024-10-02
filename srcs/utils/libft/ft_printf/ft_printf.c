/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:43:29 by nbelkace          #+#    #+#             */
/*   Updated: 2024/03/12 13:15:29 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	is_type(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = len + ft_putchar(va_arg(args, int));
	else if (c == 's')
		len = len + ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		len = len + ft_printaddress_p(va_arg(args, unsigned long int));
	else if (c == 'd')
		len = len + ft_printnbr_d(va_arg(args, int));
	else if (c == 'i')
		len = len + ft_printnbr_i(va_arg(args, int));
	else if (c == 'u')
		len = len + ft_printnbr_u(va_arg(args, unsigned int));
	else if (c == 'x')
		len = len + ft_printnbr_x(va_arg(args, unsigned int));
	else if (c == 'X')
		len = len + ft_printnbr_uppercase_x(va_arg(args, unsigned int));
	else if (c == '%')
		len = len + ft_putchar('%');
	else
		return (-1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	int		len;
	int		temp;

	if (str == 0)
		return (-1);
	va_start(args, str);
	i = -1;
	len = 0;
	while (str[++i] != '\0')
	{
		temp = len;
		if (str[i] == '%')
		{
			i++;
			len = len + is_type(str[i], args);
			if (len == temp -1)
				return (0);
		}
		else
			len = len + ft_putchar(str[i]);
	}
	va_end(args);
	return (len);
}
