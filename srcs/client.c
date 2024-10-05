/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 05:19:42 by nadjy             #+#    #+#             */
/*   Updated: 2024/10/05 06:22:47 by nbelkace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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
			usleep(100);
			bit--;
		}
		letter++;
    }
	bit = 0;
	while (bit < 8) 
	{
		kill(pid, SIGUSR1);
		usleep(100);
		bit++;
	}
}

void	acknowledgment_handler(int signum)
{
	(void)signum;
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Error, wrong arguments, please enter as follow : ./client <PID> <MESSAGE>");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid == 0)
	{
		ft_printf("Error, No server PID found");
		return (1);
	}
	message = argv[2];
	if (message[0] == '\0')
	{
		ft_printf("Error, No message found");
		return (1);
	}
	signal(SIGUSR1, acknowledgment_handler);
	send_signals(pid, message);
	return (0);
}
