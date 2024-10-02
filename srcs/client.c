/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadjy <nadjy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 05:19:42 by nadjy             #+#    #+#             */
/*   Updated: 2024/10/02 17:47:44 by nadjy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

#include <signal.h>
#include <unistd.h>

#include <signal.h>
#include <unistd.h>

void	send_signals(int pid, char *message)
{
	int	letter;
	int	bit;

	letter = 0;
	while (message[letter] != '\0') 
	{
		bit = 7;
		while (bit >= 0)
		{
			if ((message[letter] >> bit) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(50);
			bit--;
		}
		letter++;
    }
	bit = 0;
	while (bit < 8) 
	{
		kill(pid, SIGUSR1);
		usleep(50);
		bit++;
	}
}

int	main(void)
{
	ft_printf("test");
}
